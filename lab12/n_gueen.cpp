#include<bits/stdc++.h>
#define n 6
using namespace std;

int ld[30] = { 0 };
int rd[30] = { 0 };
int cl[30] = { 0 };

void print(int board[n][n])
{
	int i,j;
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
}
int solve_n_queen(int board[n][n], int col)
{
	int i;
	if (col>=n)
		return 1;
	for(i=0;i<n;i++) 
	{
		if((ld[i-col+n-1]!=1&&rd[i+col]!=1)&&cl[i]!=1) 
		{
			board[i][col]=1;
			ld[i-col+n-1]=rd[i+col]=cl[i]=1;
			if (solve_n_queen(board, col+1))
				return 1;
			board[i][col]=0; 
			ld[i-col+n-1]=rd[i+col]=cl[i]=0;
		}
	}
	return 0;
}
void n_queen()
{
	int board[n][n];
	memset(board,0,sizeof(board));
	if (solve_n_queen(board, 0) == 0) 
	{
		printf("Solution does not exist");
		return;
	}
	print(board);
}
int main()
{
//	cout<<"Enter size of the Board : ";
//	cin>>n;
	n_queen();
}
