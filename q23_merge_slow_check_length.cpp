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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return NULL;
        int* sizelist= new int[size];
        for(int i=0;i<size;++i){
            if(!lists[i]) continue;
            sizelist[i]=1;
            ListNode* temp=lists[i];
            while(temp->next) {
                ++sizelist[i];
                temp=temp->next;
            }
        }
        while(true){
            int s1(-1),s2(-1),v1(INT_MAX),v2(INT_MAX);
            for(int i=0;i<size;++i){
                if (sizelist[i]==0) continue;
                if (v1>=sizelist[i]){
                    v2=v1;
                    s2=s1;
                    v1=sizelist[i];
                    s1=i;
                    continue;
                }
                if (v2>=sizelist[i]){
                    v2=sizelist[i];
                    s2=i;
                }
                
            }
            if(s2==-1) return lists[s1];
            lists[s1]=mergeTwoLists(lists[s1],lists[s2]);
            sizelist[s1]=v1+v2;
            sizelist[s2]=0;
        }
    }
};
