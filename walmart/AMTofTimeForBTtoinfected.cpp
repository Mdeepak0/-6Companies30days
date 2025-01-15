class Solution {
public: 
        TreeNode* first = NULL;
        void markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
            if(root==NULL) return;
            if(root->left) parent[root->left] = root;
            if(root->right) parent[root->right] = root;
            markparent(root->left,parent);
            markparent(root->right,parent);
        }
 // step 1 find node with given value;
        void find(TreeNode* root, int start){
        if(root==NULL) return;
        if(root->val==start){
            first= root;
            return;
        }
        find(root->left,start);
        find(root->right,start);
    }
    int amountOfTime(TreeNode* root, int start) {
         find(root,start);
        unordered_map<TreeNode*,TreeNode*> parent;
        markparent(root, parent);
        unordered_set<TreeNode*> isInfected;
        isInfected.insert(first);
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> p;
        p.first = first;
        p.second = 0;
        q.push({first,0});
       int mxLevel = 0;
        // bfs;
        while(q.size()>0){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            int level = p.second;
            mxLevel = max(mxLevel,level);
            TreeNode* temp = p.first;
            if(temp->left){
                if(isInfected.find(temp->left)==isInfected.end()){
                    q.push({temp->left,level+1});
                    isInfected.insert(temp->left);
                }
            }
             if(temp->right){
                if(isInfected.find(temp->right)==isInfected.end()){
                    q.push({temp->right,level+1});
                    isInfected.insert(temp->right);
                }
            }
            if(parent.find(temp)!=parent.end()){
                if(isInfected.find(parent[temp])==isInfected.end()){
                    q.push({parent[temp],level+1});
                    isInfected.insert(parent[temp]);
                }
            }
        }
        return mxLevel;
    }
};
