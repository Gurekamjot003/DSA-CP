#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    ifstream in("input.txt");
    int t; in>>t;
    while(t--){
        int x, y,z, a,b,c;

        in>>x>>y>>z>>a>>b>>c;
        int ans = 0;
        ans += (min(c, z));
        y += max(0, z-c);
        ans += min(y, b);
        x += max(0, y-b);
        ans += min(x,a);
        cout<<ans<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    //     int x, y,z, a,b,c;

    //     cin>>x>>y>>z>>a>>b>>c;
    //     int ans = 0;
    //     ans += (max(c, z));
    //     y += max(0, z-c);
    //     ans += max(y, b);
    //     x += max(0, y-b);
    //     ans += max(x,a);
    //     cout<<ans<<endl;
    // }
}
