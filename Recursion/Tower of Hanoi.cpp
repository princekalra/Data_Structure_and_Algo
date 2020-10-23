// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// string str[4]={"##","rod 1","rod 2","rod 3"};
// int solve(int s,int d,int h,int n,int &count)
// {
//     if(n==1)
//     {
//         count++;
//         cout<<"move disk 1 from "<<str[s]<<" to "<<str[d]<<endl;
//         return count;
//     }
//     solve(s,h,d,n-1,count);
//     cout<<"move disk "<<n<<" from "<<str[s]<<" to "<<str[d]<<endl;
//     solve(h,d,s,n-1,count);
//     count++;
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         int count=0;
//         solve(1,3,2,n,count);
//         cout<<count<<endl;
        
//     }
// }
/*Tower of Hanoi 
Basic Accuracy: 43.6% Submissions: 12968 Points: 1
The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.
Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.

Input:
The first line of input is T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.

Output:
For each testcase, print the steps and the total steps taken. Please see the example output to see the steps format.

Constraints:
1 <= T <= 16
1 <= N <= 16

Example:
Input:
2
2
3
Output:
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3
3
move disk 1 from rod 1 to rod 3
move disk 2 from rod 1 to rod 2
move disk 1 from rod 3 to rod 2
move disk 3 from rod 1 to rod 3
move disk 1 from rod 2 to rod 1
move disk 2 from rod 2 to rod 3
move disk 1 from rod 1 to rod 3
7*/
#include<bits/stdc++.h>
using namespace std;
void fun(string &src,string &dest,string &help,int n,int &count)
{
    if(n==1)
    {
        count++;
        cout<<"move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    fun(src,help,dest,n-1,count);
         cout<<"move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
         fun(help,dest,src,n-1,count);
         count++;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string src="rod 1";
        string dest="rod 3";
        string help="rod 2";
        int count=0;
        fun(src,dest,help,n,count);
        cout<<count<<endl;
    }
}
