#include <bits/stdc++.h>
#include "data.hpp"
using namespace std;

int main() {
    createMap();
    createGraph();
    string station;
    cout << "Ingrese la estacion en la que se encuentra: ";
    cin >> station;
    
    vector<vector<int>> shortest_routes = dijkstra(63,m[station],adj);
    return 0;
}