class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0 || len == 1) return len;
        int l = 0, r = 0;
        unordered_set<char> cset;
        int ans = 0;
        while(r < len) {
            while(cset.count(s[r]) != 0) {
                cset.erase(s[l]);
                l++;
            }
            cset.insert(s[r]);
            r++;
            ans = max(ans, (int) cset.size());
        }
        return ans;
    }
};