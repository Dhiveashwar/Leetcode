#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        if (abs(findHeight(root->left) - findHeight(root->right)) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }

private:
    int findHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createSampleTree();
    if (solution.isBalanced(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;
    return 0;
}
