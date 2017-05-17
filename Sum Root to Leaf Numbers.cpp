// Sum Root to Leaf Numbers.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
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

 
void PreOrderTraverse(TreeNode* T){  
 //����ݹ����������  
 if(T){//����㲻Ϊ�յ�ʱ��ִ��  
  cout<<T->val;  
  PreOrderTraverse(T->left);//  
  PreOrderTraverse(T->right);  
 }  
 else cout<<"";  
}//PreOrderTraverse  
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers1(root,0);
    }
    int sumNumbers1(TreeNode *root,int val)
    {
        if(root==NULL) return 0;
        val=val*10+root->val;
        if(root->left==NULL && root->right==NULL)
           return val;
        return sumNumbers1(root->left,val)+sumNumbers1(root->right,val);
    }
};
 
int main()
{
	TreeNode* T;
	CreatBiTree(T);
	Solution ob;
	PreOrderTraverse(T);
	//cout<<ob.sumNumbers (p)<<endl;
	system("pause");
	return 0;
}

