/*Flood fill Algorithm 
Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };

 x=4, y=4, color=3 

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1 <= T <= 100
1 <= M[][] <= 100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4*/
#include<bits/stdc++.h>
using namespace std;
int row[4]={1,-1,0,0};
int col[4]={0,0,1,-1};
 void fun(int matrix[102][102],int x,int y,vector< vector<bool> >&visited,int color,int k,int n,int m){
    //  cout<<color<<" "<<k<<" ";
     matrix[x][y]=k;
    //  cout<<k<<endl;
    //  cout<<x<<" "<<y<<" "<<matrix[x][y]<<endl;
    
     visited[x][y]=true;
     for(int kk=0;kk<4;kk++)
     {
         int newx=x+row[kk];
         int newy=y+col[kk];
         
         if(newx>=0&&newx<n&&newy>=0&&newy<m&&visited[newx][newy]==false)
         {
             if(matrix[newx][newy]==color)
             {
                 
                 fun(matrix,newx,newy,visited,color,k,n,m);
             }
         }
     }
     
 }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int matrix[102][102];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>matrix[i][j];
            }
        }
        int x,y,k;
        cin>>x>>y>>k;
      
        int color=matrix[x][y];
        vector< vector<bool> >visited(n, vector<bool>(m,false));
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        fun(matrix,x,y,visited,color,k,n,m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            //cout<<endl;
        }
        cout<<endl;
        
    }
}
