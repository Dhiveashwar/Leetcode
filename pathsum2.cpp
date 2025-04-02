#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to find all paths with the target sum
    void findPath(TreeNode* root, vector<vector<int>>& ans, vector<int> temp, int target, int value) {
        if (!root) return;
        
        value += root->val;
        temp.push_back(root->val);

        // Check if current node is a leaf and path sum equals target
        if (!root->left && !root->right && value == target) {
            ans.push_back(temp);
        }

        // Recur for right and left subtrees
        findPath(root->right, ans, temp, target, value);
        findPath(root->left, ans, temp, target, value);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        findPath(root, ans, temp, targetSum, 0);
        return ans;
    }
};

// Function to insert nodes into the tree
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

// Function to build a sample tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    return root;
}

// Function to print paths
void printPaths(const vector<vector<int>>& paths) {
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = createSampleTree();
    Solution sol;
    
    int targetSum;
    cout << "Enter target sum: ";
    cin >> targetSum;

    vector<vector<int>> result = sol.pathSum(root, targetSum);

    if (result.empty()) {
        cout << "No paths found with the target sum." << endl;
    } else {
        cout << "Paths with target sum " << targetSum << ":\n";
        printPaths(result);
    }

    return 0;
}
