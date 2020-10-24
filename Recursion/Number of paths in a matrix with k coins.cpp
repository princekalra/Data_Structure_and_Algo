/*Number of paths in a matrix with k coins 
Medium Accuracy: 31.88% Submissions: 11021 Points: 4
Given a N x N matrix where every cell has some number of coins. Count number of ways to reach bottom right cell of matrix from top left cell with exactly K coins. We can move to (i+1, j) or (i, j+1) from a cell (i, j).

Input:
First line contains number of test cases T. For each test case, first line contains the integer value 'X' denoting coins, second line contains an integer 'N' denoting the order of square matrix. Last line contains N x N elements in a single line in row-major order.

Output:
Output the number of paths possible.

Constraints:
1 <=T<= 500
1 <= K <= 200
1 <= N <= 200
1 <= Ai <= 200

Example:
Input:
2
16
3
1 2 3 4 6 5 9 8 7
12
3
1 2 3 4 6 5 3 2 1

Output:
0
2

Explanation:
Testcase 2: There are 2 possible paths with exactly K coins, which are (1 + 4 + 3 + 2 + 1) and (1 + 2 + 3 + 5 + 1).*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll fun(ll n,vector< vector< vector<ll> > >&dp,ll count,ll i,ll j,vector< vector<ll> >&matrix)
{
    if(i<0||j<0||count<0)
    {
        return 0;
    }
    if(i==0&&j==0)
    {
        if(count==matrix[i][j])
        {
            return 1;
        }
        return 0;
    }
    if(dp[i][j][count]!=-1)
    {
        return dp[i][j][count];
    }
    return dp[i][j][count]=fun(n,dp,count-matrix[i][j],i-1,j,matrix)+fun(n,dp,count-matrix[i][j],i,j-1,matrix);
    
}
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
       ll coins;
        cin>>coins;
       ll n;
        cin>>n;
        vector< vector<ll> >matrix(n,vector<ll>(n,0));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cin>>matrix[i][j];
            }
        }
        vector< vector<vector<ll> > >dp(n, vector<vector<ll>>(n,vector<ll>(coins+1,-1)));
       ll count=0;
        fun(n,dp,coins,n-1,n-1,matrix);
        if(dp[n-1][n-1][coins]==-1)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<dp[n-1][n-1][coins]<<endl;
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         for(int k=0;k<=coins;k++)
        //         {
        //           cout<<dp[i][j][k]<<" ";   
        //         }
        //         cout<<"/";
               
        //     }
        //     cout<<endl;
        // }
     }
	//code
	return 0;
}
