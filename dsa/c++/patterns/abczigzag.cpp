/*  a       i       q       y
     b     h j     p r     x z
      c   g   k   o   s   w
       d f     l n     t v
        e       m       u
*/

#include<iostream>
using namespace std;

int main(){
    int start= 97, end =123;
    for(int i=start; i<end; i++){
        if(i==start or i==start+8 or i==start +16 or i==start+24){
            cout<<char(i);
        }
        else
            cout<<" ";
    }
    cout<<'\n';
    for(int i=start; i<end; i++){
        if(i==start+1 or i==start +7 or i==start +9 or i==start+15 or i== start+ 17 or i==start+23 or i==start+25){
            cout<<char(i);
        }
        else
            cout<<" ";
    }
    cout<<'\n';
    for(int i=start; i<end; i++){
        if(i==start +2 or i==start +6 or i== start+10 or i==start+14 or i==start+18 or i==start+22){
            cout<<char(i);
        }
        else
            cout<<" ";
    }
    cout<<'\n';
    for(int i=start; i<end; i++){
        if(i==start +3 or i==start +5 or i== start+11 or i==start+13 or i==start+19 or i==start+21){
            cout<<char(i);
        }
        else
            cout<<" ";
    }
    cout<<'\n';
    for(int i=start; i<end; i++){
        if(i==start+4 or i==start+12 or i==start +20){
            cout<<char(i);
        }
        else
            cout<<" ";
    }
    return 0;
}