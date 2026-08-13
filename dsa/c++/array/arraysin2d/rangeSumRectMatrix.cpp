#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>v[i][j];
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Enter value of l1, r1, l2, r2 \n";
    int l1, r1, l2, r2, sum = 0;
    cin>>l1>>r1>>l2>>r2;

    // method 1 brute force
    /*
    for(int i=l1; i<=l2; i++){
        for(int j=r1; j<=r2; j++){
            sum+=v[i][j];
        }
    }
    */

    // method 2 prefix sum row wise
    /*
    for(int i=0; i<v.size(); i++){
        for(int j=1; j<v[0].size(); j++){
            v[i][j] += v[i][j-1];
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i = r1; i<=r2; i++){
        if(l1!=0)
            sum += v[i][l2]- v[i][l1-1];
        else
            sum += v[i][l2];
    }
    */
    

    // method 3 prefix sum row wise & column wise

    for(int i=0; i<v.size(); i++){
        for(int j=1; j<v[0].size(); j++){
            v[i][j] += v[i][j-1];
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            v[i][j] += v[i-1][j];
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    int topSum = 0, leftSum = 0, topLeftSum = 0;
    if(l1!=0) leftSum = v[l1-1][r2];
    if(r1!=0) topSum = v[l2][r1-1];
    if(l1 != 0 && r1!=0) topLeftSum = v[l1-1][r1-1];
    sum = v[l2][r2] - leftSum - topSum + topLeftSum;

    cout<<sum;

    return 0;
}