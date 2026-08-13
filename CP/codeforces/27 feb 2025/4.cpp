#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
#define pll pair<ll, ll>
#define vll vector<ll>
#define vb vector<bool>
#define umapii unordered_map<int, int>
#define mapii map<int, int>
#define useti unordered_set<int>

void find_levels(vi& levels_array, vvi &graph, int cur = 1, int depth = 0){
    if(levels_array.size() == depth) levels_array.push_back(0);
    levels_array[depth]++;
    for(auto& neighbor: graph[cur]){
        find_levels(levels_array, graph, neighbor, depth+1);
    }
}

int number_of_valid_vertex_sequences(vi & arr){
    vvi graph(arr.size()+2);
    for(int i = 0; i<arr.size(); i++){
        graph[arr[i]].push_back(i+2);
    }
    vi level_wise_number_of_vertices;
    find_levels(level_wise_number_of_vertices, graph);
    for(auto n: level_wise_number_of_vertices) cout<<n<<" ";
    return 0;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t; 
    while(t--){
        int n; in>>n;
        vi arr(n-1);
        for(int i = 0; i<(n-1); i++) in>>arr[i];
        cout<<number_of_valid_vertex_sequences(arr)<<endl;
    }
    // int t; cin>>t; 
    // while(t--){
    //     int n; cin>>n;
    //     vi arr(n-1);
    //     for(int i = 0; i<(n-1); i++) cin>>arr[i];
    //     cout<<number_of_valid_vertex_sequences(arr)<<endl;
    // }
    return 0;
}