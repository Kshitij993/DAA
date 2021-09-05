#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int n=10,a[10],f=0;

struct activity
{
	int id,start,end;
}s[10],t;

int partition(int p,int r)
	{
		int j,i=p-1;
		int pivot=s[r].end;
		
		for(j=p;j<=r-1;j++)
			{
				if(s[j].end<=pivot)
					{
						i++;
						t=s[i];
						s[i]=s[j];
						s[j]=t;
					}
			}
			t=s[i+1];
			s[i+1]=s[r];
			s[r]=t;
			return i+1;
	}
int random_partition(int p,int r)
	{
		srand(time(0));
		int i=(rand()%(r-p+1))+p;
		t=s[r];
		s[r]=s[i];
		s[i]=t;
		return partition(p,r);
	}
void random_quick_sort(int p,int r)
	{
		int q;
		if(p<r)
			{
				q=random_partition(p,r);
				random_quick_sort(p,q-1);
				random_quick_sort(q+1,r);
			}
	}
int pos(int a)
	{
		int i;
		for(i=0;i<n;i++)
			{
			if(a==s[i].id)
				return i;
			}
	}
void print()
	{
		int i;
		cout<<"<start, end> \n";
		for(i=0;i<n;i++)
			{
				cout<<"<"<<s[i].start<<", "<<s[i].end<<">"<<" ";
			}
		cout<<endl;
	}
void print(int c[],int n)
	{
		int i;
		cout<<"<start, end> \n";
		for(i=0;i<n;i++)
			{
				cout<<"<"<<s[pos(c[i])].start<<", "<<s[pos(c[i])].end<<">"<<" ";
			}
		cout<<endl;
	}
void activity_selector_recursive(int k)
	{
		int m=k+1;
		if(k==0)
			{
				a[f]=s[k].id;
				f++;
			}
		while(m<n && s[m].start<s[k].end)
			m++;
		if(m<n)
			{
				a[f]=s[m].id;
				f++;
				activity_selector_recursive(m);
			}
		else
			return;
	}
void activity_selector_iterative()
	{
		int i,b[n],z=0;
		b[z]=s[0].id;
		z++;
		int k=0;
		for(i=1;i<n;i++)
			{
			 	if(s[i].start >= s[k].end)	
			 		{
			 			b[z]=s[i].id;
			 			k=i;
			 			z++;
			 		}
			}
		print(b,z);
	}
int main()
	{
		int i,j;
		clock_t start,stop;
		double duration;
		srand(time(0));
		for(i=0;i<n;i++)
			{
			s[i].id=i+1;
			s[i].start=rand()%20;
			s[i].end=s[i].start+1+rand()%20;				
			}
		print();
		random_quick_sort(0,n-1);
		print();
		cout<<"Recursive \n";
		start=clock();
		activity_selector_recursive(0);
		print(a,f);
		stop=clock();
		duration=((double)(stop-start)/CLOCKS_PER_SEC);
		printf("time taken=%f sec\n",duration);
		cout<<"Iterative \n";
		start=clock();
		activity_selector_iterative();
		stop=clock();
		duration=((double)(stop-start)/CLOCKS_PER_SEC);
		printf("time taken=%f sec\n",duration);
	}
