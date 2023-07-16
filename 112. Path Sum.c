/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void fun(struct TreeNode* root, int targetSum, int now_sum, bool* ret)
{

    if(root->left)
        fun(root->left, targetSum, now_sum+root->val, ret);
    if(root->right)
        fun(root->right, targetSum, now_sum+root->val, ret);
    printf("now_sum = %d\n", now_sum+root->val);
    if(now_sum+root->val == targetSum && root->left == NULL && root->right == NULL)
        *ret = true;
}
bool hasPathSum(struct TreeNode* root, int targetSum){
    bool ret = false;
    if(root)
        fun(root, targetSum, 0, &ret);
    return ret;
}