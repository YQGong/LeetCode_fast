//把and改成or之后，一些空指针的case就漏到下面的句子去了。
//审题不清楚导致出错
//忘了对root的空指针进行处理


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
private:
    int mindipth;
    
public:
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        mindipth=INT_MAX;
        findMinDipth(root,1);
        return mindipth;
    }
    
    int findMinDipth(TreeNode* root,int level){
        if(level>=mindipth) return 0;
        if(root->left==NULL&&root->right==NULL) {
            mindipth=level;
            return 0;
        }
        if(root->left) findMinDipth(root->left,level+1);
        if(root->right) findMinDipth(root->right,level+1);
        return 0;
    }
};
