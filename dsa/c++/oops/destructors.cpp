#include <iostream>
using namespace std;

class geeks
{
public:
    int id;

    ~geeks(){
        cout<<"Destructor called for id: "<<id<<endl;
    }
};

int
main()
{
    geeks obj1;
    obj1.id=7;
    for(int i=0; i<5; i++){
        geeks obj2;
        obj2.id=i;
    }

    return 0;
}