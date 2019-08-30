class Solution {
public:
    bool valid(string s) {
        int cnt[300] = {0};
        for(int i = 0; i < s.length(); i++) {
            int t = s[i];
            cnt[t]++;
            if(cnt[t] >= 2) return false;
        }
        return true;
    }
    
    int lengthOfLongestSubstring(string s) {
        // if(s.length() == 0 || s.length() == 1) return (int)s.length();
        int cnt = 0;
        for(int len = 1; len <= s.length(); len++) {
            bool flag = 0;
            for(int i = 0; i < s.length()-len+1; i++) {
                string str = s.substr(i, len);
                // cout << "str: " << str << endl;
                if(valid(str)) { flag = 1; break; }
            }
            if(!flag) {
                cnt = len-1;
                break;
            }
            cnt = len;
        }
        return cnt;
    }
};