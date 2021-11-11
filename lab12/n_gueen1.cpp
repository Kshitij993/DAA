#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;

int N;
char mat[10][10];
int isSafe(int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (mat[i][c] == 'Q') 
        {
            return 0;
        }
    }
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 'Q') 
        {
            return 0;
        }
    }
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
    {
        if (mat[i][j] == 'Q') 
        {
            return 0;
        }
    }
    return 1;
}
void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
} 
void nQueen(int r)
{
    if (r == N)
    {
        printSolution();
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(r, i))
        {
            mat[r][i] = 'Q';
            nQueen(r + 1);
            mat[r][i] = '-';
        }
    }
}
int main()
{
    cout<<"Enter the no of queen : ";
    cin>>N;
    char mat[N][N];
    memset(mat, '-', sizeof mat);
    nQueen(0);
    return 0;
}

