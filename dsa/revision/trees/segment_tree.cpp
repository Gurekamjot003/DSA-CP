#include<bits/stdc++.h>
using namespace std;

template<class T>
class SegmentTree{
    vector<T> tree;
    vector<T> arr; // The original array for which the segment tree is built

    // Function to initialize a leaf node in the segment tree
    // For a sum segment tree, it's just the value itself.
    T init_leaf(int index){
        return arr[index];
    }

    // Function to combine results from two child nodes
    // For a sum segment tree, it's addition.
    T combine(T val_1, T val_2){
        return val_1 + val_2;
    }

    // Helper function for updating a value in the segment tree
    // target_index: index in the original array to update
    // left, right: current segment range covered by the 'index' node
    // index: current node index in the 'tree' vector
    void update_helper(int target_index, int left, int right, int index = 0){
        if(left == right){
            // Leaf node reached, update its value
            tree[index] = init_leaf(target_index);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;

        // Recurse into the appropriate child
        if(target_index<=mid) update_helper(target_index, left, mid, left_child);
        else update_helper(target_index, mid+1, right, right_child);

        // Update the current node's value based on its children
        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    // Helper function for querying a range in the segment tree
    // q_left, q_right: query range
    // left, right: current segment range covered by the 'index' node
    // index: current node index in the 'tree' vector
    T query_helper(int q_left, int q_right, int left, int right, int index = 0){
        // Case 1: Current segment is completely within the query range
        if(left>=q_left && right<=q_right) return tree[index];
        // Case 2: Current segment is completely outside the query range
        if(left>q_right or right<q_left) return (T)0;
        // Case 3: Current segment partially overlaps with the query range
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        // Combine results from left and right children
        return combine(query_helper(q_left, q_right, left, mid, left_child), query_helper(q_left, q_right, mid+1, right, right_child)); 
    }

public:
    // Constructor
    SegmentTree(const vector<T>& initial_arr){ // Use const reference for initial array
        int sz = initial_arr.size();
        tree.resize(sz*4);
        this->arr = initial_arr; // Copy the initial array
        // Start building the tree from the root (index 0) covering the entire array range
        build(0, 0, sz-1);
    }

    // Function to build the segment tree
    // index: current node index in the 'tree' vector
    // left, right: current segment range covered by the 'index' node
    void build(int index, int left, int right){
        if(left == right){
            // Leaf node: store the value from the original array
            tree[index] = init_leaf(left);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        // Recursively build left and right subtrees
        build(left_child, left, mid);
        build(right_child, mid + 1, right);
        
        // Current node's value is combined from its children
        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    // Public method to update a value in the original array and propagate changes to the tree
    void update(int data_index, T value){
        arr[data_index] = value; // Update the original array
        update_helper(data_index, 0, arr.size()-1); // Call helper to update the tree
    }

    // Public method to query the sum (or other aggregate) for a given range
    T get_value(int q_left, int q_right){
        // Call helper to perform the query on the tree
        return query_helper(q_left, q_right, 0, arr.size()-1);
    }

};

int main(){
    vector<int> data = {1, 2, 3, 4, 5};

    SegmentTree st(data);

    cout<<st.get_value(1,3)<<endl;
    st.update(2, 10);
    cout<<st.get_value(0, 3)<<endl;
    cout<<st.get_value(2, 2)<<endl; // Query a single element
}