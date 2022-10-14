
using namespace std;

class Solution {
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        queue<TreeNode*> queue;
        queue.push(root);
        int currentLevel = 1;

        while (!queue.empty() && currentLevel < depth) {

            int sizeLevel = queue.size();
            while (sizeLevel-- > 0) {
                TreeNode* current = queue.front();
                queue.pop();

                if (currentLevel + 1 == depth) {
                    TreeNode* temp = current->left;
                    current->left = new TreeNode(val);
                    current->left->left = temp;
                    queue.push(current->left->left);
                } else if (current->left != nullptr) {
                    queue.push(current->left);
                }

                if (currentLevel + 1 == depth) {
                    TreeNode* temp = current->right;
                    current->right = new TreeNode(val);
                    current->right->right = temp;
                    queue.push(current->right->right);
                } else if (current->right != nullptr) {
                    queue.push(current->right);
                }
            }
            ++currentLevel;
        }
        return root;
    }
};

/*
Struct TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this struct.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} 
};
