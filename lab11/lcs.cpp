#include<bits/stdc++.h>
using namespace std;
int b[40][40];
void print_lcs(string x,int i,int j)
{
	if(i==0 || j==0)
		return;
	if(b[i][j]==1)
	{
		print_lcs(x,i-1,j-1);
		cout<<x[i];
	}
	else if(b[i][j]==2)
		print_lcs(x,i-1,j);
	else
		print_lcs(x,i,j-1);
		
}
void lcs_length(string x, string y)
{
	int m=x.length();
	int n=y.length();
	int c[m][n],i,j;
	for(i=0;i<m;i++)
		c[i][0]=0;
	for(j=0;j<n;j++)
		c[0][j]=0;
	for(i=1;i<m;i++)
	{
		for(j=1;j<n;j++)
		{
			if(x[i]==y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
	}
	cout<<"LCS length = "<<c[m-1][n-1]<<endl;
	print_lcs(x,m-1,n-1);
	cout<<endl;
}
int main()
{
	string s1,s2;
	cout<<"Enter 1st string : ";
	cin>>s1;
	cout<<"Enter 2nd string : ";
	cin>>s2;
	lcs_length(s1,s2);
}
