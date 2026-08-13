#include<iostream>
#include<math.h>
using 

int main()
    int n;
    cin>>n;
    int a=n;
    int no=0;
    while (
    {
        n=n/10;
        no++;
    }
    int lastdigit;
    int rev=0;
    no=no-1;
    cout<<a;
    while (a>0)
    {
        int lastdigit;
        lastdigit=a%10;
        rev=rev+lastdigit*(pow(10,no));
        no--;
    }
    cout<<rev;
    
    return 0;
}