#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* node, string path, vector<string> &paths) {
    if (!node) return;
    path += to_string(node->val);
    if (!node->left && !node->right) {
        paths.push_back(path);
        return;
    }
    path += "->";
    dfs(node->left, path, paths);
    dfs(node->right, path, paths);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    dfs(root, "", paths);
    return paths;
}
