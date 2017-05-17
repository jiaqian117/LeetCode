// reorder_list.cpp : 定义控制台应用程序的入口点。
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
    void reorderList(ListNode *head) {
        if(head==NULL||head->next ==NULL)
			return;
		ListNode *fast=head,*slow=head;
		while(fast->next !=NULL&&fast->next ->next )
		{
			fast=fast->next ->next ;
			slow=slow->next ;
		}
		fast=slow->next ;
		slow->next =NULL;
		fast=ReverseList(fast);
		slow=head;
		while(slow)
		{
			if(fast!=NULL)
			{
				ListNode *l1=slow->next ;
				slow->next =fast;
				ListNode *l2=fast->next ;
				fast->next =l1;
				slow=l1;
				fast=l2;
			}
			else
				break;
		}

        
    }
    ListNode *ReverseList(ListNode *head)
        {
        if(head==NULL)
            return NULL;
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
	
	Solution ob;
	ob.reorderList (head->next);
	for(int i=0;i<n;++i)
	{
		cout<<head->next ->val <<" ";
		head=head->next ;
	}
	cout<<endl;
	
	system("pause");
	return 0;
}

