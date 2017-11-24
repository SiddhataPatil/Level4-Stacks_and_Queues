/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Container With Most Water
 Example     : Input : [1, 5, 4, 3] Output : 6 Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3.  So total area = 3 * 2 = 6
  ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
 int trap(const vector<int> &A);
}obj;

int chooseMax(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int chooseMin(int a, int b){
    if(a > b){
        return b;
    }
    return a;
}

int Solution::trap(const vector<int> &A)
{
    if(A.size() == 0)
    {
        return 0;
    }

    vector<int> left(A.size());
    vector<int> right(A.size());

    left[0] = A[0];

    for(int i = 1; i < A.size(); i++)
    {
        left[i] = chooseMax(left[i-1], A[i]);
    }

    right[A.size()-1] = A[A.size()-1];

    for(int i = A.size()-2; i >= 0; i--)
    {
        right[i] = chooseMax(right[i+1], A[i]);
    }

    int result = 0;

    for(int i = 0; i < A.size(); i++){
        result = result + chooseMin(left[i], right[i]) - A[i];
    }

    return result;

}

int main()
{
  int result;
  int A1[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> A(A1, A1+sizeof(A1)/sizeof(A1[0]));
  result=obj.trap(A) ;
  cout<<"Given [0,1,0,2,1,0,1,3,2,1,2,1]"<<endl;
  cout<<"water traped is "<<result<<" units"<<endl;
  return 0;
}
