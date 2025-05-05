#ifndef GRAPH_H
#define GRAPH_H

// Necessary headers
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "heap.cpp"
#include "vector.cpp"
#include "pair.cpp"

// Type definitions
typedef vector<vector<PAIR_H::pair<int, int>>> AdjacencyType;

// Graph class
class Graph {

// Member Variables
private:
    std::string filename;

    vector<std::string> cities;
    AdjacencyType adjacencyList;

// Constructors
public:
    Graph() = default;
    explicit Graph(const std::string& _filename);

// Member functions
public:
    void initialize(const std::string& _filename);
    vector<std::string> getShortestPath(std::string firstCity, std::string secondCity);

private:
    void initialize();

// Getters and Setters
public:
    [[nodiscard]] int getNumberOfCities() const;

// Helpers
private:
    static vector<std::string> splitLine(const std::string &line);
    static std::string toLowerCase(std::string str);
    int getCityIndex(const std::string &city) const;
    void dijkstra(int start, vector<int> &distances, vector<int> &previous) const;


};

#endif // GRAPH_H