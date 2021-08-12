#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int partition(int a[],int p,int r)
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

void quick_sort(int a[],int p,int r)
	{
		int q;
		if(p<r)
			{
				q=partition(a,p,r);
				quick_sort(a,p,q-1);
				quick_sort(a,q+1,r);
			}
	}

int main()
	{
		int n,i,j,k;						
	 	clock_t start, end;				
    	double cpu_time_used;		
	 	for(i=0;i<4;i++)
	 	{
	 	cout<<endl;
	 	cout<<"Enter the size of the array : ";
	 	cin>>n;
	 	int a[n];
	 	srand(time(0));
	 	for(j=0;j<n;j++)
	 	 	a[j]=rand()%1000000;
	 	cout<<"For n= "<<n<<endl;
	 	start=clock();				
	 	quick_sort(a,0,n-1);
	 	end=clock();					
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC; 
	 	printf("Time taken for random : %fsec \n",cpu_time_used);

	 	sort(a,a+n);

	 	start=clock();			
	 	quick_sort(a,0,n-1);	
	 	end=clock();			

	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;	
	 	printf("Time taken for sorted : %fsec \n",cpu_time_used);
	 	
	 	sort(a,a+n,greater<int>());

	 	start=clock();			
	 	quick_sort(a,0,n-1);	
	 	end=clock();			
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;	
	 	printf("Time taken for reverse sorted : %fsec \n",cpu_time_used);
		}
	}
	
	
