/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void dfs(struct TreeNode* root, int* ret, int* returnSize, int index)
 {
    if(index >= (*returnSize) && root != NULL)
    {
        // ret = (int*)realloc(ret, sizeof(int)*((*returnSize)+1));
        ret[(*returnSize)] = root->val;
        (*returnSize)++;
        printf("index = %d, root->val = %d\n", index,root->val );
    }
    if(root->right != NULL)
        dfs(root->right, ret, returnSize, index+1);
    if(root->left != NULL)
        dfs(root->left, ret, returnSize, index+1);
 }
int* rightSideView(struct TreeNode* root, int* returnSize){
    int *ret = NULL;
    ret = (int*)malloc(sizeof(int)*100);
    (*returnSize) = 0;
    if(root)
        dfs(root, ret, returnSize, 0);

    ret = (int*)realloc(ret, sizeof(int)*((*returnSize)+1));
    ret[(*returnSize)] = '\n';
    return ret;
}