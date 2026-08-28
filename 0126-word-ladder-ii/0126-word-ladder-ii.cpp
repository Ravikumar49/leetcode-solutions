class Solution {
public:
    void dfs(string word, string beginWord, unordered_map<string, vector<string>>& parents, vector<string>& path, vector<vector<string>>& result) {
        if(word == beginWord) {
            vector<string> sequence = path;
            reverse(sequence.begin(), sequence.end());
            result.push_back(sequence);
            return;
        }
        for(string parent : parents[word]) {
            path.push_back(parent);
            dfs(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> distance;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        distance[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                string parent = q.front();
                q.pop();
                for(int index=0;index<parent.size();index++) {
                    char original = parent[index];
                    for(char c='a';c<='z';c++) {
                        if(c == original) continue;
                        string current = parent;
                        current[index] = c;
                        if(!wordSet.count(current)) continue;
                        if(!distance.count(current)) {
                            distance[current] = distance[parent] + 1;
                            parents[current].push_back(parent);
                            q.push(current);
                        }
                        else if(distance[current] == distance[parent] + 1) {
                            parents[current].push_back(parent);
                        }
                    }
                    parent[index] = original;
                }
            }
        }
        vector<vector<string>> result;
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, parents, path, result);
        return result;
    }
};