static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool left,right,root;
        if(p==NULL&&q==NULL) return true;
        if(p==NULL&&q!=NULL) return false;
        if(p!=NULL&&q==NULL) return false;
        //left=isSameTree(p->left,q->left);
        //right=isSameTree(p->right,q->right);
        //root=(p->val==q->val);
        //return left&&right&&root;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right)&&(p->val==q->val);
    }
};
