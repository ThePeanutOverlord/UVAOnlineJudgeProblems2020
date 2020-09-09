#  
# Author:           Paige Champagne
# Email:            paigechamp@gmail.com
# Label:            727 - Equation
# Course:           CMPS 4883
# Semester:         Fall 2020
#
# Description:
#       solves 727 (see attached files for more info)
#
# Usage:
#       run with input file
#
# Files:           727.py
#                  input
#


count = input()
#print(count)
x = input()
#print(x)
x = input()
for i in range(int(count)):
    stack = []
    string = ''
    while x != '\n':
     # print(x)
      if x == '(' or x == ')' or x == '+' or x == '-' or x == '/' or x == '*':
            
           # print("stack: ", stack)
            if stack and (x == '+' or x == '-') and (stack[-1] == '/' or stack[-1] == '*'): 
              #  print("in less than")
                stack.append(x)
                for j in range(len(stack)): 
                  string += stack.pop()
            elif stack and(x == '+' or x == '-') and (stack[-1] == '+' or stack[-1] == '-'):
               # print("in equal +-")
                stack.append(x)
                string += stack.pop()
            elif stack and (x == '*' or x == '/') and (stack[-1] == '*' or stack[-1] == '/'):
               # print("in equal */")
                stack.append(x)
                string += stack.pop()
            elif stack and x == ')':
              #  print("in closed parenthesis")
                while stack[-1] != '(':
                  string += stack.pop()
                stack.pop()
            elif x == '(':
                stack.append(x)
            else:
                stack.append(x)
      else:
           # print("in int")
            string += x
           # print("String in progress: ", string)    
      try:
         x = input() 
      except EOFError:
        break;
    
    if stack:
      for i in range(len(stack)):
        string += stack.pop()  
    print(string)
    print("\n")


