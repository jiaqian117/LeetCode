// Intersection_of_Two_Arrays.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include<string>
#include<map>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int,int> m;
        for(int i=0;i!=nums1.size();++i)
        ++m[nums1[i]];
        for(int i=0;i!=nums2.size();++i)
        --m[nums2[i]];
        for(map<int,int>::iterator ix=m.begin();ix!=m.end();++ix)
        {
            if(ix->second>0)
            for(int i=0;i!=ix->second;i++)
            res.push_back (ix->first );
        }
        return res;
    }
};
void main()
{
	system("pause");
}

