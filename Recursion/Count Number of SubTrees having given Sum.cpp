/*
Count Number of SubTrees having given Sum 
Medium Accuracy: 50.13% Submissions: 18744 Points: 4
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
Example: For the tree given below:            

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Example 1:

Input:
       5
    /    \
  -10     3
 /   \   /  \
 9   8 -4    7
X = 7
Output: 2
Explanation: Subtrees with sum 7 are
[9, 8, -10] and [7] (refer the example
in the problem description).
Example 2:

Input:
    1
  /  \
 2    3
X = 5
Output: 0
Explanation: No subtree has sum equal
to 5.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countSubtreesWithSumX() which takes the root node and an integer X as inputs and returns the number of subtrees of the given Binary Tree having sum exactly equal to X.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 103
-103 <= Node Value <= 103
 

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.*/
void fun(Node *root,int X,int &count,int &sum)
{
    if(root==NULL)
    {
        return ;
    }
    int sumL=0;
    int sumR=0;
    fun(root->left,X,count,sumL);
    fun(root->right,X,count,sumR);
    sum=sumL+sumR+root->data;
   // cout<<sum<<endl;
    if(sum==X)
    {
        count++;
    }
}
int countSubtreesWithSumX(Node* root, int X)
{
    int count=0;
    int sum=0;
    fun(root,X,count,sum);
    return count;
	// Code here
}
