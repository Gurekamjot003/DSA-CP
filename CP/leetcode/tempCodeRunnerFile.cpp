/*
    Name  : Vansh Thakur
    Email : vansh787624@gmail.com
*/

/* 
    Note:
    Please enter the tree in standard LeetCode / GfG level-order format  
    (example: [1, 2, 3, null, 4])
    as the assignment's input specification was unclear
    i standardized the program to accept LeetCode style testcases, which you can easily
    copy from any binary tree problem on LeetCode
    i have also added some visual examples in main function's top comment
    Thanks :)
*/


#include <bits/stdc++.h>
using namespace std;

//defining Node structure 
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right){}
};

class Solution{
public:
    vector<int> leftView(Node* root){
        /*
            Time Complexity : O(N)
            Space Complexity : O(N) 
            where N = number of nodes in the tree

            this function returns the left view of the tree by taking the 
            first node value of each level and pushing it into the ans array 
            as from the left side only the first node of each level is visible
        */
        queue<Node*> q;  //declaring a queue q for BFS level order traversal of the tree
        vector<int> ans; //answer array to store the left view nodes
        if(!root)return ans; //if there are 0 nodes in the tree return the empty ans array
        q.push(root); //push the first Node in the queue(1st level always has only one node, which is the root)
        while(!q.empty()){  //running the loop until all the levels are processed 

            int size=q.size();  /*
                                 size variable to store the length of current level 
                                 (number of nodes in current level of tree)
                                */
            
            /*
            loop to process every node of the current level
            making sure we dont process more or fewer nodes than this level actually has
            if we dont do this loop can process next levels in the currect level too as there will be no end point
            all nodes are processed
            */
            for(int i=0;i<size;i++){ 

                Node* curr=q.front();  //extracting the front node into curr
                q.pop();               //popping the front node

                if(i==0)ans.push_back(curr->val);  /*
                                                     if i==0 then the curr node is the first node of the current level
                                                     which makes it part of the left view
                                                    */

                if(curr->left)q.push(curr->left);  //if curr has a left child push it into the queue
                if(curr->right)q.push(curr->right); //if curr has a right child push it into the queue
            }
        }
        return ans; //return the left view stored in ans
    } 
    vector<int> rightView(Node* root){
        /*
            Time Complexity : O(N)
            Space Complexity : O(N) 
            where N = number of nodes in the tree

            this function returns the right view of the tree by taking the 
            last node value of each level and pushing it into the ans array 
            as from the right side only the last node of each level is visible
        */
        queue<Node*> q;  //declaring a queue q for BFS level order traversal of the tree
        vector<int> ans; //answer array to store the right view nodes
        if(!root)return ans; //if the tree has 0 nodes return the empty ans array
        q.push(root); //push the root node in the queue (1st level always has only one node, which is the root)

        while(!q.empty()){  //running the loop until all the levels are processed 

            int size=q.size();  /*size variable to store the length of current level 
                                (number of nodes in current level of tree)
                                */

            /*
            loop to process every node of the current level
            making sure we dont process more or fewer nodes than this level actually has
            */
            for(int i=0;i<size;i++){
                Node* curr=q.front();  //extracting the front node into curr
                q.pop();               //popping the front node

                if(i==size-1)ans.push_back(curr->val);  /* 
                                                        if i==size-1 then the curr node is the last node of the current level
                                                        which makes it part of the right view so pushn it into ans
                                                        */

                if(curr->left)q.push(curr->left);   //if curr node has a left child push it into the queue
                if(curr->right)q.push(curr->right); //if curr node has a right child push it into the queue
            }
        }
        return ans; //return the right view stored in ans
    }

