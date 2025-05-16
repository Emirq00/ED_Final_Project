#include <bits/stdc++.h>
#include "data.hpp"
using namespace std;

int main() {
    createMap();
    createGraph();
    string station, station2;
    
    cout << "Ingrese la estacion en la que se encuentra: ";
    cin >> station;
    if(m.find(station) == m.end()) {
        cout << "estacion no valida";
        return -1;
    }
    
    shortest_routes = dijkstra(92, m[station], adj);
    
    cout << "A que estacion quieres llegar?: ";
    cin >> station2;
    if(m.find(station2) == m.end()) {
        cout << "estacion no valida";
        return -1;
    }
    
    for(auto i : shortest_routes[m[station2]]) {
        for(auto &j : m) {
            if(j.second == i) {
                cout << j.first << " ";
            }
        }
    }
    return 0;
}