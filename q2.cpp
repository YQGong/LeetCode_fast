/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode start(0);
        ListNode* r=&start;
        ListNode* p1=l1;
        ListNode* p2=l2;
        int next(0),carry(0);
        while(p1!=NULL||p2!=NULL){
            int n1=(p1==NULL?0:p1->val);
            int n2=(p2==NULL?0:p2->val);
            next=n1+n2+carry;
            r->next=new ListNode(next%10);
            carry=next/10;
            r=r->next;
            p1=(p1==NULL?p1:p1->next);
            p2=(p2==NULL?p2:p2->next);
        }
        if(carry==1){
            r->next=new ListNode(1);
        }
        return(start.next);
    }
};
