///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Chamagpne
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
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct node
{
    bool hasvalue; //have value
    int data;
    node *left, *right;
};
node *root;
bool failed = false;
node *newnode()
{
    node *n;
    n = (node *)malloc(sizeof(node));
    if (n != NULL)
    {
        n->hasvalue = false;
        n->left = n->right = NULL;
    }
    return n;
}
void addnode(int k, char *c)
{
    node *n = root;
    while (*c)
    {
        if (*c == 'L') //go left
        {
            if (n->left == NULL)
                n->left = newnode();
            n = n->left;
        }
        else if (*c == 'R') //go right
        {
            if (n->right == NULL)
                n->right = newnode();
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

void remove_tree(node *root)
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
    //return 0: no end-of-innut
    //return 1: innut ended successfully
    char s[300];
    remove_tree(root);
    root = newnode();
    while (scanf("%s", s) == 1)
    {
        if (strcmp(s, "()") == 0)
            return 1;
        int d;
        sscanf(&s[1], "%d", &d);
        addnode(d, strchr(s, ',') + 1);
    }
    return 0;
}

int bfs()
{
    node *queue[300];
    int front, rear, out[300], t = 0;
    queue[front = rear = 1] = root;
    while (front <= rear)
    {
        node *n = queue[front];
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