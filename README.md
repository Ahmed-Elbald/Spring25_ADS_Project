# Map Navigator

This project is a **Map Navigator** application developed as part of the **Applied Data Structures** course at AUC for Spring 2025. The program calculates the shortest path between two cities using **Dijkstra's Algorithm** and demonstrates the use of custom data structures.

---

## Features

- **Graph Representation**: Uses an adjacency list to represent the graph of cities and distances.
- **Custom Data Structures**:
  - A custom implementation of `pair` and `vector` classes.
  - A custom `min_heap` class for efficient priority queue operations.
- **Shortest Path Calculation**: Implements Dijkstra's algorithm to find the shortest path between two cities.
- **User Interaction**: Accepts user input for the source and destination cities and displays the shortest path.

---

## File Structure

### Source Files

- **`main.cpp`**: The entry point of the program. Handles user input and displays the shortest path.
- **`graph.h` / `graph.cpp`**: Implements the `Graph` class, which manages the adjacency list and Dijkstra's algorithm.
- **`heap.h` / `heap.cpp`**: Implements a custom `min_heap` class for priority queue operations.
- **`pair.h` / `pair.cpp`**: Implements a custom `pair` class for storing key-value pairs.
- **`vector.h` / `vector.cpp`**: Implements a custom `vector` class for dynamic array operations.

### Data File

- **`data/state_distances.csv`**: Contains the dataset of distances between cities in the format:

## How to Run

### Prerequisites

- A C++ compiler that supports C++17 (e.g., `g++`).
- Ensure the `state_distances.csv` file is located in the `data/` directory relative to the executable.

### Compilation

The project is already compiled. You can run it using the command:

```bash
./main.exe
```

from your terminal, or by manually ruing the main.exe file.

If you need to do any changes, you can recompile the project as follows (g++):

```bash
g++ -c vector.h pair.h heap.h graph.h
g++ -c vector.cpp pair.cpp heap.cpp graph.cpp
g++ -c main.cpp
g++ main.o graph.o pair.o heap.o vector.o -o main
```

## Future Improvements

1. **Graphical User Interface (GUI)**: Add a GUI to enhance user interaction and visualization of the graph and paths.
2. **Dynamic Edge Addition**: Implement functionality to allow users to dynamically add or modify edges in the graph.
3. **Performance Optimization**: Optimize the custom data structures (e.g., vector, min_heap) for better performance with large datasets.

## Contributors

This is a collaborative work of Ahmed Mohammed, Ayman Shahata, and Youssef Salem.
