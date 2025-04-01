#ifndef GRAPH_H
#define GRAPH_H

// Necessary headers
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <queue>

// Used namespace
using namespace std;

// Type definitions
typedef vector<vector<pair<int, int>>> AdjacencyType;

// Graph class
class Graph {

// Member Variables
private:
    string filename;

    vector<string> cities;
    AdjacencyType adjacencyList;

// Constructors
public:
    Graph() = default;
    explicit Graph(const string& _filename);

// Member functions
public:
    void initialize(const string& _filename);
    vector<string> getShortestPath(string firstCity, string secondCity);

private:
    void initialize();

// Getters and Setters
public:
    [[nodiscard]] int getNumberOfCities() const;

// Helpers
private:
    static vector<string> splitLine(const string &line);
    static string toLowerCase(string str);
    int getCityIndex(const string &city) const;
    void dijkstra(int start, vector<int> &distances, vector<int> &previous) const;


};

#endif // GRAPH_H