/*
	Written By: Kshitij Kumar Sharma              Roll No: 1905514
	Question:
		Write a program to compute the nth Magic number (recursively) defined as below and find its time complexity (in terms of number of recursions).nth magic number MN(n) = MN(n-1) + MN(n-2), whereas MN(0) = 0, and MN(1) = 1.
		
	Idea of the solution:
		I am defining a fibo function for calculating the n th fibonachi series number recursively, and then applying the divide and conquer approach for finding the n th number.
*/
#include<bits/stdc++.h>

using namespace std;

int t=0;												//Variable for keeping no. of recursions
	
int fibo(int n,int a,int b,int c)						//function for calculating the n th fibonachi number.
	{
	t++;
	if(n==0)
		return a;
	if(n==1)
		return b;
	if(n==2)											//break condition of the recursion
		return c;	
	a=b;
	b=c;
	c=a+b;
	n--;
	fibo(n,a,b,c);										//recursively calling the fibo function with the updated value
	}
	
int main()
	{
	 int n,mn;
	 cout<<"Enter the position of the magic no : ";	
	 cin>>n;											//taking the n th number from user
	 if(n>=2)
	 	mn=fibo(n-1,0,1,1)+fibo(n-2,0,1,1);				//applying divide and conquer
	 cout<<"The magic no. is : "<<mn<<endl;
	 cout<<"No. of recursions : "<<t<<endl;
	}
