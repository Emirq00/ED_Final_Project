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
extern vector<int> routes_ids; // the shortest route from a current node to a destination node
extern vector<int> dist; // the shortest route from a current node to every nodes
extern unordered_map<string , vector<int>> routes; // routes for station

void createMap();
void createGraph();
void createRoutes();
vector<int> dijkstra(int v, int source, int destination, vector<vector<pair<int,int>>>& adj);
