#include<bits/stdc++.h>
using namespace std;
int product(int x,int y)
{
	 if (x<y)
        return product(y,x);
    else if(y!=0)
        return(x+ product(x,y-1));
    else
        return 0;
}
int main()
{
	int n,i,p;
	cout<<"Enter the no of elments : ";
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++)
	{
		p=product(a[i],a[i+1]);
		a[i+1]=p;
	}
	cout<<p<<endl;
}	
