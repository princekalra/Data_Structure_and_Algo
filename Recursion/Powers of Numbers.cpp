/*Given a number N, let the reverse of the number be R. The task is to print the output of the Expression pow(N,R), where pow function represents N raised to power R.
Note: As answers can be very large, print the result modulo 1000000007.

Input:
The first line of the input consists of an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing an integer N.

Output:
Corresponding to each test case, print in a new line, the output of the expression pow as described above.

Constraints:
1 <= T <= 103
1 <= N <= 1010

Example:
Input:
2
2
12

Output:
4
864354781

Explanation:
Testcase 1: The reverse of 2 is 2 and after raising power of 2 by 2 we get 4 which gives remainder as 4 by dividing 1000000007.*/
#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll rev(ll n)
{
   ll num=0;
    while(n!=0)
    {
        num=num*10;
        num+=(n%10);
        n/=10;
    }
    return num;
}
ll pow(ll n,ll r)
{
    if(r==0)
    {
        return 1;
    }
    if(r==1)
    {
        return n%mod;
    }
    ll temp=0;
    temp=pow(n,r/2);
    temp%=mod;
    temp=(temp*temp)%mod;
    if(r%2==0)
    {
        return temp;
    }
    else
    {
        temp=((temp%mod)*(n%mod))%mod;
        return temp;
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       ll n;
        cin>>n;
      ll r;
        r=rev(n);
     ll res=pow(n,r);
        cout<<res<<endl;
    }
}
