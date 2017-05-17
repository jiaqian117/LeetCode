// list to BST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

 //* Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
	public:
    TreeNode *sortedListToBST(vector<int> &vec,int start,int end)
        {
         int length=end+start;
        int mid=length+1/2;
        if(end<=start) return NULL;
		vector<int>::iterator iter = vec.begin();
        int x=*(iter+mid);
        TreeNode *root=new TreeNode(x);
        root->left=sortedListToBST(vec,start,mid-1);
        root->right=sortedListToBST(vec,mid+1,end);
        return root;
    }

    
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> vec;
        if(head==NULL)
            return NULL;
        while(head->next!=NULL)
            {
            vec.push_back(head->val);
            head=head->next;
        }
        
        return sortedListToBST(vec,0,vec.size()-1);
    }
};

int main()
{
	int data[]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(data)/sizeof(data[0]);
	vector<int> vec(data,data+n);
	Solution ob;
	ob.sortedListToBST (vec,0,vec.size ());

	system("pause");
	return 0;
}
