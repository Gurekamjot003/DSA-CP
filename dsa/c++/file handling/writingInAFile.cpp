#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    string st="gurekam bhai";
    ofstream out("writinginafile.txt");
    out<<st;
    return 0;
}