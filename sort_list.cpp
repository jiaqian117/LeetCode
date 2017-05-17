// sort_list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include <list>
#include<algorithm>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
  ListNode *sortList(ListNode *head) {
     if(head==NULL||head->next==NULL)
        return head;
        return mergeSort(head);
    }
ListNode *mergeSort(ListNode *head)
    {
    if(head==NULL||head->next==NULL)
        return head;
    ListNode *fast=head,*slow=head,*pre=NULL;
    while(fast!=NULL&&fast->next!=NULL)
        {
        fast=fast->next->next;
        pre=slow;
        slow=slow->next;
    }
    pre->next=NULL;
    ListNode *l1=mergeSort(head);
    ListNode *l2=mergeSort(slow);
    return merge(l1,l2);
    }


    ListNode* merge(ListNode* l1, ListNode* l2) {
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

ListNode *l1, *ll1;  
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
   
	ListNode *res = s.sortList(ll1->next );  
    while (res != NULL) {  
        cout << res->val << ' ';  
        res = res->next;  
    }  
   system("pause");
    return 0;  
} 
