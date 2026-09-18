class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for(int i=0;i<n;i++) {
            if(first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
                last[s[i] - 'a'] = i;
            }
            else last[s[i] - 'a'] = i;
        }
        vector<pair<int, int>> intervals;
        for(int i=0;i<n;i++) {
            int start = first[s[i] - 'a'];
            int end = last[s[i] - 'a'];
            if(i != start) continue;
            int j = start;
            bool isValid = true;
            while(j <= end) {
                int newStart = first[s[j] - 'a'];
                int newEnd = last[s[j] - 'a'];
                if(newStart < start) {
                    isValid = false;
                    break;
                }
                if(newEnd > end) end = newEnd;
                j++;
            }
            if(isValid) {
                intervals.push_back({start, end});
            }
        }
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });
        int lastEnd = -1;
        int write = 0;
        for(int i=0;i<intervals.size();i++) {
            if(intervals[i].first > lastEnd) {
                intervals[write++] = intervals[i];
                lastEnd = intervals[i].second;
            }
        }
        intervals.resize(write);
        vector<string> ans;
        for(int i=0;i<intervals.size();i++) {
            int start = intervals[i].first;
            int end = intervals[i].second;
            ans.push_back(s.substr(start, end - start + 1));
        }
        return ans;
    }
};