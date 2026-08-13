#ifndef GUREKAM
#define GUREKAM
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
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
#define all(x) x.begin(),x.end()
#define yn(x) cout<<(x?"YES":"NO")<<endl
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep1(i, n) for(int i = 1; i<=n; i++)
#define rev(i, n, step) for(int i = n-1; i>=0; i-= step)

template<typename T>
void amin(T& a, T b){ a = min(a, b); }
template<typename T>
void amax(T& a, T b){ a = max(a, b); }

template<typename T>
T gcd(T a, T b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b) {
        T t = b;
        b = a % b;
        a = t;
    }
    return a;
}

template<typename T>
T lcm(T a, T b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

vector<int> prime_numbers_upto(int n){
    vector<bool> is_prime(n+1, true);
    vi ans;
    for(int i = 2; i<=n; i++){
        if(!is_prime[i]) continue;
        ans.push_back(i);
        for(int j = i*2; j<=n; j+=i) is_prime[j] = false;
    }
    return ans;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll mod) {
    return power(a, mod - 2, mod);
}

istream& getInputStream() {
    static ifstream file("input.txt");
    return (file.is_open()? file: cin);
}
#endif


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* prev_end;
    ListNode* ptr1, *ptr2;
    ListNode* seg2_end, *seg1_end;

    void merge(){
        ListNode* temp_ptr = prev_end;
        while(ptr1 != seg1_end && ptr2 != seg2_end){
            if(ptr1->val < ptr2->val){
                temp_ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                temp_ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            temp_ptr = temp_ptr->next;
        }
        while(ptr1 != seg1_end){
            temp_ptr->next = ptr1;
            temp_ptr = temp_ptr->next;
            ptr1 = ptr1->next;
        }
        while(ptr2 != seg2_end){
            temp_ptr->next = ptr2;
            temp_ptr = temp_ptr->next;
            ptr2 = ptr2->next;
        }
        temp_ptr ->next = seg2_end;
    }

public:
    ListNode* sortList(ListNode* head) {
        ListNode* ptr = head;
        int sz = 0;
        while(ptr){
            ptr = ptr->next; sz++;
        }
        head = new ListNode(0, head);
        int gap = 1;
        while(gap<sz){
            prev_end = head;
            ptr = head->next;
            while(ptr){
                
                //set ptr1, ptr2, seg1_end, seg2_end
                ptr1 = ptr;
                int count = gap;
                while(ptr && count--){
                    ptr = ptr->next;
                }
                if(!ptr) break;
                ptr2 = seg1_end = ptr;
                count = gap;
                while(ptr && count--){
                    ptr = ptr->next;
                }
                seg2_end = ptr;
                merge();

                //update prev_end
                count = gap*2;
                while(count-- && prev_end){
                    prev_end = prev_end->next;
                }
            }
            gap<<=1;
        }
        return head->next;
    }
};