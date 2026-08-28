class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> distance;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        distance[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                string parent = q.front();
                q.pop();
                if(parent == endWord) return count;
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
            count++;
        }
        return 0;
    }
};