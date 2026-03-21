# Gui_KMeans


## Overview
Interactive K-Means clustering visualization tool with real-time graphical feedback. Implements the K-Means unsupervised machine learning algorithm for partitioning data points into clusters.

## Core Algorithm

### K-Means Clustering
- Unsupervised learning algorithm
- Partitions data into K clusters
- Minimizes variance within clusters
- Requires no labeled training data

### Algorithm Steps
1. **Initialization**: Place K cluster centers (centroids) randomly
2. **Assignment**: Assign each point to nearest cluster center (Euclidean distance)
3. **Update**: Recalculate cluster centers as mean of assigned points
4. **Convergence**: Repeat until centers stabilize

### Interactive Features
- **Left-Click**: Add new data points
- **Right-Click**: Remove data points
- **W Key**: Execute one K-Means iteration
- **Pan/Zoom**: Navigate visualization

### Visualization
- Points color-coded by cluster assignment
- Cluster centers shown as special markers
- Real-time update display
- Interactive coordinate transformation

### Technical Implementation
- 2D data point management
- Euclidean distance calculations
- Dynamic cluster center tracking
- File I/O for saving/loading clusters
- TransformedView for coordinate transforms
- WindowEngine for rendering

## Data Structures
- Point set: Dynamic collection of data points
- Cluster centers: K center points
- Assignments: Point-to-cluster mapping

## Use Cases
- Machine learning visualization
- Understanding clustering algorithms
- Data point classification experiments
- Educational machine learning tool

## Performance
- Real-time clustering on 2D data
- Interactive responsiveness
- Efficient distance calculations
- Quick convergence


## Building the Project

### Prerequisites
- C/C++ Compiler (GCC, Clang, or MSVC)
- Make utility
- Standard development tools

### Build Steps

1. Navigate to project directory:
```bash
cd Gui_KMeans
```

2. Build the project:
```bash
make -f Makefile.(os) all
```

3. For clean rebuild:
```bash
make -f Makefile.(os) clean
make -f Makefile.(os) all
```

4. If there are ./bin and ./libs directories, build libs with:
```bash
make -f Makefile.(os) cleanlib
make -f Makefile.(os) lib
```

### Build Options
```bash
make -f Makefile.(os) all         # build output
make -f Makefile.(os) do        # build + exe output
make -f Makefile.(os) clean   # Remove build artifacts
```

## Running the Project

Execute the compiled binary:

```bash
./build/Main(.exe)
```

Or using make:
```bash
make -f Makefile.(os) exe
```

## Project Organization

```
Gui_KMeans/
├── src/
│   ├── Main.c          # Entry point
│   └── *.c             # Implementation files
├── Makefile            # Build configuration
└── README.md           # This file
```

## Technical Details

### Language: C/C++
- Performance-oriented
- Direct hardware access where needed
- Memory efficient
- Widely portable

### Key Technologies
- Standard C library
- System-specific libraries as needed
- Algorithm optimization
- Efficient data structures

### Code Quality
- Clean, readable implementation
- Proper error handling
- Resource management
- Well-documented algorithms

## Development Notes

### Architecture Decisions
- Modular design for reusability
- Efficient algorithms for performance
- Clear separation of concerns
- Extensible structure

### Performance Optimizations
- Algorithm efficiency
- Memory layout optimization
- Cache-conscious programming
- Minimal overhead

### Portability
- Cross-platform compatible
- Platform-specific optimizations where possible
- Standard library usage
- No external dependencies (where feasible)

## Troubleshooting

### Build Issues
- Ensure compiler is installed
- Check file paths and permissions
- Verify Make installation
- Review compiler error messages

### Runtime Issues
- Check input data validity
- Verify file accessibility
- Ensure sufficient memory
- Review output format

### Performance Issues
- Check compiler optimization flags
- Profile hot code paths
- Review algorithm complexity
- Consider input size

## Future Improvements

Potential enhancements:
- Additional optimization opportunities
- Extended functionality
- Platform-specific optimizations
- Performance profiling

## References

For technical background:
- Algorithm textbooks
- Computer science references
- Language documentation
- Online educational resources

---

*Project implementing practical algorithms and data structures in C/C++*
