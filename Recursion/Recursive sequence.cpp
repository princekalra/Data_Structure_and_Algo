/*A function f is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... n. Given an integer n the task is to print the F(n)th term.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test contains an integer n.

Output:
For each test case print the nth term of the sequence. .

Constraints:
1 <= T <= 10
1 <= N <= 10

Example:
Input:
2
5
7
Output:
365527
6006997207*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll fun(ll n,ll i,ll count)
{
    if(i>n)
    {
        return 0;
    }
   ll temp=i;
   ll ans=1;
   while(temp!=0)
   {
       ans*=count;
       temp--;
       count++;
   }
   i++;
   ans+=fun(n,i,count);
   return ans;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
        ll res=fun(n,1LL,1LL);
        cout<<res<<endl;
    }
}
