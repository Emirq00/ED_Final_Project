#include <bits/stdc++.h>
using namespace std;

extern unordered_map<string,int> m;
extern vector<vector<pair<int,int>>> adj(94);
extern vector<vector<int>> shortest_routes;

void createMap();
void createGraph();
vector<vector<int>> dijkstra(int v, int source, vector<vector<pair<int,int>>>& adj);
