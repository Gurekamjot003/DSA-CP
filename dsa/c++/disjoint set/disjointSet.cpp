#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for( int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    int find_ult_parent(int node){
        if(node == parent[node]) return node;
        return parent[node] = find_ult_parent(parent[node]);
    }

    void union_by_rank(int u, int v){
        int ult_par_u = find_ult_parent(u);
        int ult_par_v = find_ult_parent(v);
        if(ult_par_u == ult_par_v) return;
        if(rank[ult_par_u] < rank[ult_par_v]){
            parent[ult_par_u] = ult_par_v;
        }
        else if(rank[ult_par_u] > rank[ult_par_v]){
            parent[ult_par_v] = ult_par_u;
        }
        else{
            parent[ult_par_u] = ult_par_v;
            rank[ult_par_v]++;
        }
    } 

    void union_by_size(int u, int v){
        int ult_par_u = find_ult_parent(u);
        int ult_par_v = find_ult_parent(v);
        if(ult_par_u == ult_par_v) return;
        if(size[ult_par_u] < size[ult_par_v]){
            parent[ult_par_u] = ult_par_v;
            size[ult_par_v] += size[ult_par_u];
        }
        else{
            parent[ult_par_v] = ult_par_u;
            size[ult_par_u] += size[ult_par_v];
        }
    } 
};

int main(){
    DisjointSet ds(7);
    ds.union_by_size(1, 2);
    ds.union_by_size(2, 3);
    ds.union_by_size(4, 5);
    ds.union_by_size(6, 7);
    ds.union_by_size(5, 6);
    if(ds.find_ult_parent(3) == ds.find_ult_parent(7)) cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    ds.union_by_size(3, 7);
    if(ds.find_ult_parent(3) == ds.find_ult_parent(7)) cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    
}