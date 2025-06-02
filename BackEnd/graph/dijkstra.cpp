#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>
#include "data.hpp"
using namespace std;

vector<vector<int>> dijkstra(int v, int source, vector<vector<pair<int,int>>>& adj) {
    //Reiniciar dist
    dist.assign(v+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<vector<int>> nodes(v+1);
    
    dist[source] = 0;
    nodes[source] = {source};
    pq.push({0, source});
    
    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                nodes[v] = nodes[u];
                nodes[v].push_back(v);
                pq.push({dist[v], v});
            }
        }
    }
    
    return nodes;
}