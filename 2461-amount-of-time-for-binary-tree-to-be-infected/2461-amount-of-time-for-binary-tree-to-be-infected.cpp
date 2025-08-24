/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  public:
    TreeNode* findTarget(TreeNode* root,int target){
        if(root== nullptr) return nullptr;
        if(root->val==target) return root;
        
        TreeNode* left = findTarget(root->left,target);
        if(left) return left;
        
        return findTarget(root->right,target);
        
    }
    
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int target) {
        // code here
        TreeNode* tar = findTarget(root,target);
        
        unordered_map<TreeNode*,TreeNode*>parent_track;
        markParent(root,parent_track);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(tar);
        visited[tar] = true;
        int cur_level =0;
        while(!q.empty()){
            int size = q.size();

                while(size--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
            cur_level++;

        }
        return cur_level-1;
    }
};

