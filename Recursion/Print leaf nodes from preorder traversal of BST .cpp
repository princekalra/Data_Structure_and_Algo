/*Given a preorder traversal of a BST, print the leaf nodes of the tree without building the tree.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the no of nodes of the BST. Then in the next line are N space separated values denoting the preorder traversal of the binary tree.

Output:
For each test case in a new line print the leaf nodes separated by space of the BST in sorted order.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
5
890 325 290 530 965 
3
3 2 4

Output:
290 530 965
2 4

*/
#include<bits/stdc++.h>
using namespace std;
void fun(vector<int>&v,set<int>&st)
{
    if(v.size()==0)
    {
        return;
    }
    if(v.size()==1)
    {
      //  cout<<v[0]<<endl;
        st.insert(v[0]);
        return;
    }
    vector<int>left;
    vector<int>right;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<v[0])
        {
            left.push_back(v[i]);
        }
        else
        {
            right.push_back(v[i]);
        }
    }
    fun(left,st);
    fun(right,st);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        set<int>st;
        fun(v,st);
        for(auto x:st)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
     
}
