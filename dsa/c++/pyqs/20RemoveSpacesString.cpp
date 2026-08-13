//wap to remove all the spaces from a string without using inbuilt functions

#include<iostream>
#include<string>
using namespace std;

class space{
    char *s;
    public:
        void setData(){
            cin.get(s,100);
        }
        void getData(){
            for(int i=0; s[i]!='\0'; i++){
                if(s[i]!=' '){
                    cout<<s[i];
                }
            }
        }
};

int main(){
    space s;
    s.setData();
    s.getData();
    return 0;
}