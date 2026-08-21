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
    
    int binToDec(string &binaryNum) {

        int len = binaryNum.length();
        int cnt = 0;

        int num = 0;
        for(int i = len - 1; i >= 0; i--) {

            if(binaryNum[i] == '1') {
                num += pow(2, cnt);
            }

            cnt++;
        }

        return num;
    }

    int findSum(TreeNode* root, string binaryNum) {

        if(root == nullptr) return 0;

        if(root->left == nullptr && root->right == nullptr) {
            binaryNum += (root->val == 0) ? "0" : "1";
            return binToDec(binaryNum);
        }

        binaryNum += (root->val == 0) ? "0" : "1";
        int left = findSum(root->left, binaryNum);
        int right = findSum(root->right, binaryNum);

        return left + right;
    }
public:
    int sumRootToLeaf(TreeNode* root) {

        return findSum(root, "");
    }
};