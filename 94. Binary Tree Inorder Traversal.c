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
 void search(struct TreeNode* ptr, int* returnSize, int* ret)
 {
     if(ptr)
     {
        search(ptr->left, returnSize, ret);
         ret[(*returnSize)++] = ptr->val;
        search(ptr->right, returnSize, ret);
     }
 }
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret = (int*)malloc(sizeof(int)*100);
    *returnSize = 0;
    search(root, returnSize, ret);
    return ret;
}