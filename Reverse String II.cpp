// Reverse String II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>

#include<iostream>

using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
 
       for(int i=0;i!=n;i+=2*k)
       reverse(s.begin()+i,min(s.begin()+i+k,s.end()));
	   cout<<s<<endl;
       return s;
    }
};

void main()
{
	string s("bacdfeg");
	Solution ob;
	ob.reverseStr (s,2);
	system("pause");
}

