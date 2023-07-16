/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void BFS(struct TreeNode* root, int* returnSize, int** returnColumnSizes,int** ret, int depth)
{
    if(root)
    {
        (*returnSize) = (*returnSize) < depth+1 ? depth+1 : (*returnSize);
        // ret[depth] = (int*)realloc(ret[depth], ((*returnColumnSizes)[depth]+1) * sizeof(int));
        // ret[depth] = (int*)realloc(ret[depth], ((*returnColumnSizes)[depth]+1) * sizeof(int));
        ret[depth][(*returnColumnSizes)[depth]] = root->val;
        (*returnColumnSizes)[depth]++;
        // printf("(*returnColumnSizes)[%d] = %d\n",depth, (*returnColumnSizes)[depth]);
        // printf("val = %d, depth = %d, (*returnSize) = %d\n", root->val, depth, (*returnSize));
    }
    else
        return;
    if(root->left)
        BFS(root->left, returnSize, returnColumnSizes, ret, depth+1);
    if(root->right)
        BFS(root->right, returnSize, returnColumnSizes, ret, depth+1);
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **ret = NULL;
    *returnSize = 0;
    ret = (int**)malloc(sizeof(int*)*(2000));
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*(2000));
    memset((*returnColumnSizes), 0, 2000*sizeof(int));
    for(int i = 0 ;i < 2000 ;i++)
    {
        ret[i] = malloc(1000* sizeof(int));
    }
    BFS(root, returnSize, returnColumnSizes, ret, 0);
    return ret;
}