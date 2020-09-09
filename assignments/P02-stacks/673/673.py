#  
# Author:           Paige Champagne
# Email:            paigechamp@gmail.com
# Label:            673 - Parenthesis Balance
# Course:           CMPS 4883
# Semester:         Fall 2020
#
# Description:
#       solves 673 (see attached files for more info)
#
# Usage:
#       run with input file
#
# Files:           673.py
#                  input
#

count = input()
​
for i in range(int(count)):
    parens = input()
​    stack = []
    if len(parens) % 2 == 1:
        print("No")
        continue
    
    flag = "Yes"
    for p in parens:
        if p == '(' or p == '[':
            stack.append(p)
        else:
            if len(stack) == 0:
                flag="No"
                break
            if p == ')':
                if stack[-1] == '(':
                    stack.pop()
                else:
                    flag = "No"
                    break
            if p == ']':
                if stack[-1] == '[':
                    stack.pop()
                else:
                    flag = "No"
                    break
    if len(stack) > 0:
        flag = "No"
    print(flag)