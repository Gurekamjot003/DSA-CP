#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Write
{
    string s;

public:
    void setString(string str)
    {
        s = str;
    }
    void give()
    {
        ofstream out("writingHelloWorld.txt");
        out << s;
    }
};

int main()
{
    Write st;
    st.setString("Hello world!");
    st.give();
    return 0;
}