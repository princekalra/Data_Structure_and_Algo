/*Print N-bit binary numbers having more 1s than 0s 
Medium Accuracy: 42.45% Submissions: 311 Points: 4
Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

Example 1:

Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's
Example 2:

Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's
User Task:
Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of strings in decreasing order. You need not take any input or print anything.

Expected Time Complexity: O(|2N|)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 20*/
class Solution{
public:	
void fun(int count,int N,string str,vector<string>&s)
{
    if(str.length()==N)
    {
       // cout<<count<<endl;
        s.push_back(str);
        return;
    }
    
         str.push_back('1');
    fun(count+1,N,str,s);
    str.pop_back();
     if(count>(str.length())/2)
    {
           str.push_back('0');
    fun(count,N,str,s);
    
    }
 
}
	vector<string> NBitBinary(int N)
	{
	    vector<string>s;
	    int count=0;
	    string str="";
	    fun(count,N,str,s);
	    return s;
	    
	}
};