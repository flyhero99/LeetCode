class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int cnt = 0;
        map<char, int> mp;
        string pat = "";
        for(int i = 0; i < pattern.length(); i++) {
            if(mp.count(pattern[i]) == 0) {
                mp.insert(make_pair(pattern[i], cnt++));
            }
        }
        for(int i = 0; i < pattern.length(); i++) {
            pat.push_back(mp[pattern[i]]+'a');
        }
        for(int i = 0; i < words.size(); i++) {
            mp.clear(); cnt = 0;
            string temp = "";
            for(int j = 0; j < words[i].length(); j++) {
                if(mp.count(words[i][j]) == 0) {
                    mp.insert(make_pair(words[i][j], cnt++));
                }
            }
            // cout << mp.size() << endl;
            // for(auto it = mp.begin(); it != mp.end(); it++) {
            //     cout << it->first << ' ' << it->second << endl;
            // }
            for(int j = 0; j < words[i].length(); j++) {
                temp.push_back(mp[words[i][j]]+'a');
            }
            
            if(temp == pat) ans.push_back(words[i]);
        }
        return ans;
    }
};