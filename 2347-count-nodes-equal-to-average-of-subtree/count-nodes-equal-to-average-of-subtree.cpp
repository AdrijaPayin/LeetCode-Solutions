/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int count = 0;

public:
    vector<int> helper(TreeNode* root) {
        if (!root)  return {0, 0};

        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);

        int currSum = root->val + left[0] + right[0];
        int currCnt = 1 + left[1] + right[1];
        int avg = currSum / currCnt;

        if (root->val == avg)  count++;

        return {currSum, currCnt};
    }

public:
    int averageOfSubtree(TreeNode* root) {

        helper(root);
        return count;
    }
};