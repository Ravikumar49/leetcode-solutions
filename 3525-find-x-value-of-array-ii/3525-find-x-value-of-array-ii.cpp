class Solution {
public:
    struct Node{
        int product;
        array<int, 5> prefix{};
    };
    int n;
    vector<Node> Tree;
    Node merge(Node left, Node right, int k) {
        Node curr;
        curr.product = (left.product * right.product) % k;
        curr.prefix = left.prefix;
        for(int r=0;r<k;r++) {
            curr.prefix[(left.product * r) % k] += right.prefix[r];
        }
        return curr;
    }

    Node query(int node, int l, int r, int ql, int qr, int k) {
        if(r < ql || qr < l) {
            Node EMPTY;
            EMPTY.product = 1;
            EMPTY.prefix = {0, 0, 0, 0, 0};
            return EMPTY;
        }
        if(ql <= l && r <= qr) {
            return Tree[node];
        }
        int m = (l + r)/2;
        Node left = query(2 * node + 1, l, m, ql, qr, k);
        Node right = query(2 * node + 2, m+1, r, ql, qr, k);
        return merge(left, right, k);
    }

    vector<int> result(vector<vector<int>>& queries, int k) {
        vector<int> results(queries.size());
        for(int i=0;i<queries.size();i++) {
            int index = queries[i][0];
            int value = queries[i][1];
            int start = queries[i][2];
            int x = queries[i][3];
            update(0, 0, n-1, index, value, k);
            Node curr = query(0, 0, n-1, start, n-1, k);
            results[i] = curr.prefix[x];
        }
        return results;
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        Tree.resize(4 * n);
        build(0, 0, n-1, k, nums);
        return result(queries, k);
    }

    void update(int node, int l, int r, int index, int value, int k) {
        if(l == r) {
            Tree[node].prefix = {};
            Tree[node].product = value % k;
            Tree[node].prefix[value % k] = 1;
            return;
        }
        int m = (l + r) / 2;
        if(index <= m) {
            update(2 * node + 1, l, m, index, value, k);
        }
        else {
            update(2 * node + 2, m+1, r, index, value, k);
        }
        Tree[node] = merge(Tree[2 * node + 1], Tree[2 * node + 2], k);
    }

    void build(int node, int l, int r, int k, vector<int>& nums) {
        if(l == r) {
            Tree[node].product = nums[l] % k;
            Tree[node].prefix[nums[l] % k] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(2 * node + 1, l, m, k, nums);
        build(2 * node + 2, m+1, r, k, nums);
        Tree[node] = merge(Tree[2 * node + 1], Tree[2 * node + 2], k);
    }
};