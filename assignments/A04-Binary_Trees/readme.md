## A04 Binary Trees
### Paige Champagne
### Description:

For this assignment you wanted a set of problems from uva about binary trees and also some snippets of binary trees.


### Files:
| Number | Folder                | Description       |
| :----: | --------------------- | ----------------- |
|   1    | [12476](./p12476.pdf) | binary tree game  |
|   2    | [122](./122.pdf)      | binary tree print |

### Problems:

#### [uva 12476](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3920)
This one is about a sort of game that deals with a binary tree and outputs whether or not it is possible to win

#### [uva 122](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=58)
This one is about printing a binary tree. It seems easier than the others I've looked at but it might be a good one for the class to do idk.

### Binary Tree snippets
This one in c++ is using a linked list and it doesn't use a class but it does use a struct
''' 
 using namespace std; 
  
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
  
    // val is the key or the value that 
    // has to be added to the data part 
    Node(int val) 
    { 
        data = val; 
  
        // Left and right child for node 
        // will be initialized to null 
        left = NULL; 
        right = NULL; 
    } 
    }; 
  
    int main() 
    { 
  
    /*create root*/
    struct Node* root = new Node(1); 
    /* following is the tree after above statement 
  
             1 
            / \ 
            NULL NULL 
    */
  
    root->left = new Node(2); 
    root->right = new Node(3); 
    /* 2 and 3 become left and right children of 1 
                    1 
                    / \ 
                   2     3 
                  / \    /  \ 
               NULL NULL NULL NULL 
    */
  
    root->left->left = new Node(4); 
    /* 4 becomes left child of 2 
               1 
            /    \ 
            2     3 
            / \  / \ 
    4 NULL NULL NULL 
    / \ 
    NULL NULL 
    */
  
    return 0; 
    } 

This is an array implementation in c++ even though those kinda suck I thought it would be good to see one

'''

    // C++ implementation of tree using array
    // numbering starting from 0 to n-1.
    #include<bits/stdc++.h>
    using namespace std;
    char tree[10];
    int root(char key)
    {
        if(tree[0] != '\0')
            cout << "Tree already had root";
        else
            tree[0] = key;
        return 0;
    }
    
    int set_left(char key, int parent)
    { 
        if(tree[parent] == '\0')
            cout << "\nCan't set child at"
                << (parent * 2) + 1 
                << " , no parent found";
        else
            tree[(parent * 2) + 1] = key;
        return 0;
    }
    
    int set_right(char key, int parent)
    {
        if(tree[parent] == '\0')
            cout << "\nCan't set child at"
                << (parent * 2) + 2
                << " , no parent found";
        else
            tree[(parent * 2) + 2] = key;
        return 0;
    }
    
    int print_tree()
    {
        cout << "\n";
        for(int i = 0; i < 10; i++)
        {
            if(tree[i] != '\0')
                cout << tree[i];
            else
                cout << "-";
        }
        return 0;
    }
    
    // Driver Code
    int main()
    {
        root('A');
        //insert_left('B',0);
        set_right('C', 0);
        set_left('D', 1);
        set_right('E', 1);
        set_right('F', 2);
        print_tree();
        return 0;
    }
    
    // This code is contributed by
    // Gaurav_Kumar_Raghav

### Sources:
https://www.geeksforgeeks.org/binary-tree-array-implementation/

https://www.geeksforgeeks.org/binary-tree-set-1-introduction/
