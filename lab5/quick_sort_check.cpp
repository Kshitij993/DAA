#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int a[10];
int partition(int p,int r)
	{
		int j,t,i=p-1;
		int pivot=a[r];
		
		for(j=p;j<=r-1;j++)
			{
				if(a[j]<=pivot)
					{
						i++;
						t=a[i];
						a[i]=a[j];
						a[j]=t;
					}
			}
			t=a[i+1];
			a[i+1]=a[r];
			a[r]=t;
			return i+1;
	}

void quick_sort(int p,int r)
	{
		int q;
		if(p<r)
			{
				q=partition(p,r);
				quick_sort(p,q-1);
				quick_sort(q+1,r);
			}
	}

int main()
	{
	 int i;
	 for(i=0;i<10;i++)
	 	cin>>a[i];
	 quick_sort(0,9);
	 for(i=0;i<10;i++)
	 	cout<<a[i]<<" ";
	 cout<<endl;
	}
