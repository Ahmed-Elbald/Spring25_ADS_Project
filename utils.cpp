//
// Created by Ayman Refat on 27/03/2025.
//
#include <tuple>
#include "utils.h"
using namespace std;


int getFirstTuple(tuple<int ,int ,int> t) {
    return get<0>(t);
}
bool minCPM (int a, int b) {
    return a < b ;
}
bool maxCPM (int a, int b) {
    return a > b ;
}
int getFirstPair(pair<int, int> p) {
    return p.first;
}

