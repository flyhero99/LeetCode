class Solution {
public:
    bool dp[1001][1001];
    string longestPalindrome(string s) {
        int maxlen = 1, st = 0;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            for(int j = 0; j <= i; j++) {
                if(i-j <= 1)
                    dp[j][i] = (s[i] == s[j]);
                else
                    dp[j][i] = (s[i] == s[j]) && dp[j+1][i-1];
                if(dp[j][i] && maxlen < i-j+1) {
                    maxlen = i-j+1;
                    st = j;
                }
            }
        }
        return s.substr(st, maxlen);
    }
};