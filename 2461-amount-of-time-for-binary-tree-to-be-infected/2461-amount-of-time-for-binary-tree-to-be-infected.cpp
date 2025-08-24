/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int result = 0; // max time to infect entire tree

    // Helper function to compute the depth of a subtree
    int subtreeDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(subtreeDepth(root->left), subtreeDepth(root->right));
    }

    // DFS returns distance from current node to target
    int dfs(TreeNode* root, int target) {
        if (!root) return -1;

        if (root->val == target) {
            // Compute infection time downward from target
            int depth = subtreeDepth(root);
            result = max(result, depth - 1);
            return 0; // distance to target = 0
        }

        int left = dfs(root->left, target);
        if (left != -1) {
            // target is in left subtree
            int depth = subtreeDepth(root->right); // infection spreads into right subtree
            result = max(result, left + 1 + depth);
            return left + 1;
        }

        int right = dfs(root->right, target);
        if (right != -1) {
            // target is in right subtree
            int depth = subtreeDepth(root->left); // infection spreads into left subtree
            result = max(result, right + 1 + depth);
            return right + 1;
        }

        return -1; // target not found in this subtree
    }

    int amountOfTime(TreeNode* root, int target) {
        dfs(root, target);
        return result;
    }
};
