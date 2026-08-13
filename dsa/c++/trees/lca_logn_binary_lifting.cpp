#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> parent;
vector<int> height;
void init(vector<vector<int>>& edges){
    n = edges.size()+1;
    parent.resize(n+1);
    height.resize(n+1);
    vector<vector<int>> graph(n+1);
    
    for(auto& e: edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    queue<pair<int, int>> q; 
    q.push({1, -1});

    height[1] = 0;
    int h = 1;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto[u, prev] = q.front();
            q.pop();
            for(auto& v: graph[u]){
                if(v == prev) continue;   // skip reverse edge
                parent[v].push_back(u);
                fill(v);
                q.push({v, u});
                height[v] = h;
            }
        } 
        h++;
    }
}

void fill(int u){
    int v = parent[u][0]; 
    int exp = 0;
    while(exp<parent[v].size()){
        v = parent[v][exp++];
        parent[u].push_back(v);
    }
}

int kth_ancestor(int node, int k){
    for(int i = 20; i>=0; i--){
        if(1<<i & k){
            if(i<parent[node].size()){
                node = parent[node][i];
            }
            else return -1;
        }
    }
    return node;
}

int LCA(int u, int v){
    if(height[u]>height[v]) return LCA(v, u);
    if(height[v]>height[u]){
        int diff = height[v] - height[u];
        v = kth_ancestor(v, diff);
    }

    int ans = 1;
    for(int i = parent[u].size()-1; i>=0; i--){
        if(u == v) return u;
        if(parent[u][i] == parent[v][i]) ans = parent[u][i];
        else{
            u = parent[u][i]; v = parent[v][i];
            i = min<int>(i, parent[u].size());
        }
    }
    
    return ans;
}
