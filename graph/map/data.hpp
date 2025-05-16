#pragma once
#include <bits/stdc++.h>
using namespace std;

extern unordered_map<string,int> m;
extern vector<vector<pair<int,int>>> adj;
extern vector<vector<int>> shortest_routes;
extern vector<int> dist;

void createMap();
void createGraph();
vector<vector<int>> dijkstra(int v, int source, vector<vector<pair<int,int>>>& adj);
