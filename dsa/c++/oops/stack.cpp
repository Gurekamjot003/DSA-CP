#include<iostream>
using namespace std;

class Stack{
    int stack[50];
    int counter;
    public:
        void initcounter(){
            counter =0;
        } 
        void push(int value){
            stack[counter]=value;
            cout<<value<<" was added to stack"<<endl;
            counter++;
        }
        void pop(){
            counter--;
            cout<<stack[counter]<<" popped from stack"<<endl;
        }
        void display(){
            cout<<endl<<"Stack is as follows: "<<endl;
            for(int i=0; i<counter; i++){
                cout<<stack[i]<<endl;
            }
            cout<<"End of stack"<<endl<<endl;
        }
};

int main(){
    Stack s1;
    s1.initcounter();
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