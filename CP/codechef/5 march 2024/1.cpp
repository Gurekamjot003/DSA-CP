#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int x, y;
    cin>>x>>y;
    int dist = 0;
    int ans = 0;
    while(dist<y){
        dist+=x;
        ans++;
    }
    cout<<ans;
    return 0;
}
