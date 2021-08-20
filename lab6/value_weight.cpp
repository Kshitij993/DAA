#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

const int capacity=20;
int n=10;

struct item
	{
	int id,weight;
	float value,ratio;
	}s[10],t;
	
struct container
	{
	int id[10] ,weight;
	float value;
	};
/*
float random_float(float a, float b)
	{
	 float random=((float)rand())/(float)b;
    float diff=b-a;
    float r=random*diff;
    return a+r;
	}
*/
int partition(int p,int r)
	{
		int j,i=p-1;
		int pivot=s[r].ratio;
		
		for(j=p;j<=r-1;j++)
			{
				if(s[j].ratio>=pivot)
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
	for(i=0;i<n;i++)
		{
		 cout<<"<"<<s[i].weight<<", "<<s[i].value<<">"<<" ";
		}
	}
int main()
	{
		int i,j,added_weight=0;
		struct container p;
		clock_t start,end;
		double duration;
		p.weight=0;
		p.value=0;
		srand(time(0));
		for(i=0;i<n;i++)
			{
			s[i].id=i+1;
			s[i].weight=(rand()%(50-1+1))+1;
			s[i].value=(rand()%(10-1+1))+1;				//random_float(0.01,0.3);
			s[i].ratio= s[i].value/s[i].weight;
			}
		start=clock();
		cout<<"Items <weight, value> \n";
		print();
		cout<<endl;
		random_quick_sort(0,n-1);
		
		cout<<"\nSorted items according to ratio value/weight \n";
		print();
		cout<<endl;
		i=0;
		added_weight=s[0].weight;
		while(added_weight<=capacity)
			{
			p.id[i]=s[i].id;
			p.weight=p.weight+s[i].weight;
			p.value=p.value+s[i].value;
			i++;
			added_weight=added_weight+s[i].weight;
			}
		cout<<"\nItems in container \n";				
		for(j=0;j<i;j++)
			{
			 cout<<"<"<<s[pos(p.id[j])].weight<<", "<<s[pos(p.id[j])].value<<">"<<" ";
			}	
		cout<<"\n\nTotal container weight = "<<p.weight<<endl;
		cout<<"Value of Container = "<<p.value<<endl;
		end=clock();
		duration=(double(start-end))/CLOCKS_PER_SEC;
		printf("Time Taken = %f sec\n",duration);
	}


