// reverse_list_2.cpp : 定义控制台应用程序的入口点。
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||head->next==NULL)
        return head;
        int num=0;
        
        ListNode *rhead=reverseList(head);
        ListNode *fast1=head,*slow1=head,*fast2=rhead,*slow2=rhead,*len=head;
        while(len->next)
        {
            len=len->next;
            num++;
        }
        
        while(m-1>0)
        {
            slow1=slow1->next;
            m--;
        }
        while(n>0)
        {
            fast1=fast1->next;
            n--;
        }
        int l=num-n;
        int h=num-m;
        while(l>0)
        {
            slow2=slow2->next;
            l--;
        }
        while(h>0)
        {
            fast2=fast2->next;
            h--;
        }
        slow1->next=slow2;
        fast2->next=fast1;
        return head;
    }
    ListNode *reverseList(ListNode *head){
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *res=NULL;
        while(head)
            {
            ListNode *temp=head->next;
            head->next=res;
            res=head;
            head=temp;
        }
        return res;
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
	int i,j;
	cin>>i>>j;
	Solution ob;
	ListNode *res=ob.reverseBetween (head->next ,i,j);
	for(int i=0;i<n;++i)
	{
		cout<<res ->val <<" ";
		res=res->next ;
	}
	cout<<endl;
	system("pause");
	return 0;
}

