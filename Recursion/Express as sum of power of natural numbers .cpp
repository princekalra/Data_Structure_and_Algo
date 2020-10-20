/*
Given two numbers X and N, find out the total number of ways X can be expressed as sum of Nth power of unique natural numbers.

Examples:

Input  : X = 10, N = 2
Output : 1
Explanation: 10 = 12 + 32, 
Hence total 1 possibility

Input  : X = 100, N = 2
Output : 3
Explanation: 100 = 102
             OR 62 + 82
             OR 12 + 32 + 42 + 52 + 72
Hence total 3 possibilities

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a single line containing two space seperated integers denoting the values of X and N respectively.

Output:
For each test case output a new line containing a single integer denoting the total number of ways X can be expressed as sum of Nth power of unique natural numbers.

Constraints:
1 <= T <= 100
1 <= X <= 103
1 <= N <= 5

Example:
Input:
2
10 2
100 2
Output:
1
3
*/
#include<bits/stdc++.h>
// using namespace std;

// void fun(int x,int n,int&count,int start,int sum)
// {
//   int p=pow(start,n);
//   while(p+sum<x)
//   {
//       fun(x,n,count,start+1,p+sum);
//       start++;
//       p=pow(start,n);
      
//   }
//   if(p+sum==x)
//   {
//       count++;
//       return;
//   }
// }
// int main() {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int x,n;
//         cin>>x>>n;
//         int count=0;
//         fun(x,n,count,1,0);
//         cout<<count<<endl;
//     }
// 	//code
// 	return 0;
// }
using namespace std;

void fun(int x,int n,int&count,int start,int sum)
{
    if(x==0)
    {
        count++;
        return;
    }
   
    for(int i=start;pow(i,n)<=x;i++)
    {
       // cout<<"1";
        fun(x-pow(i,n),n,count,i+1,sum+pow(i,n));
    }
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int x,n;
        cin>>x>>n;
        int count=0;
        fun(x,n,count,1,0);
        cout<<count<<endl;
    }
	//code
	return 0;
}