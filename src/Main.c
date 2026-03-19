#include "/home/codeleaded/System/Static/Library/KNN.h"

#define KNN_CENTER_PATH     "./data/Output." KNN_CENTER_FILETYPE
#define KNN_DATA_PATH       "./data/Output." KNN_DATA_FILETYPE
#define KNN_LEARNRATE       0.5f

int main(int argc,char** argv){
    
    KNN knn = KNN_New(4U,2U,3U);
    KNN_Add_Data(&knn,(NeuralType*[]){
        (NeuralType[]){ 0.0f,0.0f },
        (NeuralType[]){ 0.0f,0.0f },
        (NeuralType[]){ 0.0f,0.0f },
        (NeuralType[]){ 0.0f,0.0f },
        (NeuralType[]){ 0.0f,0.0f },
        (NeuralType[]){ 0.0f,0.0f },
        (NeuralType[]){ 0.0f,0.0f },
        (NeuralType[]){ 0.0f,0.0f },
        NULL
    });
    KNN_Load_Data(&knn,KNN_DATA_PATH);
    
    KNN_Relocate(&knn,KNN_LEARNRATE);
    int c = KNN_Centerize(&knn,(NeuralType[]){ 0.0f,0.0f });
    printf("Center: %d\n",c);

    //KNN_Save(&knn,KNN_CENTER_PATH);
    //KNN_Load(&knn,KNN_CENTER_PATH);
    
    KNN_Free(&knn);
    return 0;
}