/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }

         TreeNode* left = lowestCommonAncestor( root->left,  p,q);
          TreeNode* rigt = lowestCommonAncestor( root->right,  p,q);

          if(left == NULL){
            return rigt;
          }
          else if(rigt == NULL){
            return left;
          }
          else{
            return root;
          }


    }
};