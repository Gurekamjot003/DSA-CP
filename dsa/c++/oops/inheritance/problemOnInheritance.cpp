/*
Create 2 classes:
1. SimpleCa1cu1ator
Takes input of 2 numbers using a utility function and perfoms +, -, *, / and displays the results using another function.

2. ScientificCa1cu1ator -
Takes input of 2 numbers using a utility function and perfoms any four scientific operation of your chioice and displays the results using another function.
Create another class HybridCa1cu1ator and inherit it using these 2 classes:
Q1. What type of inheritance are you using?
Q2. Which mode of inheritance are you using?
*/

#include <iostream>
#include <math.h>
using namespace std;

class simpleCalculator
{
    int a;
    int b;

    float result;

public:
    simpleCalculator() { cout << ""; }
    void display()
    {
        cout << result;
    }
    void setData()
    {
        cout << "Enter the numbers:" << endl;
        cin >> a >> b;
    }
    void add()
    {
        result = a + b;
    }
    void sub()
    {
        result = a - b;
    }
    void mul()
    {
        result = a * b;
    }
    void div()
    {
        result = (float)(float(a) / float(b));
    }
};

class scientificCalculator
{
    float value;
    float result;

public:
    void display2()
    {
        cout << result;
    }
    void setData()
    {
        cout << "Enter the value " << endl;
        cin >> value;
    }

    void sine()
    {
        result = sinf(value);
    }
    void tangent()
    {
        result = tanf(value);
    }
    void cosine()
    {
        result = cosf(value);
    }
    void lg()
    {
        result = log10(value);
    }
};

class hybridCalculator : public simpleCalculator, public scientificCalculator
{
public:
    int choice;
    hybridCalculator() {}
    void setChoice()
    {
    here:
        cout << "What function do you want to perform?   " << endl;
        cout << "1    ->      addition" << endl
             << "2    ->      subtraction" << endl
             << "3    ->      multiplication" << endl
             << "4    ->      division" << endl
             << "5    ->      sine" << endl
             << "6    ->      tangent" << endl
             << "7    ->      cosine" << endl
             << "8    ->      log base 10" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            simpleCalculator::setData();
            add();
            display();
            break;
        case 2:
            simpleCalculator::setData();
            sub();
            display();
            break;
        case 3:
            simpleCalculator::setData();
            mul();
            display();
            break;
        case 4:
            simpleCalculator::setData();
            div();
            display();
            break;
        case 5:
            scientificCalculator::setData();
            sine();
            display2();
            break;
        case 6:
            scientificCalculator::setData();
            tangent();
            display2();
            break;
        case 7:
            scientificCalculator::setData();
            cosine();
            display2();
            break;
        case 8:
            scientificCalculator::setData();
            lg();
            display2();
            break;

        default:
            cout << "You were supposed to write a number between 1 to 8" << endl;
            goto here;
        }
    }
};

int main()
{
    hybridCalculator c1;
    c1.setChoice();
    return 0;
}