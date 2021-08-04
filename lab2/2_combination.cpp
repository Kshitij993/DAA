/*
Written by: Kshitij Kumar Sharma     Roll No.: 1905514

Question: 
	Given key for a stored array A with distinct values. write a program
	to find i,j,k such that a[i]+a[j]+a[k]=key.

Idea of the Solution:
	I have a loop form the first element to the third last element, in that
	loop an another loop from the next element to the second last element,
	again in that loop an another loop from the next element to the last element 
	in that loop cheching for a[i]+a[j]+a[k]=key, if found printing the reasult
*/

#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

void sum3num(int a_514[],int n_514,int key_514)							//function to find the triplet
	{
	 	int i_514,j_514,k_514;
	 	for(i_514=0;i_514<n_514-2;i_514++)
	 	{
	 		for(j_514=i_514+1;j_514<n_514-1;j_514++)
	 		{
	 			for(k_514=j_514+1;k_514<n_514;k_514++)
	 			{
	 				if(a_514[i_514]+a_514[j_514]+a_514[k_514]==key_514)	//checking the triplet condition
	 					cout<<"Triplet forming index are "<<i_514<<", "<<j_514<<", "<<k_514<<endl;			
	 			}
	 		}
	 	}
	}
	 						
int main()
	{
		int n_514;
		cout<<"Enter size of the array : ";		
		cin>>n_514;														//taking array size						
		int a_514[n_514],p_514;
		cout<<"Enter array element : \n";
		for(p_514=0;p_514<n_514;p_514++)
			cin>>a_514[p_514];											//taking the array 
		int key_514;																	
		cout<<"Enter the key : ";
		cin>>key_514;													//taking the key
		sum3num(a_514,n_514,key_514);									//calling the function sum3num
		return 0;
	}
