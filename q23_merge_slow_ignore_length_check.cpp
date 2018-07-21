/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static auto x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return NULL;
        while(size>1){
            for(int i=0;i<size/2;++i){
                lists[i]=mergeTwoLists(lists[i],lists[size-i-1]);
                --size;
            }
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode*head=NULL,*end=NULL;
        if(l1->val<l2->val) {
            head=l1;
            end=l1;
            l1=l1->next;
        } else {
            head=l2;
            end=l2;
            l2=l2->next;
        }
        while(l1&&l2){
            
        if(l1->val<l2->val) {
            end->next=l1;
            end=l1;
            l1=l1->next;
        } else {
            end->next=l2;
            end=l2;
            l2=l2->next;
        }
            
        }
        if(!l1){
            end->next=l2;
            return head;
        }
        end->next=l1;
        return head;
        
    }
};

