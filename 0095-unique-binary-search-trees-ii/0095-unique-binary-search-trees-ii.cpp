class Solution {
public:

    vector<TreeNode*> generate(int start, int end) {

        vector<TreeNode*> ans;

        if(start > end) {
            ans.push_back(NULL);
            return ans;
        }

        for(int i = start; i <= end; i++) {

            vector<TreeNode*> left = generate(start, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);

            for(int l = 0; l < left.size(); l++) {
                for(int r = 0; r < right.size(); r++) {

                    TreeNode* root = new TreeNode(i);

                    root->left = left[l];
                    root->right = right[r];

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};