// Necessary headers
#include "graph.h"
#include <iostream>
using namespace std;


// Constructors
Graph::Graph(const string &_filename) {
    filename = _filename;
    initialize(filename);
}

// Member functions
void Graph::initialize(const string& _filename) {
    filename = _filename;
    initialize();
}

VECTOR_H::vector<string> Graph::getShortestPath(string firstCity, string secondCity)
{

    // Get the index of the cities
    int start = getCityIndex(toLowerCase(firstCity));
    int end = getCityIndex(toLowerCase(secondCity));

    // Validation
    if (start == -1 || end == -1)
        throw std::invalid_argument("Invalid city name(s)");
    
    // Dijkstra's algorithm
    VECTOR_H::vector<int> distances, previous;
    dijkstra(start, distances, previous);
    
    // Validation
    if (distances[end] == INT_MAX)
        throw std::runtime_error("No path found between the cities");

    // Constructing the path
    VECTOR_H::vector<int> _path;
    for (int at = end; at != -1; at = previous[at])
        _path.push_back(at);

    int pathSize = static_cast<int>(_path.size());
    VECTOR_H::vector<string> cityPath(pathSize);

    for (int i = 0; i < pathSize; i++)
        cityPath[pathSize - i - 1] = cities[_path[i]];

    return std::move(cityPath);
}   


// TODO: Move this logic to the main function in the form of "add_edge" function
void Graph::initialize() {

    // Open the file containing the data
    std::ifstream file("data/" + filename);

    // Validation
    if (!file.is_open())
        throw std::runtime_error("Could not open file at path: " + filename);

    // Ignoring the first line (header)
    string line;
    std::getline(file, line);

    // Build Adjacency list
    string lastCity;
    int idx = 0;
    while (std::getline(file, line)) {

        // Get data
        auto lineSplitted = splitLine(line);
        const string& firstCity = toLowerCase(lineSplitted[0]);
        const string& secondCity = toLowerCase(lineSplitted[1]);
        const string& distance = lineSplitted[2];
        // If a new city is introduced
        if (firstCity != lastCity) {
            idx = 0;
            adjacencyList.push_back({});
            cities.push_back(firstCity);
        }

        // Add a new edge
        if (stoi(distance) != 0)
            adjacencyList.back().push_back({idx, stoi(distance)});

        // Next iteration
        lastCity = firstCity;
        idx++;
    }

}

// Getters and Setters
int Graph::getNumberOfCities() const {
    return static_cast<int>(cities.size());
}


// Helpers
VECTOR_H::vector<string> Graph::splitLine(const string &line) {

    // Allocate Memory
    VECTOR_H::vector<string> result(3 , "");

    // Splitting
    int idx = 0;
    for (char c : line) {
        if (c == ',') {
            idx++;
            continue;
        }
        result[idx] += c ;
    }
    return result;

}

string Graph::toLowerCase(string str) {
    // Convert to lower case
    for (char &c : str) c = tolower(c);

    return str;
}

int Graph::getCityIndex(const string &city) const {


    int start = 0, end = getNumberOfCities() - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if (cities[mid] == city)
            return mid;
        if (cities[mid] < city)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1; // Not found

}

void Graph::dijkstra(int start, VECTOR_H::vector<int> &distances, VECTOR_H::vector<int> &previous) const {

    // Setup
    int numberOfCities = getNumberOfCities();
    distances.resize(numberOfCities, INT_MAX);
    previous.resize(numberOfCities, -1);
    min_heap pq;

    // Initialization
    distances[start] = 0;
    pq.push(PAIR_H::pair<int, int>(0, start));

    while(!pq.empty()) {
        // Get the current city
        int idx = pq.top().second;
        pq.pop();

        for(int i = 0; i < (int)adjacencyList[idx].size(); i++) {
            auto nextCity = adjacencyList[idx][i].first;
            auto distance = adjacencyList[idx][i].second;
            // Calculate the new distance
            int newDistance = distances[idx] + distance;
    
            // If the new distance is shorter, update it
            if (newDistance < distances[nextCity]) {
                distances[nextCity] = newDistance;
                previous[nextCity] = idx;
                pq.push(PAIR_H::pair<int, int>(newDistance, nextCity));
            }
        }
    }

}