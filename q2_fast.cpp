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
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res=NULL,*cur=NULL;
        int val=0;
        int plus=0;
        
        if(l1==NULL){
            return l2;
        }else if (l2==NULL){
            return l1;
        }
        

        val+=l1->val;
        l1=l1->next;
        val+=l2->val;
        l2=l2->next;
        plus=val/10;
        val=val%10;
        res=new ListNode(val);
        cur=res;

        while(l1!=NULL||l2!=NULL){
            val=plus;
            if (l1!=NULL){
                val+=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL){
                val+=l2->val;
                l2=l2->next;
            }
            plus=val/10;
            val=val%10;
            cur->next=new ListNode(val);
            cur=cur->next;            
        }
        if(plus!=0){
            cur->next=new ListNode(plus);
        }
        return res;
    }
};
