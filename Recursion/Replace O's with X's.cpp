/*Given a matrix of size NxM where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.

Examples:

Input: mat[N][M] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'O', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
Output: mat[N][M] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'X', 'X', 'X'},
                      {'O', 'X', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'O', 'X', 'O'},
                      {'O', 'O', 'X', 'O', 'O', 'O'},
                    };

Input: mat[N][M] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'O', 'O', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };
Input: mat[N][M] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1<=T<=10
1<=mat[][]<=100
1<=n,m<=20

Example:
Input:
2
1 5
X O X O X 
3 3
X X X X O X X X X
Output:
X O X O X
X X X X X X X X X*/
#include<bits/stdc++.h>
using namespace std;
int col[4]={-1,1,0,0};
int row[4]={0,0,-1,1};
void fun(vector< vector<bool> >&visited,vector<pair<int,int> >&visited1,char matrix[1000][1000],int n,int m,int i,int j,bool &key)
{
    visited[i][j]=true;
  visited1.push_back(make_pair(i,j));
    for(int k=0;k<4;k++)
    {
         int newi=i+row[k];
        int newj=j+col[k];
        if(newi<n&&newj<m&&newi>=0&&newj>=0)
        { 
            if(!visited[newi][newj])
        {
            if(matrix[newi][newj]=='X')
            {
                
            }
            else
            {
                fun(visited,visited1,matrix,n,m,newi,newj,key);
               
            }
        }
        }
        else
        {
            key=false;
        }
        
       
    }
    if(key==true)
    {
         matrix[i][j]='X';
    }
   
  
    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    	int n,m;
	cin>>n>>m;
	char  matrix[1000][1000];
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	       cin>> matrix[i][j];
	    }
	}

	vector< vector<bool> >visited(n+1,vector<bool>(m+1,false));
// 	for(int i=0;i<n;i++)
// 	{
// 	    for(int j=0;j<m;j++)
// 	    {
// 	        cout<<matrix[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	        if(visited[i][j]==false&&matrix[i][j]!='X')
	        {
	            	bool key=true;
	            	vector< pair<int,int> >visited1;
	            	fun(visited,visited1,matrix,n,m,i,j,key);
	            	
	            	if(key==false)
	            	{
	            	   for(auto x:visited1)
	            	   {
	            	       matrix[x.first][x.second]='O';
	            	   }
	            	    
	            	    
	            	}
	        }
	    }
	}
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	        cout<<matrix[i][j]<<" ";
	    }
	  // cout<<endl;
	}
cout<<endl;
	}

	
	return 0;
}
