#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r)
{
	if (l<r) 
	{
		int m=l+(r-l)/2;
		merge_sort(arr,l,m);
		merge_sort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
void merge(int arr[], int l, int m, int r)
{
	int i,j,k,n1,n2;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for (i=0;i<n1;i++)
		L[i]=arr[l+i];
	for (j=0;j<n2;j++)
		R[j]=arr[m+1+j];
	i=0; 
	j=0; 
	k=l; 
	while(i<n1&&j<n2) 
	{
		if (L[i]<=R[j]) 
		{
			arr[k]=L[i];
			i++;
		}
		else 
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2) 
	{
		arr[k]=R[j];
		j++;
		k++;
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
	 	merge_sort(a,0,n-1);								
	 	end=clock();								
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC; 
	 	printf("Time taken for random : %fsec \n",cpu_time_used);
	 	sort(a,a+n);
	 	
	 	start=clock();								
	 	merge_sort(a,0,n-1);								
	 	end=clock();								
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;	
	 	printf("Time taken for sorted : %fsec \n",cpu_time_used);
	 	
	 	sort(a,a+n,greater<int>());
	 	start=clock();								
	 	merge_sort(a,0,n-1);								
	 	end=clock();								
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;	
	 	printf("Time taken for reverse sorted : %fsec \n",cpu_time_used);
	 	}	 	 
	}
