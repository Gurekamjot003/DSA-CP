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

class Node{
  public:
    char val;
    Node* next;
    Node(int value){
        val = value;
        next = NULL;
    }
};

Node* to_ll(string&s){
    Node* head = new Node(s[0]);
    Node* temp = head;
    for(int i = 1; i<s.size(); i++){
        temp->next = new Node(s[i]);
        temp = temp->next;
    }
    return head;
}

vi mishkin_energizer(string& s){
    unordered_map<char, int> freq;
    for(auto& ch: s) freq[ch]++;
    Node* head = to_ll(s);
    int max_freq = s.size();
    
    vector<int> ans;
    int cur_size = s.size(), max_size = 3*s.size();
    while(cur_size < max_size){
        Node* temp = head;
        bool changed = false;
        int index = 1;
        while(temp->next){
            if(temp->val != temp->next->val){
                char ch;
                unordered_set<char> chars = {'L', 'I', 'T'};
                chars.erase(temp->val);
                chars.erase(temp->next->val);
                ch = *chars.begin();
                if(freq[ch]<max_freq){
                    Node* node = new Node(ch);
                    node->next = temp->next;
                    temp->next = node;
                    freq[ch]++;
                    cur_size++;
                    changed = true;
                    ans.push_back(index);
                }
            }
            temp = temp->next;
            index++;
        }
        if(!changed) return {-1};
    }
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        string s; in>>s;
        vi ans = mishkin_energizer(s);
        if((ans.size() == 1 && ans[0] == -1) or ans.size()>(2*n)) cout<< -1 <<endl;
        else
        {cout<<ans.size()<<endl;
        for(auto&n: ans) cout<<n<<endl;}
        // cout<<program_name(parameters)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}