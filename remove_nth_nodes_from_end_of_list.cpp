// remove_nth_nodes_from_end_of_list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

// * Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
       if(head==NULL) return head;
        ListNode *new_head=new ListNode(0);
        new_head->next=head;
		head=new_head;
        ListNode *fast=head,*slow=head;
        
        for(int i=0;i<n;i++)
            {
            fast=fast->next;
        }
        while(fast->next!=NULL)
            {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *d=slow->next;
        slow->next=slow->next->next;
        delete d;
        return new_head->next;
    }
};

ListNode *l1, *ll1;  
int main() {  
    int n1;  
     
    cin >> n1;  
     ll1 = l1 = new ListNode(0); 
    for (int i = 0; i < n1; i++) {  
        l1->next = new ListNode(0);  
        l1 = l1->next; 
        scanf("%d", &(l1->val));
		 
    }  
  
   Solution ob;
   ListNode *r=ob.removeNthFromEnd (ll1->next,1);
	while (r != NULL) {  
        cout << r->val << ' ';  
        r = r->next;  
    } 
   system("pause");
    return 0;  
} 
