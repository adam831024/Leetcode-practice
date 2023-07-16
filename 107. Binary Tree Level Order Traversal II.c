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

int check_depth(struct TreeNode* root)
{
    int l = 0;
    int r = 0;
    if(!root)
        return 0; 
    l = check_depth(root->left)+1;
    r = check_depth(root->right)+1;
    if(l>r)
        return l;
    return r;
}

void BFS(struct TreeNode* root, int* returnColumnSizes, int** ret, int depth_now, int final_depth)
{
    if(!root)
        return;
    int index = final_depth-depth_now;
    // printf("index = %d, depth = %d, val = %d\n", index, depth_now, root->val);
    // ret[index] = (int*)realloc(ret[index], sizeof(int)*(returnColumnSizes[index]+1));
    ret[index][returnColumnSizes[index]] = root->val;
    returnColumnSizes[index]++;
    // printf("returnColumnSizes[index] = %d\n", returnColumnSizes[index]);
    
    

    if(root->left)
        BFS(root->left, returnColumnSizes, ret, depth_now+1, final_depth);
    if(root->right)
        BFS(root->right, returnColumnSizes, ret, depth_now+1, final_depth);
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** ret = NULL;
    int depth = check_depth(root);
    printf("depth = %d\n", depth);
    *returnSize = depth;

    if(depth == 0)
        return ret;
    (*returnColumnSizes) = (int*)malloc(sizeof(int)* depth);
    memset((*returnColumnSizes), 0, sizeof(int)*depth);
    ret = (int**)malloc(sizeof(int*) * depth);
    for(int i = 0; i <depth;i++)
    {
        ret[i] = (int*)malloc(sizeof(int)*1000); 
    }
    BFS(root, (*returnColumnSizes), ret, 0, depth-1);
    
    return ret;
}