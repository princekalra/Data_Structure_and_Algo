/*Add two numbers represented by Linked List 
Medium Accuracy: 53.44% Submissions: 4003 Points: 4
Given two numbers represented by two linked lists, write a function that returns Sum list. The sum list is linked list representation of addition of two input numbers.

Example 1:

Input:
S1 = 3, S2 = 3
ValueS1 = {2,3,4}
ValueS2 = {3,4,5}
Output: 5 7 9
Explanation: After adding the 2 numbers
the resultant number is 5 7 9.
Example 2:

Input:
S1 = 1, S2 = 2
ValueS1 = {9}
ValueS2 = {8,7}
Output: 9 6
Explanation: Add 9 and 7 we get 16.
1 is carry here and is added to 8.
So the answer is 9 6
Your Task:
The task is to complete the function addSameSize() addCarryToRemaining().

Constraints:
1 <= S1, S2 <= 100*/

#include<bits/stdc++.h>
//User function Template for C++

Node* addSameSize(Node* head1, Node* head2, int* carry) 
{ 
//     stack<int>st1;
//     stack<int>st2;
   
//     while(head1!=NULL)
//     {
//          st1.push(head1->data);
//     st2.push(head2->data);
//     head1=head1->next;
//     head2=head2->next;
//     }
   
//     Node*prev=(struct Node*)malloc(sizeof(struct Node));
//   prev=NULL;
//   Node*head;
//     while(st1.empty()==false)
//     {
//         Node*nde=new Node(0);
//         nde->data=(st1.top()+st2.top()+*carry)%10;
//         *carry=(st1.top()+st2.top()+*carry)/10;
//         st1.pop();
//         st2.pop();
//         nde->next=prev;
//         prev=nde;
//         head=nde;
//     }
    
//   return head;
if(head1==NULL)
{
    return NULL;
}
Node* node=new Node(0);
node->next=addSameSize(head1->next, head2->next, carry) ;
node->data=(head1->data+head2->data+*carry)%10;
*carry=(head1->data+head2->data+*carry)/10;
return node;
} 

void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) 
{ 
//     stack<int>st;
//     Node*ptr=head1;
//     int size=0;
//     while(ptr!=NULL)
//     {
//       size++;
//       ptr=ptr->next;
//     }
//     ptr=curr;
    
//       while(ptr!=NULL)
//     {
//       size--;
//       ptr=ptr->next;
//     }
//     while(size!=0)
//     {
//         st.push(head1->data);
//         size--;
//         head1=head1->next;
//     }
//     // cout<<st.top()<<endl;
//     Node *prev=*result;
//     while(st.empty()==false)
//     {
//         Node* nde=new Node(0);
//         nde->data=(st.top()+*carry)%10;
//         *carry=(st.top()+*carry)/10;
//         st.pop();
//         nde->next=prev;
//         prev=nde;
        
//     }
//   *result=prev;
if(head1!=curr)
{
    addCarryToRemaining(head1->next, curr,  carry, result);
    int sum=(*carry+head1->data)%10;
    *carry=(*carry+head1->data)/10;
   Node *node=new Node(sum);
   node->next=*result;
   *result=node;
}

}
