/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check(struct TreeNode* left, struct TreeNode* right)
{
    if(left == NULL && NULL == right)
        return true;
    else if(left == NULL || NULL == right)
        return false;
    else
    {
        if(left->val == right->val)
            return check(left->right, right->left) && check(left->left, right->right);
        else
            return false;
    }

}

bool isSymmetric(struct TreeNode* root){
    return check(root->left, root->right);
}