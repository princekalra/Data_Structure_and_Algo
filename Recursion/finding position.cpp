/*Some people are standing in a queue. A selection process follows a rule where people standing on even positions are selected. Of the selected people a queue is formed and again out of these only people on even position are selected. This continues until we are left with one person. Find out the position of that person in the original queue.

Input:
The first line of input contains an integer T denoting the number of test cases.The first line of each test case is N,number of people standing in a queue.

Output:
Print the position(original queue) of that person who is left.

Constraints:
1 <= T <= 103
1 <= N <= 108

Example:
Input:
2
5
9
Output:
4
8*/
// MATHEMATICAL APPROACH
#include<bits/stdc++.h>
using namespace std;
int pow(int n,int x)
{
    if(x==0)
    {
        return 1;
    }
    if(x==1)
    {
        return n;
    }
    int temp=pow(n,x/2);
    temp=temp*temp;
    if(x%2==0)
    {
        return temp;
    }
    else
    {
        return n*temp;
    }
}
void fun(int n,int &ans,int i)
{
    if(pow(2,i)<n)
    {
        ans=pow(2,i);
    }
    else
    {
        return;
    }
    fun(n,ans,i+1);
}
int main() {
	//code
	int power[40];
	power[0]=1;
	for(int i=1;i<=40;i++)
	{
	    power[i]=power[i-1]*2;
	}
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	   
	    int i=1;
	    int ans=0;
	    fun(n,ans,1);
	   // while(power[i]<=n)
	   // {
	   //     ans=power[i];
	   //     i++;
	   // }
	    cout<<ans<<endl;
	}
	
	return 0;

}
