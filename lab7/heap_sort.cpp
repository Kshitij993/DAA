#include <bits/stdc++.h>

using namespace std;

void heapify(int a[], int n, int i)
{
	int l,r,largest=i; 
	l=2*i+1; 
	r=2*i+2; 
	if (l<n&&a[l]>a[largest])
		largest=l;
	if (r<n&&a[r]>a[largest])
		largest=r;
	if (largest!=i) 
	{
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}
}
void heap_sort(int a[], int n)
{
	int i;
	for (i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for (i=n-1;i>0;i--) 
	{
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}
int main()
{
	int n,i,j,k,s[]={20000,50000,100000,500000};						
 	clock_t start, end;				
  	double cpu_time_used;		
	for(i=0;i<4;i++)
	 {
	 	cout<<endl;
	 	n=s[i];
	 	int a[n];
	 	srand(time(0));
	 	for(j=0;j<n;j++)
	 	 	a[j]=rand()%1000000;
	 	cout<<"For n= "<<n<<endl;
	 	start=clock();				
	 	heap_sort(a,n);
	 	end=clock();					
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC; 
	 	printf("Time taken for random : %fsec \n",cpu_time_used);

	 	sort(a,a+n);

	 	start=clock();			
	 	heap_sort(a,n);	
	 	end=clock();			

	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;	
	 	printf("Time taken for sorted : %fsec \n",cpu_time_used);
	 	
	 	sort(a,a+n,greater<int>());

	 	start=clock();			
	 	heap_sort(a,n);	
	 	end=clock();			
	 	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;	
	 	printf("Time taken for reverse sorted : %fsec \n",cpu_time_used);
	}
}
