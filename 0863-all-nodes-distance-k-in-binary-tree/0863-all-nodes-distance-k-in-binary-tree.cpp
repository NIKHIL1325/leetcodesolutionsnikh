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
    void markparent(TreeNode* root,       unordered_map<TreeNode*,TreeNode*> & parenttrack,TreeNode* target){
        queue<TreeNode*> qe;
        qe.push(root);

        while(!qe.empty()){
            TreeNode* curr = qe.front();
            qe.pop();
            if(curr->left){
                parenttrack[curr->left] = curr;
                qe.push(curr->left);
            }
              if(curr->right){
                parenttrack[curr->right] = curr;
                qe.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parenttrack;
        markparent(root,parenttrack,target);

        unordered_map<TreeNode*,bool> visit;
        queue<TreeNode*>q;
        q.push(target);
            visit[target] = true;
            
        int curlevel =0;
        while(!q.empty()){
           int size = q.size();

           if(curlevel++ == k) break;

         for(int i=0;i<size;i++){
           TreeNode*  curr = q.front();
           q.pop();

            if(curr->left && !visit[curr->left]){
                q.push(curr->left);
                visit[curr->left] = true;
            }
               if(curr->right && !visit[curr->right]){
                q.push(curr->right);
                visit[curr->right] = true;
            }

               if(parenttrack[curr] && !visit[parenttrack[curr]]){
               q.push(parenttrack[curr]);       // Fix 1: Push parent
                    visit[parenttrack[curr]] = true;
            }
         }
          

        }

        vector<int> result;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
        
    }
};