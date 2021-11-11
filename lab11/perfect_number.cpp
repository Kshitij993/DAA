#include<bits/stdc++.h>
using namespace std;
int perfect(int n)
{
    int sum=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i!=n)
                sum=sum+i+n/i;
            else
                sum=sum+i;
        }
    }
     if(sum==n&&n!=1)
          return 1;
     return 0;
}
int main()
{
	int c=0,i=2;
	while(c<4)
	{
		if(perfect(i))
		{
			cout<<i<<endl;
			c++;
			i++;
		}
		else
			i++;
	}
}
