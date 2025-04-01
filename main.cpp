#include "graph.cpp"
using namespace std;

int main() {

    // To do
    // Add the GUI

    Graph graph(string("state_distances.csv"));

    string firstCity, secondCity;

    cout << "Please enter the name of the first city: ";
    getline(cin, firstCity);
    
    cout << "Please enter the name of the second city: ";
    getline(cin, secondCity);

    try {
        auto path = graph.getShortestPath(firstCity, secondCity);
        cout << "Shortest path from " << firstCity << " to " << secondCity << endl;
        for(int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1)
                cout << " -> ";
        }
        cout << endl;
    } catch(exception &e) {
        cout << "Error: " << e.what() << endl;
    }

}
