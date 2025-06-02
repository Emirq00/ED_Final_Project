#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

extern unordered_map<string , int> m; // map [station : node]
extern vector<vector<pair<int , int>>> adj; // adjacent nodes
extern vector<vector<int>> shortest_routes; // the shortest route from a current node to a destination node
extern vector<int> dist; // the shortest route from a current node to every nodes
extern unordered_map<string , vector<int>> routes; // routes for station

void createMap();
void createGraph();
void createRoutes();
vector<vector<int>> dijkstra(int v, int source, vector<vector<pair<int,int>>>& adj);
