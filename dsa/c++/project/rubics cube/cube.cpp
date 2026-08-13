#include<bits/stdc++.h>
#include<math.h>
using namespace std;

class Cube{
    private:
    vector<vector<vector<char>>> cube;
    public:

    Cube(){
        vector<vector<vector<char>>> input(6, vector<vector<char>>(3, vector<char>(3)));
        // for(int i = 0; i<6; i++){
        //     for(int j = 0; j<3; j++){
        //         for(int k = 0; k<3; k++){
        //             cin>>input[i][j][k];
        //         }
        //     }
        // }
        srand(time(0));
        
        vector<char> colors = {'R', 'G','O','B','Y','W'};
        vector<int> freq(6);

        for(int i = 0; i<6; i++){
            for(int j = 0; j<3; j++){
                for(int k = 0; k<3; k++){
                    int randInd = rand()%colors.size();
                    input[i][j][k] = colors[randInd];
                    freq[randInd]++;
                    if(freq[randInd] == 9) colors.erase(colors.begin() + randInd);
                }
            }
        }
        cube = input;
    }
    void display(){
        cout<<"Current situation: "<<endl;
        for(int i = 0; i<cube.size(); i++){
            for(int j = 0; j<cube[i].size(); j++){
                for(int k = 0; k<cube[i][j].size(); k++){
                    cout<<cube[i][j][k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }

};

// int main(){
//     Cube c;
//     c.display();

//     return 0;
// }