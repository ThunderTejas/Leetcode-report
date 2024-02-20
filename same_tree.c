/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    // If both trees are empty then return true...
    if(p == NULL && q == NULL)
        return true;
    // If one of the tree is empty and the other is not or the value of p tree is not equal to the value of q tree, then return false...
    if(p == NULL || q == NULL || p->val != q->val)
        return false;
    // If both trees are non empty and the value of p tree is equal to the value of q tree...
    // Check left subtrees and right subtrees recursively...
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
