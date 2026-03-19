#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/KNN.h"

#define KNN_CENTER_PATH     "./data/Output." KNN_CENTER_FILETYPE
#define KNN_DATA_PATH       "./data/Output." KNN_DATA_FILETYPE
#define KNN_LEARNRATE       0.5f
#define KNN_RADIUS          0.01f
#define KNN_STARTPOINTS     50

TransformedView tv;
KNN knn;

void Setup(AlxWindow* w){
    RGA_Set(Time_Nano());

	tv = TransformedView_New((Vec2){ GetWidth(),GetHeight() });
	knn = KNN_New(8U,2U,3U);

    for(int i = 0;i<KNN_STARTPOINTS;i++){
        KNN_Add_Data(&knn,(NeuralType*[]){
            (NeuralType[]){ Random_f64_New(),Random_f64_New() },
            NULL
        });
    }
    //KNN_Load_Data(&knn,KNN_DATA_PATH);
    //KNN_Save(&knn,KNN_CENTER_PATH);
    //KNN_Load(&knn,KNN_CENTER_PATH);
    
}
void Update(AlxWindow* w){
    tv.ZoomSpeed = 1.0f * w->ElapsedTime;
	TransformedView_HandlePanZoom(&tv,window.Strokes,GetMouse());
    Vec2 const mp = TransformedView_ScreenWorldPos(&tv,GetMouse());

    if(Stroke(ALX_KEY_W).PRESSED){
        KNN_Relocate(&knn,KNN_LEARNRATE);
    }
    
    if(Stroke(ALX_MOUSE_L).PRESSED){
        KNN_Add_Data(&knn,(NeuralType*[]){
            (NeuralType[]){ mp.x,mp.y },
            NULL
        });
    }
    if(Stroke(ALX_MOUSE_R).PRESSED){
        for(int i = 0;i<knn.dps.size;i++){
            NeuralType* nt = *(NeuralType**)Vector_Get(&knn.dps,i);
            const Vec2 d = Vec2_Sub(mp,(Vec2){ nt[0],nt[1] });
            const float d2 = Vec2_Mag2(d);
            
            if(d2 < KNN_RADIUS * KNN_RADIUS){
                free(nt);
                Vector_Remove(&knn.dps,i);
                break;
            }
        }
    }

	Clear(BLACK);

	Vec2 const sp = TransformedView_WorldScreenPos(&tv,(Vec2){ 0.0f,0.0f });
	Vec2 const sd = TransformedView_WorldScreenLength(&tv,(Vec2){ 1.0f,1.0f });
	Rect_RenderXWire(WINDOW_STD_ARGS,sp,sd,WHITE,1.0f);

	Vec2 const ntd = TransformedView_WorldScreenLength(&tv,(Vec2){ KNN_RADIUS,KNN_RADIUS });
    for(int i = 0;i<knn.dps.size;i++){
        NeuralType* nt = *(NeuralType**)Vector_Get(&knn.dps,i);
        const int c = KNN_Centerize(&knn,nt);
        Pixel color = WHITE;
        if(c == 0)      color = RED;
        else if(c == 1) color = GREEN;
        else if(c == 2) color = YELLOW;
        
        Vec2 const ntp = TransformedView_WorldScreenPos(&tv,(Vec2){ nt[0],nt[1] });
        Circle_R_RenderWire(WINDOW_STD_ARGS,ntp,ntd,color,1.0f);
    }

    for(int i = 0;i<knn.outs;i++){
        NeuralType* nt = knn.cts[i];
        Vec2 const ntp = TransformedView_WorldScreenPos(&tv,(Vec2){ nt[0],nt[1] });
        Circle_R_RenderWire(WINDOW_STD_ARGS,ntp,ntd,BLUE,1.0f);
    }
}
void Delete(AlxWindow* w){
    KNN_Free(&knn);
}

int main(){
    if(Create("KNN",1900,1100,1,1,Setup,Update,Delete))
        Start();
    return 0;
}