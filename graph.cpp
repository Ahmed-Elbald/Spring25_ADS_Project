// Necessary headers
#include "graph.h"

// Constructors
Graph::Graph(const std::string &_filename) {
    filename = _filename;
    initialize(filename);
}

// Member functions
void Graph::initialize(const std::string& _filename) {
    filename = _filename;
    initialize();
}

vector<std::string> Graph::getShortestPath(std::string firstCity, std::string secondCity)
{

    // Get the index of the cities
    int start = getCityIndex(toLowerCase(firstCity));
    int end = getCityIndex(toLowerCase(secondCity));

    // Validation
    if (start == -1 || end == -1)
        throw std::invalid_argument("Invalid city name(s)");
    
    // Dijkstra's algorithm
    vector<int> distances, previous;
    dijkstra(start, distances, previous);
    
    // Validation
    if (distances[end] == INT_MAX)
        throw std::runtime_error("No path found between the cities");

    // Constructing the path
    vector<int> _path;
    for (int at = end; at != -1; at = previous[at])
        _path.push_back(at);

    int pathSize = static_cast<int>(_path.get_size());
    vector<std::string> cityPath(pathSize);

    for (int i = 0; i < pathSize; i++)
        cityPath[pathSize - i - 1] = cities[_path[i]];

    return move(cityPath);
}   


// TODO: Move this logic to the main function in the form of "add_edge" function
void Graph::initialize() {

    // Open the file containing the data
    std::ifstream file("./data/" + filename);

    // Validation
    if (!file.is_open())
        throw std::runtime_error("Could not open file at path: " + filename);

    // Ignoring the first line (header)
    std::string line;
    std::getline(file, line);

    // Build Adjacency list
    std::string lastCity;
    int idx = 0;
    while (std::getline(file, line)) {

        // Get data
        auto lineSplitted = splitLine(line);
        const std::string& firstCity = toLowerCase(lineSplitted[0]);
        const std::string& distance = lineSplitted[2];

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
    return static_cast<int>(cities.get_size());
}


// Helpers
vector<std::string> Graph::splitLine(const std::string &line) {

    // Allocate Memory
    vector<std::string> result(3);

    // Splitting
    int idx = 0;
    for (char c : line) {
        if (c == ',') {
            idx++;
            continue;
        }
        result[idx].append(&c);
    }

    return result;

}

std::string Graph::toLowerCase(std::string str) {
    // Convert to lower case
    for (char &c : str)
        if (isupper(c))
            c = tolower(c);

    return str;
}

int Graph::getCityIndex(const std::string &city) const {

    // Applying binary search
    int start = 0, end = getNumberOfCities() - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if (cities.get_at(mid) == city)
            return mid;
        else if (cities.get_at(mid) < city)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1; // Not found

}

void Graph::dijkstra(int start, vector<int> &distances, vector<int> &previous) const {

    // Setup
    int numberOfCities = getNumberOfCities();
    distances.resize(numberOfCities, INT_MAX);
    previous.resize(numberOfCities, -1);
    HEAP_H::priority_queue<PAIR_H::pair<int, int>, vector<PAIR_H::pair<int, int>>, std::greater<PAIR_H::pair<int, int>>> pq;

    // Initialization
    distances[start] = 0;
    pq.insert({0, start});

    while(!pq.empty()) {
        // Get the current city
        int idx = pq.top().second;
        pq.pop();

        for(int i = 0; i < (int)adjacencyList.get_size(); i++) {
            auto nextCity = adjacencyList.get_at(i).get_at(idx).first;
            auto distance = adjacencyList.get_at(i).get_at(idx).second;
            // Calculate the new distance
            int newDistance = distances.get_at(idx) + distance;
    
            // If the new distance is shorter, update it
            if (newDistance < distances[nextCity]) {
                distances[nextCity] = newDistance;
                previous[nextCity] = idx;
                pq.insert({newDistance, nextCity});
            }
        }
    }

}