vll find_beautiful_sequence(long long& n, long long& m){
    vll ans;
    if(n == 0) ans.push_back(0);
    int position = 0;
    for(int i = 0; i<64; i++){
        if((1ll<<i) & n) position = i;
    }
    for(int i = position; ((1ll<<i) | n) <= m; i++){
        ans.push_back((1ll<<i) | n);
    }
    // cout<<position<<" ";
    return ans;

}