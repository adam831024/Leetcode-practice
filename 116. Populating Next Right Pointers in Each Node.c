/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

int depth_cal(struct Node *node) {
    int l, r;
    if (!node) return 0;
    l = depth_cal(node->left)  + 1;
    r = depth_cal(node->right) + 1;
    if (l > r) return l;
    return r;
}

void BFS(struct Node* root, int depth, struct Node** prev)
{
    if(root)
    {
        // printf("val = %d, depth = %d\n", root->val, depth);
        if(prev[depth] == NULL)
            prev[depth] = root;
        else
        {
            prev[depth]->next = root;
            prev[depth] = root;
        }
    }
    if(root->left)
        BFS(root->left, depth+1, prev);
    if(root->right)
        BFS(root->right, depth+1, prev);
}
struct Node* connect(struct Node* root) {
    int depth = depth_cal(root);
    // printf("depth = %d\n", depth);
    if(0 == depth)
        return root;

    struct Node** prevList = (struct Node**)malloc(sizeof(struct Node*)* depth);
    memset(prevList, 0, sizeof(struct Node*)*depth);

    BFS(root, 0, prevList);

    free(prevList);
    return root;
}