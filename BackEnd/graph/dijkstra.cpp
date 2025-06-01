#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>
#include "data.hpp"
using namespace std;

vector<int> dijkstra(int v, int source, int destination, vector<vector<pair<int,int>>>& adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> nodes(v+1, -1);
    vector<int> r_ids;
    
    dist[source] = 0;
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
                nodes[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    int i = destination;
    while(i != source) {
        r_ids.push_back(i);
        i = nodes[i];
    } r_ids.push_back(source);
    reverse(r_ids.begin(),r_ids.end());
    
    return r_ids;
}
