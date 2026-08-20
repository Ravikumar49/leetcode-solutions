class Fenwick {
    vector<int> bit;
    int n;
public:
    Fenwick(int n) {
        this->n = n;
        bit.resize(n+1, 0);
    }

    void update(int i, int delta) {
        while(i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        unordered_map<int, int> rank;
        for(int i=0;i<sorted.size();i++) {
            rank[sorted[i]] = i+1;
        }
        Fenwick bit1(sorted.size());
        Fenwick bit2(sorted.size());
        int size1 = 1, size2 = 1;
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        bit1.update(rank[nums[0]], 1);
        bit2.update(rank[nums[1]], 1);
        for(int i=2;i<n;i++) {
            int r = rank[nums[i]];
            int greater1 = size1 - bit1.query(r);
            int greater2 = size2 - bit2.query(r);
            if(greater1 > greater2) {
                arr1.push_back(nums[i]);
                bit1.update(r, 1);
                size1++;
            }
            else if(greater1 < greater2) {
                arr2.push_back(nums[i]);
                bit2.update(r, 1);
                size2++;
            }
            else {
                if(size1 <= size2) {
                    arr1.push_back(nums[i]);
                    bit1.update(r, 1);
                    size1++;
                }
                else {
                    arr2.push_back(nums[i]);
                    bit2.update(r, 1);
                    size2++;
                }
            }
        }
        vector<int> result;
        for(int x : arr1) result.push_back(x);
        for(int x : arr2) result.push_back(x);
        return result;
    }
};