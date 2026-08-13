class Solution {
public:
    vector<int> parent;
    unordered_map<string, int> id;
    int find(int x) {
        if(parent[x] == x) return x;
        return find(parent[x]);
    }
    void unite(string email_a, string email_b) {
        int a = find(id[email_a]);
        int b = find(id[email_b]);
        if(a != b) parent[b] = a;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i=0;i<accounts.size();i++) {
            for(int j=1;j<accounts[i].size();j++) {
                string email = accounts[i][j];
                if(!id.count(email)) id[email] = id.size();
            }
        }
        parent.resize(id.size());
        for(int i=0;i<id.size();i++) parent[i] = i;
        for(int i=0;i<accounts.size();i++) {
            string firstEmail = accounts[i][1];
            for(int j=2;j<accounts[i].size();j++) {
                unite(firstEmail, accounts[i][j]);
            }
        }
        unordered_map<int, vector<string>> group;
        for(auto &x : id) {
            group[find(x.second)].push_back(x.first); 
        }
        unordered_map<int, string> names;
        for(int i=0;i<accounts.size();i++) {
            string firstEmail = accounts[i][1];
            int x = id[firstEmail];
            int root = find(x);
            names[root] = accounts[i][0];
        }
        vector<vector<string>> ans;
        for(auto &root : group) {
            vector<string> curr;
            curr.push_back(names[root.first]);
            vector<string> &emails = root.second;
            sort(emails.begin(), emails.end());
            for(auto &email : emails) {
                curr.push_back(email);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};