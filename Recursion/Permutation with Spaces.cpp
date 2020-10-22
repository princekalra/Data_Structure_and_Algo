/*Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. Output should be printed in sorted increasing order of strings.

Input:  str[] = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Input:
First line contains the test cases T.  1<=T<=10
Each test case have one line string S of characters of length  N.  1<=N<=10

Output:
One line per test case, every string enclosed in ().(See example). Output should be printed in sorted order.

Example:
Input:
2
AB
ABC

Output:
(A B)(AB)
(A B C)(A BC)(AB C)(ABC)*/
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
void fun(string str,int i,string ans)
{
    if(i==str.length())
    {
        cout<<"(";
        cout<<ans<<")";
        return;
    }
    ans.push_back(' ');
    ans.push_back(str[i]);
    fun(str,i+1,ans);
    ans.pop_back();
    ans.pop_back();
    ans.push_back(str[i]);
    fun(str,i+1,ans);
    ans.pop_back();
}
int main()
{
//prince();
int t;
cin>>t;
while(t--)
{
    string str;
    cin>>str;
    string ans="";
    ans.push_back(str[0]);
    fun(str,1,ans);
    cout<<endl;
    
}

}
