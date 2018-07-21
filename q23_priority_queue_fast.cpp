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
        ListNode* r=new ListNode(0),*end=r;
        priority_queue<pair<ListNode*,int>,vector<pair<ListNode*,int>>,cmp> heap;
        for(int i=0;i<lists.size();++i){
            if(lists[i]){
                heap.push({lists[i],i});
                lists[i]=lists[i]->next;
            }
        }
        while(!heap.empty()){
            pair<ListNode*,int> temp;
            temp=heap.top();
            heap.pop();
            end->next=temp.first;
            end=temp.first;
            if(lists[temp.second]){
                heap.push({lists[temp.second],temp.second});
                lists[temp.second]=lists[temp.second]->next;
            }
        }
        //ListNode* clean=r;
        //r=r->next;
        //delete clean;
        return r->next;
        
    }
    
    struct cmp{
        bool operator()(pair<ListNode*,int> a,pair<ListNode*,int> b){
            return a.first->val>b.first->val;
        }
    };
};
