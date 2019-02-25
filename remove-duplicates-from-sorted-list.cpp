static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* current=head;
        while(current->next!=NULL){
            ListNode* next=findNextDifferentNode(current);
            deleteNodes(current,next);
            if(next==NULL) break;
            current=next;
        }
        return head;
    }
    
    ListNode* findNextDifferentNode(ListNode* head){
        int currentValue=head->val;
        while(head->next!=NULL&&head->next->val==currentValue) head=head->next;
        return head->next;
    }
    
    void deleteNodes(ListNode* begin,ListNode* end){
        begin->next=end;
    }
};
