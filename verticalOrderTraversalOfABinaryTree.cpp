#include<vector>
#include<map>
#include<algorithm>
  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:

    void traverse(std::map<int, std::map<int, std::vector<int>>> m, int level, int d, TreeNode* root) {

        m[d][level].push_back(root->val);

        if(root->left) {
            traverse(m, level+1, d-1, root->left);
        }

        if(root->right) {
            traverse(m, level+1, d+1, root->right);
        }

    }

    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {

        std::map<int, std::map<int, std::vector<int>>> m;
        std::map<int, std::map<int, std::vector<int>>>::iterator mIter;
        std::map<int, std::vector<int>>::iterator iter;
        std::vector<std::vector<int>> resolution;

        traverse(m, 0, 0, root);

        for(mIter = m.begin(); mIter != m.end(); mIter++) {

            std::vector<int> temp;

            for(iter = (mIter->second).begin(); iter != (mIter->second).end(); iter++) {

                sort((iter->second).begin(), (iter->second).end());

                for(auto i: iter->second) {
                    temp.push_back(i);
                }

            }

            resolution.push_back(temp);

        }

        return resolution;

    }
};