// add_two_numbers.cpp : 定义控制台应用程序的入口点。
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
       if(l1==NULL&&l2==NULL) return NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *res=new ListNode(0);
        ListNode *run=res;
        int yushu=0;
        ListNode *ll1=l1,*ll2=l2;
        while(ll1&&ll2)
            {
            run->next=new ListNode(0);
            int temp=ll1->val+ll2->val+yushu;
            
            run->next->val=temp%10;
            yushu=temp/10;
            
            run=run->next;
            ll1=ll1->next;
            ll2=ll2->next;
                
            
        }
        
        while (ll1)
		{

            run->next=new ListNode(0);
            int temp=ll1->val+yushu;
            
            run->next->val=temp%10;
            yushu=temp/10;
            
            run=run->next;
            ll1=ll1->next;
		}
        while(ll2)
		{
            run->next=new ListNode(0);
            int temp=ll2->val+yushu;
            
            run->next->val=temp%10;
            yushu=temp/10;
            
            run=run->next;
            ll2=ll2->next;
		}
       
		if(ll1==NULL&&ll2==NULL&&yushu!=0)
            {
            run->next=new ListNode(0);
            run->next->val=yushu;
        }
		 return res->next;
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
	Solution ob;
	ListNode *r=ob.addTwoNumbers (ll1->next , ll2->next);
	while (r != NULL) {  
        cout << r->val << ' ';  
        r = r->next;  
    } 
	system("pause");
	return 0;
}

