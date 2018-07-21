/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* p1=head,* p2=p1->next,*r=p2;
        if(p2->next==NULL||p2->next->next==NULL) {
            p1->next=p2->next;
            p2->next=p1;
            return r;
        }
        while(p2->next&&(p2->next)->next){
            ListNode* p3=p2->next,*p4=p3->next;
            p1->next=p4;
            p2->next=p1;
            p1=p3;
            p2=p4;
        }
        p1->next=p2->next;
        p2->next=p1;
        return r;
    }
};
