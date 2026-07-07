class Solution {
public:
    long long number(int n) {
        stack<int> st;
        while(n > 0) {
            if(n%10 != 0) {
                st.push(n%10);
            }
            n /= 10;
        }
        long long x = 0;
        while(!st.empty()) {
            int top = st.top();
            x = x * 10 + top;
            st.pop();
        }
        return x;
    }
    int sumOfDigits(long long n) {
        int sum = 0;
        while(n > 0) {
            int rem = n%10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    long long sumAndMultiply(int n) {
        long long x = number(n);
        int sum = sumOfDigits(x);
        long long ans = x * sum;
        return ans;
    }
};