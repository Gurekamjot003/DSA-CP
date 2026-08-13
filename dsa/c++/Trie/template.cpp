#include<bits/stdc++.h>
using namespace std;

class Trie {
    vector<Trie*> next;
    int count;

    void dfs(Trie* node, int & ans){
        if(!node) return;
        ans += node->count;
        for(auto& n: node->next){
            dfs(n, ans);
        }
    }

public:
    Trie() {
        next.resize(26, NULL);
        count = 0;
    }

    void insert(string word) {
        Trie* node = this;
        for(auto& ch: word){
            
            if(!node->next[ch-'a']) node->next[ch-'a'] = new Trie();
            node = node->next[ch-'a'];
        }
        node->count++;
    }

    int countWordsEqualTo(string word) {
        Trie* node = this;
        for(auto& ch: word){
            if(!node->next[ch-'a']) return 0;
            node = node->next[ch-'a'];
        }
        return node->count;
    }

    int countWordsStartingWith(string word) {
        Trie* node = this;
        for(auto& ch: word){
            if(!node->next[ch-'a']) return 0;
            node = node->next[ch-'a'];
        }
        int ans = 0;
        dfs(node, ans);
        return ans;
    }

    bool erase(string word, int i = 0){
        if(i>=word.size()){
            if(count>0) count--;
            if(count == 0){
                for(auto& n: next){
                    if(n) return false;
                }
                return true;
            }
            return false;
        }
        if(!next[word[i]-'a']) return false;
        if(next[word[i]-'a']->erase(word, i+1) && count == 0){
            delete next[word[i]-'a'];
            next[word[i]-'a'] = NULL;
            for(auto& n: next) if(n) return false;
            return true;
        }
        return false;
    }
};

// ——— Stress Test Harness ———

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N_OPS = 100000;
    const int MAX_LEN = 5;     // random words up to length 5
    const string ALPHABET = "abcd";

    mt19937 rng(12345);
    uniform_int_distribution<int> opDist(0, 3);
    uniform_int_distribution<int> lenDist(1, MAX_LEN);
    uniform_int_distribution<int> charDist(0, (int)ALPHABET.size()-1);

    Trie trie;
    multiset<string> ref;    // reference multiset

    auto randWord = [&]() {
        int L = lenDist(rng);
        string s;
        while(L--){
            s += ALPHABET[charDist(rng)];
        }
        return s;
    };

    for(int step = 1; step <= N_OPS; ++step){
        int op = opDist(rng);
        string w = randWord();

        if(op == 0){
            // insert
            trie.insert(w);
            ref.insert(w);
        }
        else if(op == 1){
            // erase one instance
            trie.erase(w);
            auto it = ref.find(w);
            if(it != ref.end()) ref.erase(it);
        }
        else if(op == 2){
            // countWordsEqualTo
            int got = trie.countWordsEqualTo(w);
            int expect = ref.count(w);
            if(got != expect){
                cerr << "Mismatch at step " << step << " in countWordsEqualTo(\""
                     << w << "\") got=" << got << " expect=" << expect << "\n";
                return 1;
            }
        }
        else {
            // countWordsStartingWith
            int got = trie.countWordsStartingWith(w);
            int expect = 0;
            for(auto &s : ref){
                if(s.rfind(w,0) == 0) ++expect; 
            }
            if(got != expect){
                cerr << "Mismatch at step " << step << " in countWordsStartingWith(\""
                     << w << "\") got=" << got << " expect=" << expect << "\n";
                return 1;
            }
        }
    }

    cout << "All tests passed! (" << N_OPS << " random ops)\n";
    return 0;
}