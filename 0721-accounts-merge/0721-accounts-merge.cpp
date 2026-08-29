class Solution {
public:
    vector<int> parent;
    unordered_map<string, int> id;
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) parent[b] = a;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        int val = 0;
        for(int i=0;i<n;i++) {
            for(int j=1;j<accounts[i].size();j++) {
                if(!id.count(accounts[i][j])) id[accounts[i][j]] = val++;
            }
        }
        parent.resize(val);
        for(int i=0;i<val;i++) parent[i] = i;
        for(int i=0;i<n;i++) {
            for(int j=2;j<accounts[i].size();j++) {
                unite(id[accounts[i][1]], id[accounts[i][j]]);
            }
        }
        unordered_map<int, vector<string>> groups;
        for(auto entry : id) {
            string email = entry.first;
            int emailID = entry.second;
            groups[find(emailID)].push_back(email);
        }
        unordered_map<int, string> name;
        for(int i=0;i<n;i++) {
            int root = find(id[accounts[i][1]]);
            name[find(root)] = accounts[i][0];
        }
        vector<vector<string>> ans;
        for(auto& group : groups) {
            int root = group.first;
            vector<string>& emails = group.second;
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(name[root]);
            for(string email : emails) account.push_back(email);
            ans.push_back(account);
        }
        return ans;
    }
};