#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>
#include "data.hpp"
using namespace std;

unordered_map<string,int> m;
vector<vector<pair<int,int>>> adj(92);
vector<int> routes_ids(92);
vector<int> dist(92, INT_MAX);
unordered_map<string , vector<int>> routes;

void createMap();
void createGraph();
void createRoutes();
vector<int> dijkstra(int v, int source, int destination, vector<vector<pair<int,int>>>& adj);
