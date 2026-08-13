#include<bits/stdc++.h>
using namespace std;

template<class T>
class SegmentTree{
    vector<T> tree;
    vector<T> data;

    T init(int index){
        return data[index];
    }

    T combine(T val_1, int val_2){
        return val_1 + val_2;
    }

    void update_helper(int target_index, int left, int right, int index = 0){
        if(left == right){
            tree[index] = init(target_index);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        if(target_index<=mid) update_helper(target_index, left, mid, left_child);
        else update_helper(target_index, mid+1, right, right_child);

        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    T query_helper(int q_left, int q_right, int left, int right, int index = 0){
        if(left>=q_left && right<=q_right) return tree[index];
        if(left>q_right or right<q_left) return (T)0;
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        return combine(query_helper(q_left, q_right, left, mid, left_child), query_helper(q_left, q_right, mid+1, right, right_child)); 
    }

public:
    SegmentTree(vector<T>& data){
        int sz = data.size();
        tree.resize(sz*4);
        this->data = data;
        int left = 0, right= data.size()-1;
        build(data, left, right);
    }

    void build(vector<T>& data, int left, int right, int index = 0){
        if(left == right){
            tree[index] = init(left);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        build(data, left, mid, left_child);
        build(data, mid + 1, right, right_child);
        
        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    void update(int data_index, T value){
        data[data_index] = value;
        update_helper(data_index, 0, data.size()-1);
    }

    T get_value(int q_left, int q_right){
        return query_helper(q_left, q_right, 0, data.size()-1);
    }

};

// int main(){
//     vector<int> data = {1,2,3,4,5};

//     SegmentTree st(data);

//     cout<<st.get_value(1,3)<<endl;
//     st.update(2, 10);
//     cout<<st.get_value(0, 3)<<endl;
// }