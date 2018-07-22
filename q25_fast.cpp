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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode** pv=new ListNode*[k];
        ListNode* r=new ListNode(0),* end=r;
        ListNode* start=head;
        if(!head) return head;
        
        while(start){
            
        pv[0]=start;
        int len(k);
        for(int i=1;i<k;++i) {
            if(pv[i-1]->next) {
                pv[i]=pv[i-1]->next;
                continue;
            }
            len=i;
            break;
        }
            if(len==k){
                start=pv[len-1]->next;
        
                for(int i=0;i<len;++i) {
                    end->next=pv[len-1-i];
                    end=end->next;
                }
                continue;
            }
            break;
        }
        end->next=start;
            
        return r->next;
    }
};
