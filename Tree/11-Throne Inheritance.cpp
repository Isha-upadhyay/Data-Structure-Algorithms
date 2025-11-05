class ThroneInheritance {
private:
    
    struct Tree{
        string name;
        vector<Tree*> childrens;
    };

public:   
    Tree *root;
    unordered_map<string, Tree*>mp; // for dead people mark

    ThroneInheritance(string kingName) {
        root = new Tree();
        root->name = kingName;
        mp[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Tree* child = new Tree();
        child->name = childName;
        mp[parentName]->childrens.push_back(child); // link parent->child
        mp[childName] = child;
    }
    
    void death(string name) {
        mp[name] = NULL;
    }


    void dfs(Tree* root, vector<string>& ans){
        if(mp[root->name] != NULL){
            ans.push_back(root->name);
        }

        for(int i=0;i< root->childrens.size(); i++){
            dfs(root->childrens[i], ans);
        }
        return;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(root, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
