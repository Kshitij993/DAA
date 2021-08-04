/*
Written by: Kshitij Kumar Sharma     Roll No.: 1905514

Question: 
	Suppose an array has distinct elements. increasing sequence is given as
	a[0]. . . a[k] and decreasing sequence is given as a[k+1] ... a[n-1].
	write a program to find k.

Idea of the Solution:
	Taking a loop from a[0] to a[n-1] and checking where a[i] is grater than
	a[i+1], if this condition satisfies then k=i.
*/
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int main()
	{
	 	int n_514;
	 	cout<<"Enter array size : ";
	 	cin>>n_514;										//taking size of the array
	 	int a_514[n_514],i_514;
	 	cout<<"Enter array element : \n";
	 	for(i_514=0;i_514<n_514;i_514++)
	 		cin>>a_514[i_514];							//taking array elements
	 	for(i_514=0;i_514<n_514;i_514++)
	 		{
	 			if(a_514[i_514]>a_514[i_514+1])			//checking weather the next element is smaller than the previous or not
	 				{
	 					cout<<"break point at index : "<<i_514;
	 					break;
	 				}
	 		}
	 	cout<<endl;
	 	return 0;
	 }
