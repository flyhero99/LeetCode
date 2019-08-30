class Solution {
public:
    string longestPalindrome(string s) {
        int st = 0, ed = 0;
        for(int i = 0; i < s.length(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if(len > ed-st) {
                st = i - (len-1)/2;
                ed = i + len/2;
            }
        }
        return s.substr(st, ed-st+1);
    }
    int expand(string s, int l, int r) {
        while(l >= 0 && r < s.length() && s[l] == s[r])
            l--, r++;
        return r-l-1;
    }
};