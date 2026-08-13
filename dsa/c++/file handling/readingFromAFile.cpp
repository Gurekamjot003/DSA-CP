#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    string st;
    ifstream in("readingfromafile.txt");
    getline(in, st);
    cout<<st;
    return 0;
    }