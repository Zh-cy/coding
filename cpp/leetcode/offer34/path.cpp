// backtracking 

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target)
    {
        recurs(root, target);
        return res;
    }

    void recurs(TreeNode* root, int target)
    {
        if (root==nullptr)
            return;
        path.push_back(root->val);
        target -= root->val;
        if (target == 0 && root->left == nullptr && root->right == nullptr)
            res.push_back(path);
        recurs(root->left, target);
        recurs(root->right, target);
        // the last element must be popped
        path.pop_back();
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};
