class NumArray {
public:
    int n;
    vector<int> Tree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        Tree.resize(4 * n);
        build(0, 0, n-1, nums);
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if(l == r) {
            Tree[node] = nums[l];
            return;
        }
        int m = (l + r)/2;
        build(2 * node + 1, l, m, nums);
        build(2 * node + 2, m+1, r, nums);
        Tree[node] = Tree[2 * node + 1] + Tree[2 * node + 2];
    }

    void update(int node, int l, int r, int index, int val) {
        if(l == r) {
            Tree[node] = val;
            return;
        }
        int m = (l + r)/2;
        if(index <= m) {
            update(2 * node + 1, l, m, index, val);
        }
        else {
            update (2 * node + 2, m+1, r, index, val);
        }
        Tree[node] = Tree[2 * node + 1] + Tree[2 * node + 2];
    }
    
    void update(int index, int val) {
        update(0, 0, n-1, index, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(r < ql || qr < l) {
            return 0;
        }
        if(ql <= l && r <= qr) {
            return Tree[node];
        }
        int m = (l + r)/2;
        return query(2 * node + 1, l, m, ql, qr) + query(2 * node + 2, m+1, r, ql, qr);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */