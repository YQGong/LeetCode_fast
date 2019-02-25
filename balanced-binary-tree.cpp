//改名isBalanceint的时候，有两个函数名忘了改，导致怎么运行都不对。

static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        return(isBalancedint(root)!=-1);
    }
               
    int isBalancedint(TreeNode* root){
        if (root==NULL) return 0;
        int left=isBalancedint(root->left);
        int right=isBalancedint(root->right);
        if (left==-1||right==-1) return -1;
        if (abs(left-right)<=1) return max(left,right)+1;
        return -1;
    }
};

