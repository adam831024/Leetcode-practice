/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 void DFS(struct TreeNode* root, int* ret, int tVal)
 {
     if(root)
     {
        tVal += root->val;
     }

     if(root->left == NULL && root->right == NULL)
     {
         (*ret) += tVal;
     }
     if(root->left)
     {
         DFS(root->left, ret, tVal*10);
     }
     if(root ->right)
     {
         DFS(root->right, ret, tVal*10);
     }
 }
int sumNumbers(struct TreeNode* root){
    int ret = 0;
    DFS(root, &ret, 0);
    return ret;
}