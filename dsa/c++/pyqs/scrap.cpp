#include<iostream>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='X';
bool tie=false;
string n1="";
string n2="";

void fun1(){
    
    cout<<" "<<space[0][0]<<"| "<<space[0][1]<<"| "<<space[0][2]<<endl;
    cout<<"||"<<endl;
    cout<<" "<<space[1][0]<<"| "<<space[1][1]<<"| "<<space[1][2]<<endl;
    cout<<"||"<<endl;
    cout<<" "<<space[2][0]<<"| "<<space[2][1]<<"| "<<space[2][2]<<endl;
    cout<<"  |  |  "<<endl;
}

void fun2(){
    int digit;
    if(token=='X'){
        cout<<n1<<" will enter ";
        cin>>digit;
    }
    if(token=='O'){
        cout<<n2<<" will enter ";
        cin>>digit;
    }
    if(digit==1){
        row=0;
        column=0;
    }
    if(digit==2){
        row=0;
        column=1;
    }
    if(digit==3){
        row=0;
        column=2;
    }
    if(digit==4){
        row=1;
        column=0;
    }
    if(digit==5){
        row=1;
        column=1;
    }
    if(digit==6){
        row=1;
        column=2;
    }
    if(digit==7){
        row=2;
        column=0;
    }
    if(digit==8){
        row=2;
        column=1;
    }
    if(digit==9){
        row=2;
        column=2;
    }
    else if(digit<1 || digit>9){
        cout<<"invalid !!"<<endl;
    }
    if(token=='X' && space[row][column]!='X' && space[row][column]!='O'){
        space[row][column]='X';
        token='O';
    }
    else if(token=='O' && space[row][column]!='X' && space[row][column]!='O'){
        space[row][column]='O';
        token='X';
    }
    else{
        cout<<"space is not empty!!!  "<<endl;
        fun2();
    }
    
}

bool fun3(){
    for(int i=0 ;i<3 ;i++){
        if(space[0][i]==space[1][i] && space[0][i]==space[2][i] || space[i][0]==space[i][1] && space[i][0]==space[i][2]){
            return true;
        }
    }
    if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[0][2]==space[3][0]){
        return true;
    }

    for(int i=0 ;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!='X' && space[i][j]!='O'){
                return false;
            }
        }
    }
    tie=true;
    return false;
}

int main(){
    cout<<"enter the name of first player : ";
    getline(cin,n1);
    cout<<"enter the name of second player : ";
    getline(cin,n2);
    cout<<n1<<" will play first"<<endl;
    cout<<n2<<" will play second"<<endl;
    while(!fun3()){
        fun1();
        fun2();
        fun3();
    }
    fun1();
    if(token=='X' && tie==false){
        cout<<n2<<" wins !!";
    }
    else if(token=='O' && tie==false){
        cout<<n1<<" wins !!";
    }
    else{
        cout<<"its draw!!"<<endl;
    }
}