class Solution {
public:
    struct Node {
        char leftChar;
        char rightChar;
        int len;
        int prefix;
        int suffix;
        int best;
    };

    Node merge(Node left, Node right) {
        Node curr;
        if(left.prefix == left.len && left.rightChar == right.leftChar) curr.prefix = left.prefix + right.prefix;
        else curr.prefix = left.prefix;
        if(right.suffix == right.len && right.leftChar == left.rightChar) curr.suffix = right.len + left.suffix;
        else curr.suffix = right.suffix;
        curr.len = left.len + right.len;
        curr.leftChar = left.leftChar;
        curr.rightChar = right.rightChar;
        curr.best = max(left.best, right.best);
        if(left.rightChar == right.leftChar) curr.best = max(curr.best, left.suffix + right.prefix);
        return curr;
    }

    vector<int> longestRepeating(string queryCharacters, vector<int>& queryIndices) {
        vector<int> ans;
        for(int i=0;i<queryIndices.size();i++) {
            update(0, 0, n-1, queryIndices[i], queryCharacters[i]);
            ans.push_back(Tree[0].best);
        }
        return ans;
    }

    void update(int node, int l, int r, int index, char c) {
        if(l == r) {
            Tree[node].leftChar = c;
            Tree[node].rightChar = c;
            return;
        }
        int m = (l + r) / 2;
        if(index <= m) {
            update(2 * node + 1, l, m, index, c);
        }
        else {
            update(2 * node + 2, m+1, r, index, c);
        }
        Tree[node] = merge(Tree[2 * node + 1], Tree[2 * node + 2]);
    }

    void build(int node, int l, int r, string& s) {
        if(l == r) {
            Tree[node].leftChar = s[l];
            Tree[node].rightChar = s[r];
            Tree[node].len = 1;
            Tree[node].prefix = 1;
            Tree[node].suffix = 1;
            Tree[node].best = 1;
            return;
        }
        int m = (l + r)/2;
        build(2 * node + 1, l, m, s);
        build(2 * node + 2, m+1, r, s);
        Tree[node] = merge(Tree[2 * node + 1], Tree[2 * node + 2]);
    }
    
    int n;
    vector<Node> Tree;
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        Tree.resize(4 * n);
        build(0, 0, n-1, s);
        return longestRepeating(queryCharacters, queryIndices);
    }
};