// median_of_two_sorted_array.cpp : 定义控制台应用程序的入口点。
//题目描述：
//There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).


#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

 //* Definition for singly-linked list.
/*  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        
        int num=m+n;
       
        ListNode *head,*l1;
	head=l1=new ListNode(0);
	for(int i=0;i<m;++i)
	{
		
		l1->next=new ListNode(0);
		
		
		l1=l1->next;
		l1->val =A[i];
	}
        ListNode *head1,*l2;
	head1=l2=new ListNode(0);
	for(int i=0;i<n;++i)
	{
		
		l2->next=new ListNode(0);
		
		
		l2=l2->next;
		l2->val =B[i];
	}
        ListNode *res=merge(head->next,head1->next );
        ListNode *fast=res,*slow=res;
        int n2=num/2;
        if(num%2==1)
            {
            while(n2)
                {
                fast=fast->next;
                n2--;
            }
            return fast->val;
        }
        else
            {
            while(n2)
                {
                slow=slow->next;
                n2--;
            }
            return (slow->val + slow->next->val)/2;
        }
    }
    ListNode *merge(ListNode *l1,ListNode *l2)
        {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *res,*temp;
        if(l1->val <= l2->val)
            {
            res=temp=l1;
            l1=l1->next;
        }
        else{
            res=temp=l2;
            l2=l2->next;
        }
        while(l1!=NULL&&l2!=NULL)
            {
            if(l1->val <= l2->val)
                {
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1!=NULL)
            temp->next=l1;
        if(l2!=NULL)
            temp->next=l2;
        return res;
    }
};
*/
/*class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int *res=new int[m+n];
        int i=0,j=0,k=0;
        while(i<m&&j<n)
            {
            if(A[i]<B[j])
                res[k++]=A[i++];
            else
                res[k++]=B[j++];
        }
        if(i!=m)
            while(i<m)
                res[k++]=A[i++];
        if(j!=n)
            while(j<n)
                res[k++]=B[j++];
        if((m+n)%2)
            return res[(m+n)/2]*1.0;
        else
            return (res[(m+n)/2-1]+res[(m+n)/2])*0.5;
    delete []res;
    }
};
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size();
        int n=nums2.size();
		vector<int> res(m+n,0);
        int i=0,j=0,k=0;
        while(i<m&&j<n)
        {
            if(nums1[i]<nums2[j])
			{
               res[k]=nums1[i];
			   k++;
			   i++;
			}
            else
			{
               res[k]=nums2[j];
			   k++;
			   j++;
			}

        }
        if(i!=m)
          while(i<m)
		  {

             res[k]=nums1[i];
			 k++;
			 i++;
		  }
             
        if(j!=n)
           while(j<n)
		   {

             res[k]=nums2[j];
			 k++;
			 j++;
		   }
        if((m+n)%2)
          return res[(m+n)/2]*1.0;
        else
          return (res[(m+n)/2-1]+res[(m+n)/2])*0.5;
    }
};
int main()
{
	/*int a[5]={1,2,3,5,7},b[4]={3,4,7,9};
	Solution ob;
	double res=ob.findMedianSortedArrays (a,5,b,4);
	*/
	int a[5]={1,2,3,5,7},b[4]={3,4,7,9};
	vector<int> A(a,a+5),B(b,b+4);
	vector<int> r(4,0);
	cout<<r[2]<<endl;
	
	Solution ob;
	double res=ob.findMedianSortedArrays (A,B);

	cout<<res<<endl;
	
	system("pause");
	return 0;
}

