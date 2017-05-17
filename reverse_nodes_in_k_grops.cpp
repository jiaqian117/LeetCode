// reverse_nodes_in_k_grops.cpp : 定义控制台应用程序的入口点。
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
    ListNode *reverseKGroup(ListNode *head, int k) {
       if((head==NULL&&head->next==NULL)||k==1)
            return head;
        ListNode *p=head;
        int n=0;
        while(p)
            {
            n++;
            p=p->next;
        }
        int num=n/k;
        
        ListNode *preheader=new ListNode(0);
        preheader->next=head;
        ListNode *pre=preheader,*cur=preheader,*nex;
        while(num--)
            {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
        }
        return preheader->next;
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
   ListNode *r=ob.reverseKGroup (ll1->next,2);
	while (r != NULL) {  
        cout << r->val << ' ';  
        r = r->next;  
    } 
   system("pause");
    return 0;  
} 
