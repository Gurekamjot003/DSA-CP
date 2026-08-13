#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v){
    cout<<"Elements in the vector are: ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    cout<<"Enter size of vector: ";
    int size, element;
    cin>>size;
    for(int i = 0; i<size; i++){
        cout<<"Enter element in vector: "<<endl;
        cin>>element;
        v.push_back(element);
    }
    display(v);

    vector<int> :: iterator iter = v.begin();
    // v.insert(iter, 5);
    // display(v);
    v.insert(iter + 1, 50, 20);      
    display(v);

    return 0;
}