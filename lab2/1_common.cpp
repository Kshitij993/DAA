/*
Written by: Kshitij Kumar Sharma     Roll No.: 1905514

Question: 
	Given an array, let us assume that there can be duplicates in the list.
	write a program to search for an element in the list in such a way that
	we get the highest intdex if there are duplicates.

Idea of the Solution:
	I took one element from the list and then initialize a counter to 
	zero then compare with all the elements of the list if it matches then
	increment the counter and store the position. if the counter is grater
	than 1 then it means there is a duplicate element in the list, so print
	the print the element and its highest stored position.
*/
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;
int main()
	{
		int n_514,i_514,j_514;
		cout<<"Enter a size of the array : ";
		cin>>n_514;														//Taking size of the array
		int a_514[n_514],c_514=0,pos_514;
		cout<<"Enter array elements : \n";
		for(i_514=0;i_514<n_514;i_514++)
			cin>>a_514[i_514];											//Taking array elements
		for(i_514=0;i_514<n_514;i_514++)
		{
			c_514=0;													//Counter to count duplicates
			for(j_514=0;j_514<n_514;j_514++)
			{
				if(a_514[i_514]==a_514[j_514])							//Checking for duplicates
				{
					c_514++;											//Incrementing counter 
					pos_514=j_514;										//Capturing the position
				}
			}
			if(c_514>1 && i_514==pos_514)								// c>1 to check for duplicate element and i==pos for printing one time for all duplicates.
				cout<<"Repeted element : "<<a_514[i_514]<<" Highest index : "<<pos_514<<endl;
		}
		return 0;
	}
