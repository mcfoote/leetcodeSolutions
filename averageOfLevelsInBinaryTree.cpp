#include<vector>
#include<queue>

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
    std::vector<double> averageOfLevels(TreeNode* root) {
        
        std::queue<TreeNode*> q;
        std::vector<double> answer;

        q.push(root);

        while(!q.empty()) {

            int n = q.size();
            double sum =0;

            for(int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                sum += node->val;

                q.pop();

            }

            answer.push_back(sum / n);

        }

        return answer;

    }
};