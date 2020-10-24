/*An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : "3[a3[b]1[ab]]".

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print the required decoded string.

Constraints:
1<=T<=10
1<=length of the string <=30

Example:
Input:
2
1[b]
3[b2[ca]]

Output:
b
bcacabcacabcaca*/
#include<bits/stdc++.h>
using namespace std;
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         string s;
//         cin>>s;
//         stack<char>st;
//         string ans="";
//          string str="";
//         for(int i=0;i<s.length();i++)
//         {
//             if(s[i]!=']')
//             {
//                 st.push(s[i]);
//             }
//             else
//             {
//                 while(st.top()!='[')
//                 {
//                     str.push_back(st.top());
//                     st.pop();
//                 }
//               //  cout<<str<<endl;
//                 st.pop();
//                 // cout<<st.top()<<endl;
//                 // cout<<ans<<endl;
//                 int count=st.top()-'0';
//                 st.pop();
               
//                 while(count--)
//                 {
//                   ans+=str;
//                 }
//                 // cout<<str<<endl;
//                 str=ans;
//               //cout<<ans<<endl;
//               ans="";
//                 //str="";
//             }
//         }
//         ans=str;
//         reverse(ans.begin(),ans.end());
//         cout<<ans<<endl;
//     }
// }
string fun(string str,int&start,stack<char>st,int &cnt)
{
//     cout<<"11";
//   // cout<<start<<endl;
//   cout<<start<<endl;
    string ans="";
    string num="";
    int i=start;
    
    while(i<str.length())
    {
      
        if(str[i]=='[')
        {
            stack<char>st;
            st.push('[');
            i+=1;
          string ss="";
            int j=i;
            int count=0;
            ss=fun(str,j,st,count);
            // cout<<count<<endl;
            i=count;
            //  cout<<ss<<"/"<<endl;
           string s="";
           int n=stoi(num); 
          // cout<<n<<endl;
            while(n!=0)
            {
                s+=ss;
                n--;
            }
            num="";
            //  cout<<s<<"/"<<endl;
            ans+=s;
            //  cout<<ans<<"//"<<endl;
            //  cout<<j<<endl;
           // cout<<s<<endl;
          // ans+=s;
           //return ans;
            
        }
        else
        {
           if(isalpha(str[i]))
           {
               // cout<<str[i]<<endl;
               ans+=str[i];
           }
           else if(str[i]==']')
           {
               st.pop();
               if(st.empty()){
            //   {cout<<ans<<endl;
            //   i++;cout<<"i"<<" "<<i<<endl;
            i++;
               cnt=i;
                   return ans;
               }
           }
           else
           {
              num+=str[i];
           }
            i+=1;
        }
       
    }
   // cout<<ans<<endl;
    return ans;
}
int main()
{
int t;
cin>>t;
while(t--)
{
    string str;
    cin>>str;
    // string str1="1[";
    string str1="";
    str1+=str;
    // str1+="]";
   // cout<<str1<<endl;
   stack<char>st;
  
    int i=0;
    string an="";
    int cnt=0;
    an=fun(str1,i,st,cnt);
    cout<<an<<endl;
    
}
}
