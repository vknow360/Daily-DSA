class Solution {
public:
    TreeNode* get(unordered_map<int, TreeNode*> &mp, int k) {
        auto [it, inserted] = mp.emplace(k, nullptr);
        if(inserted) it->second = new TreeNode(k);
        return it->second;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> pmp;
        for(auto& des : descriptions) {
            int p = des[0], c = des[1];
            bool left = (des[2]==1);

            TreeNode* parent = get(mp, p);
            
            TreeNode* child = get(mp, c);
            
            if(left) parent->left = child;
            else parent->right = child;
            pmp.insert(c);
        }
        for(auto [k, v] : mp) {
            if(!pmp.count(k)) return v;
        }
        return nullptr;
    }
};
