#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> arr;

    public:

    MaxHeap(){
        arr = {};
    }
    MaxHeap(vector<int> input){
        arr = input;
        build_heap();
    }

    void build_heap(){
        for(int parent = (arr.size()/2 -1); parent>=0; parent--){
            step_down(parent);
        }
    }
    void push(int val){
        arr.push_back(val);
        step_up(arr.size()-1);
    }

    void print() const{
        for(auto& n: arr) cout<<n<<" ";
        cout<<endl;
    }

    int top() const{
        if(arr.empty()) throw runtime_error("Heap is empty");
        return arr[0];
    }

    void step_down(int parent){
        while(parent<arr.size()){
            int left = parent*2 + 1, right = parent*2+2;
            int largest = parent;
            if(left<arr.size()){
                if(arr[left] > arr[largest]){
                    largest = left;
                }
            }
            if(right<arr.size()){
                if(arr[right] > arr[largest]){
                    largest = right;
                }
            }
            if(largest == parent) break;
            swap(arr[parent], arr[largest]);
            parent = largest;
        }
    }

    int size(){
        return arr.size();
    }

    bool empty(){
        return (arr.size() == 0);
    }

    void step_up(int child){
        while(child != 0){
            int parent_index = (child-1)/2;
            if(arr[child]<arr[parent_index]) return;
            swap(arr[child], arr[parent_index]);
            child = parent_index;
        }
    }

    void pop(){
        arr[0] = arr.back();
        arr.pop_back();
        step_down(0);        
    }

    void heap_sort(){
        build_heap();
        for(int i = arr.size() - 1; i > 0; i--){
            swap(arr[0], arr[i]);
            int original_size = arr.size();
            arr.resize(i);
            step_down(0);
            arr.resize(original_size);
        }
    }

};



int main(){
    MaxHeap pq;
    vector<int> to_push = {4, 14, 11, 114, 24, 1};
    for(auto& n: to_push) pq.push(n);
    pq.print();
    vector<int> arr = {10, 3, 8 ,9, 5, 13, 18, 14, 11, 70};
    MaxHeap pq2(arr);
    pq2.print();
    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    return 0;
}