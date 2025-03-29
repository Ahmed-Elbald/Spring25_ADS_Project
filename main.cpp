
#include <iostream>
#include <tuple>  // For std::tuple
#include "heap.h"
#include "utils.h"
using namespace std;

int main() {

    // test with tuple
    Heap<tuple<int, int, int>, function<bool(int,int)> ,function<int(tuple<int, int, int>)>> h( getFirstTuple, minCPM);
    h.insert(make_tuple(3,4,5));
    h.insert(make_tuple(2,3,4));
    h.insert(make_tuple(1,2,3));
    while (!h.empty()) {
        auto t = h.top();
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
        h.pop();
    }

    // Test with pair
    Heap<pair<int, int>,function<bool(int,int)> ,function<int(pair<int, int>)>> h2( getFirstPair, maxCPM);
    h2.insert(make_pair(3, 4));
    h2.insert(make_pair(2, 3));
    h2.insert(make_pair(1, 2));
    while (!h2.empty()) {
        auto p = h2.top();
        cout << p.first << " " << p.second << endl;
        h2.pop();
    }
}
