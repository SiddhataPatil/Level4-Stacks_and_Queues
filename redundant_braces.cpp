/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Write a program to validate if the input string has redundant braces
 Example     : ((a + b)) has redundant braces so answer will be 1
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
 int braces(string A);
}obj;

int Solution::braces(string A)
{
    stack<char> input_string;
    int i= 0;
    bool redundant_brace = true;

    while(i<A.length())
    {
        char B = A[i];
        if(B==')')
        {
            redundant_brace= true;
            while (input_string.top()!= '(')
            {
                if(  input_string.top() == '+'|| input_string.top()=='-'|| input_string.top() == '*'|| input_string.top() == '/' )
                redundant_brace = false;
                input_string.pop();
            }
            input_string.pop();
            if(redundant_brace == true)
            return 1;
        }
        else
        {
            input_string.push(B);
        }
        i++;
    }
    return 0;
}

int main()
{
  int result;
  string A = "((a + b))";
  cout<<"1 : has redundant braces "<<endl;
  cout<<"0 : doesn't have have any redundant braces "<<endl;
  result=obj.braces(A) ;
  cout<<"((a + b)) -----> "<<result<<endl;
  return 0;
}
