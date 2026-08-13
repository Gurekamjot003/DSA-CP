#include<iostream>
using namespace std;

class BaseClass{
    public: 
        int var_base;
        void display(){
            cout<<"Displaying the base variable: "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public: 
        int var_derived;
        void display(){
            cout<<"Displaying the base variable: "<<var_base<<endl;
            cout<<"Displaying the derived variable: "<<var_derived<<endl;
        }
};



int main(){
    BaseClass * base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;
    base_class_pointer = &obj_derived;  //pointing base class pointer to derived class
    base_class_pointer->var_base=18;
    //base_class_pointer->var_derived=18;   //will throw an error
    base_class_pointer->display();

    DerivedClass * derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base = 9800;
    derived_class_pointer->var_derived = 98;
    derived_class_pointer->display();
    return 0;
    }