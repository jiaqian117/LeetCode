// Number of Boomerangs.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
       int res=0;
        unordered_map<int,int> m;
        for(int i=0;i<points.size();++i){
         for(int j=0;j<points.size();++j)
         {
             //if(i==j) continue;
             
            int x=points[i].first - points[j].first;
            int y=points[i].second - points[j].second;
            ++m[x*x+y*y];
             
         }
         for(unordered_map<int,int>::iterator ix=m.begin();ix!=m.end();++ix)
         {
             res+=ix->second*(ix->second -1);
         }
         m.clear();
        }
         return res;
    }
};

int main()
{
	vector<pair<int, int>> p;
	p.push_back(make_pair<int,int>(0,0));
	p.push_back(make_pair<int,int>(1,0));
	p.push_back(make_pair<int,int>(-1,0));
	p.push_back(make_pair<int,int>(0,1));
	p.push_back(make_pair<int,int>(0,-1));
	Solution ob;
	ob.numberOfBoomerangs (p);
	system("pause");
	return 0;
}

