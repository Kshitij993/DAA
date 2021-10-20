#include <bits/stdc++.h>
using namespace std;
int dp[100][100],a[100][100];

void optimalParents(int i,int j)
{
	if(i==j)
		cout<<"A"<<i;
	else
		{
			cout<<"(";
			optimalParents(i,a[i][j]);
			optimalParents(a[i][j]+1,j);
			cout<<")";
		}
}

int matrixChain(int* p, int i, int j)
{
	int q;
	if(i==j)
		return 0;
	
	if (dp[i][j] != -1)
		return dp[i][j];
	
	dp[i][j]=INT_MAX;
	for (int k=i;k<j;k++)
	{
		q=matrixChain(p,i,k)+matrixChain(p,k+1,j)+p[i-1]*p[k]*p[j];
		if(q<dp[i][j])
		{
			dp[i][j]=q;
			a[i][j]=k;
		}
	}
	cout<<dp[i][j]<<endl;
	return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
	int i=1,j=n-1;
	return matrixChain(p,i,j);
}


int main()
{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	memset(dp, -1, sizeof dp);
	memset(a, -1, sizeof a);
	int s=MatrixChainOrder(arr, n);
	cout<<endl;
	optimalParents(1,n-1);
	cout<<endl;
	cout << "Minimum number of multiplications is "<< s<<endl;
}
