#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<char>> &gameBoard){
    cout<<endl<<"Game Board: "<<endl;
    for(auto row: gameBoard){
        
        for(auto col: row){
            cout<<" | "<<col;
        }
        cout<<" | "<<endl<<endl;
    }
    cout<<endl<<endl;
}

bool checkWinner(vector<vector<char>> gameBoard, char symbol){
    //check row
    int n = 3;
    for(int i = 0; i<n; i++){
        bool flag = true;
        for(int j = 0; j<n; j++){
            if(gameBoard[i][j] != symbol){
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }

    //check col
    for(int i = 0; i<n; i++){
        bool flag = true;
        for(int j = 0; j<n; j++){
            if(gameBoard[j][i] != symbol){
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }

    //check diagonals
    bool flag = true;
    for(int i = 0; i<n; i++){
        if(gameBoard[i][i] != symbol)
        {
            flag = false;
            break;
        }
    }
    if(flag) return true;
    
    flag = true;
    for(int i = 0; i<n; i++){
        if(gameBoard[i][n-i-1] != symbol){
            flag = false;
            break;
        }
    }
    if(flag) return true;
    return false;
}

int main(){
    vector<vector<char>> gameBoard(3, vector<char>(3, '_'));
    display(gameBoard);
    char currentSymbol = 'X';
    int occupied = 0;
    while(true){
        cout<<"Enter position from 1 to 9 to place '"<<currentSymbol<<"'! \n";
        int pos;
        cin>>pos;
        pos--;
        if(pos<0 or pos > 8){
            cout<<"ERROR!"<<endl;
            continue;
        }
        int row = pos/3;
        pos%=3;
        int col = pos;
        if(gameBoard[row][col] == '_'){
            gameBoard[row][col] = currentSymbol;
            occupied++;
        }
        else{
            cout<<"position already used! "<<endl;
            continue;
        }
        display(gameBoard);
        
        if(occupied >= 3 && checkWinner(gameBoard, currentSymbol)){
            cout<<currentSymbol<<" Wins! ";
            return 0;
        }
        if(occupied == 9){
            cout<<"ITS A DRAW! ";
            return 0;
        }
        currentSymbol == 'X'? currentSymbol = 'O': currentSymbol = 'X';
        
    }  
    return 0;
}