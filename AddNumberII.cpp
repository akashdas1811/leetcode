/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr=head,*prev=NULL,*temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL and l2==NULL){
            return 0;
        }
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* h1=reverse(l1);
        ListNode* h2=reverse(l2);
        int temp1=(h1!=NULL)?h1->val:0;
        int temp2=(h2!=NULL)?h2->val:0;
        int sum=temp1+temp2;
        int carry=sum/10;
        ListNode* head=new ListNode(sum%10);;
        ListNode* a=h1->next,*b=h2->next,*curr=head;
        while(a!=NULL or b!=NULL){
            int t1=(a!=NULL)?a->val:0;
            int t2=(b!=NULL)?b->val:0;
            int s=t1+t2+carry;
            carry=s/10;
            curr->next=new ListNode(s%10);
            curr=curr->next;
            if(a!=NULL)
                a=a->next;
            if(b!=NULL)
                b=b->next;
        }
        if(carry>0){
            curr->next=new ListNode(carry);
        }
        ListNode* ans=reverse(head);
        return ans;
    }
};