    vector<int> topView(Node* root){
        /*
            Time Complexity : O(N logN)   (due to map as it keeps the values in sorted order)
            Space Complexity : O(N) 
            where N = number of nodes in the tree

            this function returns the top view of the tree it uses the concept of HD (Horizontal Distance)
            where the root node's HD is 0, its left child has HD-1 (-1), and its right child has HD+1 (1)
            we can calculate the HD of every node like this, if a node's HD is x then its left child's
            HD will be x-1 and its right child's HD will be x+1

            to find the top view we will take the first node encountered at each horizontal distance during the BFS
            because these are the top nodes visible from the top view of the tree 
        */
        queue<pair<Node*,int>> q; //stores {Node, HD ( Horizontal Distance) } of each node 
        vector<int> ans;   //answer array to store the top view
        if(!root)return ans;//if the tree has 0 nodes return the empty ans array
        q.push({root,0});   // pushing root and root's HD ie. 0 in the queue
        map<int,int> mpp;     /* maps HD -> val ,we will take the first node encountered of each HD for the topView
                                it will store the HD in sorted order 
                              */
        
        while(!q.empty()){  //running the while loop until all Nodes are processed 

            Node* curr = q.front().first; //extracting the current node into curr
            int   HD   = q.front().second; // extracting current node's horizontal distance into HD
            q.pop(); // removing the extracted front from queue

            if(mpp.find(HD)==mpp.end()){  //checking if the current node's HD is appearing for the first time or not

                mpp[HD]=curr->val;  /* if this HD is not present in the map, it means this is the first node encountered on that HD
                                       so it will be visible from the top, hence we store it in the map
                                       since map stores keys in sorted order, insertion takes O(logN)
                                       This makes the overall complexity O(N logN) */
            }

            if(curr->left)q.push({curr->left,HD-1});   //if curr has a left child push it into the queue with its horizontal distance (HD-1)
            if(curr->right)q.push({curr->right,HD+1}); //if curr has a right child push it into the queue with its horizontal distance (HD+1)
        }
        for(auto& it:mpp){
            ans.push_back(it.second); //map stores nodes in increasing HD so pushing them gives the top view from left to right
        }
        return ans; //returning the ans ie. the top view of the tree
    }
    vector<int> bottomView(Node* root){
        /*
            Time Complexity : O(N logN)  (due to map as it keeps the values in sorted order)
            Space Complexity : O(N) 
            where N = number of nodes in the tree

            this function returns the bottom view of the tree it uses the concept of HD (Horizontal Distance)
            where the root node's HD is 0, its left child has HD-1 (-1), and its right child has HD+1 (1)
            we can calculate the HD of every node like this, if a node's HD is x then its left child's
            HD will be x-1 and its right child's HD will be x+1

            to find the bottom view we will take the last node encountered at each horizontal distance during the BFS
            because these are the bottom nodes visible from the bottom view of the tree 
        */
        queue<pair<Node*,int>> q; //stores {Node, HD ( Horizontal Distance) } of each node 
        vector<int> ans; //answer array to store the bottom view
        if(!root)return ans; //if the tree has 0 nodes return the empty ans array
        q.push({root,0}); //pushing root and root's HD ie. 0 in the queue
        map<int,int> mpp;  //maps HD -> val ,we will take the last node encountered of each HD for the bottomView

        while(!q.empty()){  //running the while loop until all Nodes are processed 
            Node* curr = q.front().first;   //extracting the current node into curr
            int   HD   = q.front().second;  //extracting current node's horizontal distance into HD
            q.pop(); //removing the extracted front from queue

            mpp[HD]=curr->val; /* updating the map each time ensures that it always stores the last node's value encountered on this HD
                                 Since map stores keys in sorted order, insertion takes O(logN)
                                 This makes the overall complexity O(N logN) */

            if(curr->left)q.push({curr->left,HD-1});   //if curr has a left child push it into the queue with its horizontal distance HD-1
            if(curr->right)q.push({curr->right,HD+1}); //if curr has a right child push it into the queue with its horizontal distance HD+1
        }
        for(auto& it:mpp){
            ans.push_back(it.second);  //map stores nodes in increasing HD so pushing them gives the bottom view from left to right
        }
        return ans; //returning the ans ie. the bottom view of the tree
    }
    vector<int> alternateLevel(Node* root){
        /*
            Time Complexity : O(N)
            Space Complexity : O(N) 
            where N = number of nodes in the tree

            this function returns the alternate level order traversal of the tree
            that means we will take nodes level by level but only include nodes from
            alternate levels (like here :take level 1, skip level 2,take level 3, skip level 4 ,and so on)

            we will use normal BFS for level-order traversal and keep a level counter using a boolean flag
            if the current level is one of the required (alternate) levels, we will add
            all the nodes of that level into the ans array
        */
        queue<Node*> q;  //queue for BFS level order traversal
        vector<int> ans; //answer array to store alternate level nodes
        if(!root)return ans; //if tree has 0 nodes return empty ans array
        q.push(root);    //pushing the root node into the queue as the first level
        bool pick=true;  //this flag decides whether to pick when pick = true or skip when pick = false the current level
        while(!q.empty()){ //runing while loop until all nodes / levels are processed
            int size=q.size(); /*size variable to store the length of current level 
                                (number of nodes in current level of tree)
                                */

            /*
            loop to process every node of the current level
            making sure we dont process more or fewer nodes than this level actually has
            */
            for(int i=0;i<size;i++){
                Node* curr=q.front(); //extracting the front node
                q.pop();              //popping the front node from queue

                if(pick==true)ans.push_back(curr->val); /*if pick is true it means we have to include this level in the answer,
                                                           so we push the curr node's value into the ans array */

                if(curr->left)q.push(curr->left);  //pushing left child of curr if it exists
                if(curr->right)q.push(curr->right);  //pushing right child of curr if it exists

            }
            pick=!pick; /*flipping the pick so next level becomes skipped, then picked, then skipped, and so on
                         if we picked the current level then pick is true already so it will become false for the next level
                         and if we skipped this level ie. pick is false already it will become true for the next level*/
        }
        return ans; //returning the ans (alternate level traversal)
    }


