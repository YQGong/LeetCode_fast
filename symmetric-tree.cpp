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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric(root->left,root->right);
    }
    
    bool isSymmetric(TreeNode* left,TreeNode* right){
        if(left==NULL&&right==NULL) return true;
        if(left==NULL&&right!=NULL) return false;
        if(left!=NULL&&right==NULL) return false;
        //bool left,right,root;
        //left=isSameTree(p->left,q->left);
        //right=isSameTree(p->right,q->right);
        //root=(p->val==q->val);
        //return left&&right&&root;
        return isSymmetric(left->left,right->right)&&isSymmetric(left->right,right->left)&&(left->val==right->val);
    }
};
