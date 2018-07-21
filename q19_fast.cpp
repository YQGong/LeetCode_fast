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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next==NULL) return NULL;
        ListNode* nodet=head,nextnode=NULL;
        int size(1);
        while((nodet=nodet->next)!=NULL){
            ++size;
        }
        nodet=head;
        if (0>size-n-1) return head->next;
        for(int i=0;i<size-n-1;++i) nodet=nodet->next;
        nodet->next=(nodet->next)->next;
        return head;
    }
};
