// rotate_list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL)
            return NULL;
        int n=1;
        ListNode *fast=head,*slow=head,*res;
       
        while(fast->next)
            {
            fast=fast->next;
            n++;
        }
         int m=n-k%n-1;
        
            
            while(m>0)
                {
                slow=slow->next;
               m--;
            }
            fast->next=head;
            head=slow->next;
            slow->next=NULL;   
            return head;
       
    
    }
};

int main()
{
	int n;
	ListNode *head,*l1;
	cin>>n;
	head=l1=new ListNode(0);
	for(int i=0;i<n;++i)
	{
		
		l1->next=new ListNode(0);
		
		
		l1=l1->next;
		scanf("%d", &(l1->val));
	}
	int m=0;
	ListNode *l=head;
	while(l->next )
	{
		m++;
		l=l->next;
	}
	cout<<m<<endl;

	Solution ob;
	ListNode *res=ob.rotateRight  (head->next,2);
	for(int i=0;i<n;++i)
	{
		cout<<res ->val <<" ";
		res=res->next ;
	}
	cout<<endl;
	
	system("pause");
	return 0;
}

