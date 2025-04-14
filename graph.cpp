// Necessary headers
#include "graph.h"

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

vector<string> Graph::getShortestPath(string firstCity, string secondCity)
{

    // Get the index of the cities
    int start = getCityIndex(toLowerCase(firstCity));
    int end = getCityIndex(toLowerCase(secondCity));

    // Validation
    if (start == -1 || end == -1)
    throw invalid_argument("Invalid city name(s)");
    
    // Dijkstra's algorithm
    vector<int> distances, previous;
    dijkstra(start, distances, previous);
    
    // Validation
    if (distances[end] == INT_MAX)
        throw runtime_error("No path found between the cities");

    // Constructing the path
    vector<int> _path;
    for (int at = end; at != -1; at = previous[at])
        _path.push_back(at);

    int pathSize = static_cast<int>(_path.size());
    vector<string> cityPath(pathSize);

    for (int i = 0; i < pathSize; i++)
        cityPath[pathSize - i - 1] = cities[_path[i]];

    return move(cityPath);
}   


// TODO: Move this logic to the main function in the form of "add_edge" function
void Graph::initialize() {

    // Open the file containing the data
    ifstream file("./data/" + filename);

    // Validation
    if (!file.is_open())
        throw runtime_error("Could not open file at path: " + filename);

    // Ignoring the first line (header)
    string line;
    getline(file, line);

    // Build Adjacency list
    string lastCity;
    int idx = 0;
    while (getline(file, line)) {

        // Get data
        auto lineSplitted = splitLine(line);
        const string& firstCity = toLowerCase(lineSplitted[0]);
        const string& distance = lineSplitted[2];

        // If a new city is introduced
        if (firstCity != lastCity) {
            idx = 0;
            adjacencyList.emplace_back();
            cities.push_back(firstCity);
        }

        // Add a new edge
        if (stoi(distance) != 0)
            adjacencyList.back().emplace_back(idx, stoi(distance));

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
vector<string> Graph::splitLine(const string &line) {

    // Allocate Memory
    vector<string> result(3);

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

string Graph::toLowerCase(string str) {
    // Convert to lower case
    for (char &c : str)
        if (isupper(c))
            c = tolower(c);

    return str;
}

int Graph::getCityIndex(const string &city) const {

    // Applying binary search
    int start = 0, end = getNumberOfCities() - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if (cities[mid] == city)
            return mid;
        else if (cities[mid] < city)
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialization
    distances[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        // Get the current city
        int idx = pq.top().second;
        pq.pop();

        for(auto [nextCity, distance] : adjacencyList[idx]) {
            // Calculate the new distance
            int newDistance = distances[idx] + distance;

            // If the new distance is shorter, update it
            if (newDistance < distances[nextCity]) {
                distances[nextCity] = newDistance;
                previous[nextCity] = idx;
                pq.push({newDistance, nextCity});
            }
        }
    }

}