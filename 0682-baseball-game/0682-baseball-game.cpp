class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(string s : operations) {
            if(s != "C" && s != "D" && s != "+") {
                int num = stoi(s);
                st.push(num);
                sum += num;
            }
            else if(s == "C") {
                int x = st.top();
                st.pop();
                sum -= x;
            }
            else if(s == "D") {
                int n = 2 * st.top();
                st.push(n);
                sum += n;
            }
            else {
                int first = st.top();
                st.pop();
                int second = st.top();
                int curr = first + second;
                st.push(first);
                st.push(curr);
                sum += curr;
            }
        }
        return sum;
    }
};