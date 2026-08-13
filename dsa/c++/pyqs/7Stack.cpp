//wap to implement a stack and perform push and pop operation in cpp

#include<iostream>
using namespace std;

class Stack{
    int arr[10];
    int counter=0;
    int value;
    public:
        void push(int n){
            arr[counter++]=n;
            cout<<n<<" was added to the stack "<<endl;
        }
        void pop(){
            cout<<arr[--counter]<<" was popped out from stack"<<endl;

        }
        void display(){
            cout<<endl<<"Stack: "<<endl;
            for(int i=0; i<counter; i++){
                cout<<arr[i]<<endl;
            }
            cout<<"End of stack"<<endl<<endl;
        }
};

int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.display();
    s1.pop();
    s1.pop();
    s1.display();
    return 0;
}