    //Bonus Question
    int maxPathSum(Node* root){
        /*
            Time Complexity : O(N)
            Space Complexity : O(H)
            where N = number of nodes in the tree 
            and H = height of the tree (because of the recursion stack)

            this function returns the maximum path sum in the tree
            a path can start and end at any node but it must be continuous
            we call helper(root,ans) which calculates the max path sum and keeps
            updating ans with the best value found so far
        */
        int ans=INT_MIN; //this will store the maximum path sum we can get from the whole tree initially it is set to INT_MIN as we dont know whats the maximum path sum is 
        helper(root,ans);//calling helper which will update ans everytime a new maximum path is found (ans is passed by reference)
        return ans; //retrn the maximum path sum
    }

    int helper(Node* root,int& ans){
        if(!root)return 0; // if node is NULL return 0 

        /*getting left and right side max path sums, but if they are negative we take 0
         because a negative value will only reduce the overall path sum, so we can ignore them*/
        int left=max(helper(root->left,ans),0);
        int right=max(helper(root->right,ans),0);

        ans=max(ans,left +right +root->val); /*checking the best path that passes through the current node
                                                left+right+root->val gives the best through the current node 
                                             */
        

        return root->val +max(left,right); /*return the best single side path including current node
                                             because upward we can only take one side (left or right)
                                           */
    }
};

Node* constructTree(vector<string>& arr){
    /*
        Time Complexity : O(N)
        Space Complexity : O(N)
        this function builds the tree in LeetCode/GfG style (level order)
        where input looks like [1,2,3,null,null,4,5] etc
    */
    if(arr.size()==0 || arr[0]=="null" || arr[0]=="N") return NULL; //if array is empty or first element is null then tree is empty so return NULL

    Node* root=NULL;
    try{
        root=new Node(stoi(arr[0])); //creating the root node from the first element of the array
    }catch(...){
        cout<<"\nInvalid input! Please read the input format in main function top comment\n"; //if the input is invalid it will throw this error message
        exit(1); //terminate the program
    }

    queue<Node*> q; 
    q.push(root); //pushing root in queue so we can attach children level by level

    int i=1; //"i" will move over the array and help to assign children to each node
    while(!q.empty() && i < arr.size()){ 
        // taking the front node from queue and now we will try to set its left and right child
        Node* curr=q.front(); 
        q.pop();

        // left child
        if(i < arr.size() && arr[i]!="null" && arr[i]!="N"){
            //if left child exists and is a valid integer then attach it and push it into the queue else throw error
            try{
                curr->left=new Node(stoi(arr[i])); 
                q.push(curr->left);
            }catch(...){
                cout<<"\nInvalid input! Please read the input format in main function top comment\n"; //if the input is invalid it will throw this error message
                exit(1);//terminate the program
            }
        }
        i++;

        // right child
        if(i < arr.size() && arr[i]!="null" && arr[i]!="N"){
            //if right child exists and is a valid integer then attach it and push it into the queue else throw error
            try{
                curr->right=new Node(stoi(arr[i])); 
                q.push(curr->right);
            }catch(...){
                cout<<"\nInvalid input! Please read the input format in main function top comment\n"; //if the input is invalid it will throw this error message
                exit(1);//terminate the program
            }
        }
        i++;
    }
    return root; 
}


