/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void func(int *ret, int index, struct TreeNode* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        (*ret) = index > (*ret) ?  (*ret) : index;
        return ;
    }
    if(root->left)
        func(ret, index+1, root->left);
    if(root->right)
        func(ret, index+1, root->right);
}
int minDepth(struct TreeNode* root)
{
    int ret = 100001;
    if(root)
        func(&ret, 1, root);
    else
        ret = 0;
    return ret;
}