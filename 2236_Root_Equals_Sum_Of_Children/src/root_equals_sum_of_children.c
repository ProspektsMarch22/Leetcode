#include "../include/binary_tree.h"

bool checkTree(struct TreeNode *root)
{
	return (root->val == root->left->val + root->right->val);
}
