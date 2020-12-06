///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            122 - Trees on the Level
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 122 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           122.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

bool failed = false;
// Linked list node
struct ListNode
{
    int data;
    bool hasvalue;
    ListNode *left, *right;
};

ListNode *root;
// method to create a new binary tree node from the given data
ListNode *newNode(int data)
{
    ListNode *temp = new ListNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void addnode(int k, char *c)
{
    ListNode *n = new ListNode;
    while (*c)
    {
        if (*c == 'L') //go left
        {
            if (n->left == NULL)
                n->left = newNode(k);
            n = n->left;
        }
        else if (*c == 'R') //go right
        {
            if (n->right == NULL)
                n->right = newNode(k);
            n = n->right;
        }
        else
            break;
        c++;
    }
    if (n->hasvalue == false)
        n->data = k;
    else
        failed = true;
    n->hasvalue = true; //DON'T FORGET TO SET hasvalue TO TRUE!!!
}
void remove_tree(ListNode *root)
{
    if (root != NULL)
    {
        remove_tree(root->left);
        remove_tree(root->right);
        free(root);
    }
}
int init()
{
    char s[300];
    remove_tree(root);
    root = new ListNode;
    while (scanf("%s", s) == 1)
    {
        if (strcmp(s, "()") == 0) //helps eliminate unneeded input
            return 1;
        int d;
        sscanf(&s[1], "%d", &d);
        addnode(d, strchr(s, ',') + 1);
    }
    return 0;
}

int bfs()
{
    ListNode *queue[300]; //max items
    int front, rear, out[300], t = 0;
    queue[front = rear = 1] = root;
    while (front <= rear)
    {
        ListNode *n = queue[front];
        if (n->hasvalue == false)
            return 0;
        out[++t] = n->data;
        if (n->left != NULL)
            queue[++rear] = n->left;
        if (n->right != NULL)
            queue[++rear] = n->right;
        front++;
    }
    for (int i = 1; i <= t; i++)
        cout << out[i] << " ";
    cout << endl;
    return 1;
}
//took a more function-oriented approach with this one since it's so complicated
int main()
{
    while (init() == 1)
    {
        if (!bfs())
            failed = true;
        if (failed)
            cout << "not complete" << endl;
    }
    return 0;
}