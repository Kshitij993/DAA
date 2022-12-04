#include <bits/stdc++.h>

using namespace std;

void heapify(int a[], int n, int i)
{
	int l,r,min=i; 
	l=2*i+1; 
	r=2*i+2; 
	if (l<n&&a[l]<a[min])
		min=l;
	if (r<n&&a[r]<a[min])
		min=r;
	if (min!=i) 
	{
		int t=a[i];
		a[i]=a[min];
		a[min]=t;
		heapify(a,n,min);
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
void print(int a[], int n)
{
	for (int i=0;i<n;++i)
		cout<<a[i]<<" ";
	cout << "\n";
}

int main()
{
	int a[10],n,i;
	cout<<"Enter the no of elements : ";
	cin>>n;
	cout<<"Enter elements \n";
	for(i=0;i<n;i++)
		cin>>a[i];
	heap_sort(a, n);

	cout << "Sorted array is \n";
	print(a, n);
}
