/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 Example     : Given height = [2,1,5,6,2,3], o/p =10
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
 int largestRectangleArea(vector<int> &A);
}obj;

int Solution::largestRectangleArea(vector<int> &A) {

            int result = 0;
            A.push_back(0);
            vector<int> index;

            for(int i = 0; i < A.size(); i++)
            {
                while(index.size() > 0 && A[index.back()] >= A[i])
                {
                    int height = A[index.back()];
                    index.pop_back();
                    int check_height = index.size() > 0 ? index.back() : -1;
                    if(height * (i-check_height-1) > result)
                        result = height * (i-check_height-1);
                }
                index.push_back(i);
            }

            return result;
}

int main()
{
  int result;
  int A1[12] = {2,1,5,6,2,3};
  vector<int> A(A1, A1+sizeof(A1)/sizeof(A1[0]));
  result=obj.largestRectangleArea(A) ;
  cout<<"Given [2,1,5,6,2,3]"<<endl;
  cout<<"Largest rectangle possible is "<<result<<endl;
  return 0;
}
