///////////////////////////////////////////////////////////////////////////////
//
// stack1uthor:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            514 - Relational Operator
// Course:           CMPS 4883
// Semester:         Fall 2020
//
// Description:
//       solves 514 (see attached files for more info)
//
// Usage:
//       run with input file
//
// Files:           514.cpp
//                  input
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n, x;

    while (1){
        stack<int> stack1, stack2;
        scanf("%d", &n);
        if (n == 0)
            break;

        while (1){
            int i = n;
            scanf("%d", &x);
            if (x == 0){
                printf("\n");
                break;
            }

            stack1.push(x);

            for (int i = 1; i < n; i++){
                scanf("%d", &x);
                stack1.push(x);
            }

            for (; i >= 1;)
            {
                if (!stack2.empty() && stack2.top() == i)
                {
                    stack2.pop();
                    i--;
                    continue;
                }

                if (stack1.empty())
                    break;
                if (stack1.top() != i)
                    stack2.push(stack1.top());
                else
                    i--;
                stack1.pop();
            }
            if (stack1.empty() && stack2.empty())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}