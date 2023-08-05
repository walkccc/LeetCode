class Solution {
 public:
int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<double>dp(m+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = m; j > 0; j--) {
                if(s[i-1] == t[j-1]) dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[m];    
    }
};
