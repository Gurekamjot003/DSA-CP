// wap to open a file and write hello world in it using file handling

#include<iostream>
#include<fstream>
using namespace std;

class write{
    public:
    write(string s){
        ofstream out("HelloWorldFileHandling.txt");
        out<<s;
    }
};

int main(){
    write w("Hello world!");
    return 0;
}