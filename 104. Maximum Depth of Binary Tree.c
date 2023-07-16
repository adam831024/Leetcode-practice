/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 void fun(struct TreeNode* root, int index, int* ret)
 {
    (*ret) = index >= (*ret) ? index : (*ret);
    if(root->left)
        fun(root->left, index+1, ret);
    if(root->right)
        fun(root->right, index+1, ret);
 }
int maxDepth(struct TreeNode* root){
    int ret = 0;
    if(root)
        fun(root, 1, &ret);
    return ret;
}