#include <bits/stdc++.h>
#include "data.hpp"
using namespace std;

unordered_map<string,int> m;
vector<vector<pair<int,int>>> adj(92);
vector<vector<int>> shortest_routes(92);
vector<int> dist(92, INT_MAX);

void createMap();
void createGraph();
vector<vector<int>> dijkstra(int v, int source, vector<vector<pair<int,int>>>& adj);
