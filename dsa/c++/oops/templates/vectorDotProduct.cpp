#include<iostream>
using namespace std;

template <class T>
class vector{
    public:
    int size;
    T* arr;

    vector(int m){
        size=m;
        arr = new T[size];
    }

    void dotProduct(vector &v){
        T d=0;
        for(int i=0; i<size; i++){
            d+=this->arr[i] * v.arr[i];
        }
        cout<<d<<endl;
    }
};

int main(){
    vector<float> v1(3);
    v1.arr[0]=1.4;
    v1.arr[1]=3.3;
    v1.arr[2]=0.1;
    vector<float> v2(3);
    v2.arr[0]=0.1;
    v2.arr[1]=1.9;
    v2.arr[2]=4.1;
    v2.dotProduct(v1);

    return 0;
}