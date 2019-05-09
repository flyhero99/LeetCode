class Solution {
public:
    typedef pair<char, int> pci;
    
    struct qcmp {
        bool operator () (const pci &a, const pci &b) const {
            return a.second < b.second;
        }
    };
    
    map<char, int> mp;
    
    string frequencySort(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(mp.count(s[i]) == 0) {
                mp.insert(make_pair(s[i], 1));
            }
            else {
                mp[s[i]]++;
            }
        }
        priority_queue<pci, vector<pci>, qcmp> q;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            q.push(*it);
        }
        string ans = "";
        while(!q.empty()) {
            pci t = q.top(); q.pop();
            int num = t.second;
            while(num--) ans += t.first;
        }
        return ans;
    }
};