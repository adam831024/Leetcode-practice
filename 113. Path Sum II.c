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

void fun(struct TreeNode* root, int targetSum, int* returnSize,int* returnColumnSizes, int *tBuf, int tmpSum, int index, int **ret)
{
    // if(root)
        printf("root->val = %d. tmpSum = %d\n", root->val, tmpSum);
    if(tmpSum == targetSum && root->right == NULL && root->left == NULL)
    {
        ret[*returnSize] = malloc(sizeof(int) * index);
        returnColumnSizes[*returnSize] = index;
        memcpy(ret[*returnSize], tBuf, sizeof(int) * index);
        (*returnSize)++;
        printf("tBuf = ");
        for(int i = 0 ; i < index ; i++)
        {
            printf("%d ", tBuf[i]);
        }
        printf("\n");
    }
    if(root->left)
    {
        tBuf[index] = root->left->val;
        fun(root->left, targetSum, returnSize,returnColumnSizes, tBuf, tmpSum+root->left->val, index+1, ret);
    }
    if(root->right)
    {
        tBuf[index] = root->right->val;
        fun(root->right, targetSum, returnSize,returnColumnSizes, tBuf, tmpSum+root->right->val, index+1, ret);
    }

}
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    int **ret = (int**)malloc(sizeof(int*) * 1000);
    *(returnColumnSizes) = (int*)malloc(sizeof(int) * 1000);
    *(returnSize) = 0;
    int tBuf[1000];
    if(root)
    {
        tBuf[0] = root->val;
        fun(root, targetSum, returnSize,*returnColumnSizes, tBuf, root->val, 1, ret);
    }
        
    return ret;
}