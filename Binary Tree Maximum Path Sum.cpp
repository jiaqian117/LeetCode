// Binary Tree Maximum Path Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
 
 struct TreeNode {
      int val;
      TreeNode *left,*right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
  TreeNode* CreatBiTree(TreeNode* &T)
{
	char ch;
	if((ch=getchar())=='#')
		return	NULL;
	T=new TreeNode((ch - '0'));
	//T->val=ch;
	CreatBiTree(T->left);
	CreatBiTree(T->right );
	return	T;
}
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int re=INT_MIN;
        maxToRoot(root,re);
        return re;
    }
    int maxToRoot(TreeNode *root,int &re)
        {
        if(!root) return 0;
        int l=maxToRoot(root->left,re);
        int r=maxToRoot(root->right,re);
        if(l<0) l=0;
        if(r<0) r=0;
        if((l+r+root->val)>re) re=l+r+root->val;
        return root->val+=max(l,r);
    }
};
int main()
{
	TreeNode *p;
	CreatBiTree(p);
	Solution ob;
	cout<<ob.maxPathSum (p)<<endl;
	system("pause");
	return 0;
}

