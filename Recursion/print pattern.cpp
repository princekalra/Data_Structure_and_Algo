/*
Print a sequence of numbers starting with N, without using loop, in which  A[i+1] = A[i] - 5,  if  A[i]>0, else A[i+1]=A[i] + 5  repeat it until A[i]=N.

Input:
The first line contains an integer T, number of test cases. Then following T lines contains an integer N.

Output:
For each test case, print the pattern in newline with space separated integers.

Constraints:
0< N < 10000

Example:
Input:
2
16
10
Output:
16 11 6 1 -4 1 6 11 16
10 5 0 5 10

Explanation:
We basically first reduce 5 one by one until we reach a negative or 0. After we reach 0 or negative, we one by one add 5 until we reach N.*/
#include<bits/stdc++.h>
#define f(a,b,c) for(ll a=b;a<c;a++)
typedef long long ll;
using namespace std;
void prince()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
}
void fun(int n,bool key,int start)
{
   
    if(key==true&&start==n)
    {
         //cout<<key<<" ";
        cout<<start<<" ";
        return;
        }
        if(start<=0)
    {
        cout<<start<<" ";
        key=true;
    }
    else
    {
      cout<<start<<" ";   
    }
       
        if(key)
    {
        start+=5;
    }
    else
    {
        start-=5;
    }
    fun(n,key,start);
}
int main()
{
//prince();
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    bool key=false;
    fun(n,key,n);
    cout<<endl;
}

  
}
