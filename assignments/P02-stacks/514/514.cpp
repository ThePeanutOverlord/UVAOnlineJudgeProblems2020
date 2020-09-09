///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
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

int main()
{
    int n, x;

    while (1)
    {
        stack<int> A, B;
        scanf("%d", &n);
        if (n == 0)
            break;

        while (1)
        {
            int i = n;
            scanf("%d", &x);
            if (x == 0)
            {
                printf("\n");
                break;
            }

            A.push(x);

            for (int i = 1; i < n; i++)
            {
                scanf("%d", &x);
                A.push(x);
            }

            for (; i >= 1;)
            {
                if (!B.empty() && B.top() == i)
                {
                    B.pop();
                    i--;
                    continue;
                }

                if (A.empty())
                    break;
                if (A.top() != i)
                    B.push(A.top());
                else
                    i--;
                A.pop();
            }
            if (A.empty() && B.empty())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}