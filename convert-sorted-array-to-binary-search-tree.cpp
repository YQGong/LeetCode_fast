//if (low>high)条件中多写了等号
//粗心把(high+low)/2写成了减号

static int turbo = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,(int)nums.size()-1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums,int low,int high){
        if (low>high) return NULL;
        TreeNode* root=new TreeNode(nums[(high+low)/2]);
        //root->val=nums[(high-low)/2];
        root->left=sortedArrayToBST(nums,low,(high+low)/2-1);
        root->right=sortedArrayToBST(nums,(high+low)/2+1,high);
        return root;
    }
};