vector<string> makeArr(string s) {

    /*
        Time Complexity : O(N)
        Space Complexity : O(N)
        where N = length of s
        this function will take the raw input line and will convert it into a string array for tree construction 
    */

    //remove '[' and ']' from the string if present
    if (!s.empty() && s.front() == '[') s.erase(s.begin());
    if (!s.empty() && s.back() == ']') s.pop_back();

    //replace commas with spaces so that stringstream can process the line
    for (char &c:s) {
        if (c==','){
            c =' ';
        }
    }

    stringstream ss(s); //create stringstream to parse the modified string it will seperate space seperated values and store them
    string x; //temp variable to hold each string we extract from ss
    vector<string> arr;  //this will be our final array of strings
    while (ss >> x) {  
        //keep reading strings until we run out, push each one to the array
        arr.push_back(x);
    }
    return arr; //returning the finished array 
}

int main(){
    /*
    Taking input in LeetCode/GfG style:

    Example 1(assignment): 
    [1, 7, 9, 2, 6, null, 9, null, null, 5, 11, 5]
    Tree :

            1
          /   \
         7      9
        / \       \
       2   6        9
          /  \     /
         5    11  5

    Example 2(assignment): 
    [-10, 9, 20, null, null, 15, 7]
    Tree:
          -10
         /   \
        9     20
             /  \
            15   7


    Example 3:
    [1, 2, null, 3, null, 4, null, 5]
    Tree:
               1
              /
             2
            /
           3
          /
         4
        /
       5

    Example 4:
    [1, null, 2, null, 3, null, 4]
    Tree:
          1
            \
             2
               \
                3
                 \
                  4

    Example 5:
    [1, 2, 3, 4, 5, 6, 7]
    Tree:
          1
        /   \
       2     3
      / \   / \
     4   5 6   7

    Example 6:
    [1, null, 2, 3, null, null, 4, 5]
    Tree:
          1
           \
            2
           /
          3
           \
            4
           /
          5

    Example 7:
    [10, -2, 7, 8, -4, 6, null, 5, null, null, null, null, null, 2]
    Tree:
             10
            /   \
          -2      7
         /  \    /
        8   -4  6
       /         
      5
     /
    2          

    Example 8:
    [100000, 50000, -100000, null, 75000, null, null, 99999]
    Tree:
              100000
            /        \
        50000       -100000
           \  
           75000
           /
        99999

    i have used the leetcode testcases for these examples as the assignment's input format 
    was not clear
    you can pass the input in any of the given format :

     [10, -2, 7, 8, -4, 6, null, 5, null, null, null, null, null, 2]

     10 -2 7 8 -4 6 null 5 null null null null null 2

     10, -2, 7, 8, -4, 6, null, 5, null, null, null, null, null, 2

     [10 -2 7 8 -4 6 N 5 N N N N N 2]


     Note : Both "null" and "N" can be used to represent "null"
    */
    string raw; //variable for storing the raw input line 
    cout<<"Enter the tree (BFS Traversal) (LeetCode/GFG Style) : "<<endl;
    getline(cin, raw); /*Taking input Please enter the tree in standard LeetCode format,
                        as this program builds the binary tree only from LeetCode/GfG-style
                        level-order input (eg: [1,2,3,null,4])*/

    vector<string> arr=makeArr(raw); //converts the raw input into a string array for tree construction 

    Node* root=constructTree(arr); //constructs the tree using the string array and returns the root 

    Solution test; //creating Solution object test for testing

    cout<<endl;
    //testing left view
    vector<int> lv = test.leftView(root);
    cout<<"Left View is:               ";
    for(int x:lv)cout<<x<<" ";
    cout<<endl;

    //testing right view
    vector<int> rv = test.rightView(root);
    cout<<"Right View is:              ";
    for(int x:rv)cout<<x<<" ";
    cout<<endl;

    //testing top view
    vector<int> tv = test.topView(root);
    cout<<"Top View is:                ";
    for(int x:tv)cout<<x<<" ";
    cout<<endl;

    //testing bottom view
    vector<int> bv = test.bottomView(root);
    cout<<"Bottom View is:             ";
    for(int x:bv)cout<<x<<" ";
    cout<<endl;

    //testing alternate level order
    vector<int> al = test.alternateLevel(root);
    cout<<"Alternate Level Order is:   ";
    for(int x:al)cout<<x<<" ";
    cout<<endl;

    //testing max path sum
    int mps = test.maxPathSum(root);
    cout<<"Max Path Sum is:            "<<mps<<endl;

    return 0;
}