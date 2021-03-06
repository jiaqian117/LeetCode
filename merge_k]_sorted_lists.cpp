// merge_k]_sorted_lists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

// * Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        ListNode *res=lists[0];
        for(int i=1;i<lists.size();i++)
            {
            res=mergeList(res,lists[i]);
        }
        return res;
    }
    ListNode *mergeList(ListNode *l1,ListNode *l2)
        {
         ListNode *res,*r;
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;
        if(l1->val <= l2->val)
        {
        res=r=l1;
        l1=l1->next;
        }
        else
        {
        res=r=l2;
        l2=l2->next;
        }
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                
                res->next=l1;
                
                l1=l1->next;
            }
            else
            {
                
                res->next=l2;
                
                l2=l2->next;
            }
            res=res->next;
        }
        if (l1 != NULL)  
            res->next = l1;  
        else  
            res->next = l2;  
        return r;
        
    }
};

ListNode *l1, *l2, *ll1, *ll2;  
int main() {  
    int n1, n2;  
    Solution s;  
    cin >> n1;  
     ll1 = l1 = new ListNode(0); 
    for (int i = 0; i < n1; i++) {  
        l1->next = new ListNode(0);  
        l1 = l1->next; 
        scanf("%d", &(l1->val));
		 
    }  
    cin >> n2;  
     ll2 = l2 = new ListNode(0); 
    for (int i = 0; i < n2; i++) {  
        l2->next = new ListNode(0);  
        l2 = l2->next;  

        scanf("%d", &(l2->val)); 
		    }  
	vector<ListNode *> l;
	l.push_back (ll1->next);
	l.push_back(ll2->next);

    ListNode *res = s.mergeKLists ( l );  
	
    while (res != NULL) {  
        cout << res->val << ' ';  
        res = res->next;  
    }  
	
   system("pause");
    return 0;  
} 
