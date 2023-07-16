/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 void search(struct TreeNode* root, int* ret)
 {
    if(root)
    {  
        if(root->val >= 0)
            (*ret) = (*ret) +1;
        if(root->left)
            search(root->left, ret);
        if(root->right)
            search(root->right, ret);
    }
 }
int countNodes(struct TreeNode* root){
    int ret = 0;
    search(root, &ret);

    return ret;
}