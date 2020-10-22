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
void fun(string str,int start)
{
    if(start==str.length())
    {
        cout<<str<<" ";
        return;
    }
    for(int i=start;i<str.length();i++)
    {
 swap(str[start],str[i]);
    fun(str,start+1);
    swap(str[start],str[i]);
    }
   
}
int main()
{
prince();
int t;
cin>>t;
while(t--)
{
    string str;
    cin>>str;
    fun(str,0);
    cout<<endl;
}

}