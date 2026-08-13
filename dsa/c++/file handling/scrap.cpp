#include <bits/stdc++.h>
#include<fstream>
using namespace std;


int main() {
    
    auto start = chrono::high_resolution_clock::now(); 
    vector<int> v(99999);
    ifstream in("input.txt"); 
    string st;
    getline(in, st);
    ofstream out("output.txt");
    for(int i = 0; i<st.size(); i++){
        if(st[i] == '1') out<<'2';
        else out<<st[i];
    }
    // for(int i = 0; i<v.size(); i++){
    //     v[i] = i+1;
    // }
    // out<<"[";
    // for(int i = v.size()-1; i>=0; i--){
    //     int left, right;
    //     for(int j = 0; j<v.size(); j++){
    //         if(v[j] == i+1) right = j;
    //         if(v[j] == (i+2)/2) left = j;
    //     }
    //     swap(v[left], v[right]);
        
    // }
    // for(int i = 0; i<v.size(); i++){
    //     out<<v[i];
    //     if(i!=v.size()-1) out<<", null, ";
    // }
    // out<<"]";
    // End timing
    auto end = chrono::high_resolution_clock::now(); 
    chrono::duration<double> duration = end - start; 

    // Print results
    cout << "Time taken by program is : " << fixed << setprecision(10) 
         << duration.count() << " sec " << endl; 

    return 0;
}
