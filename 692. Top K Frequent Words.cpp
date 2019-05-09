class Solution {
public:
    typedef pair<string, int> psi;
    
    struct qcmp {
        bool operator () (const psi &a, const psi &b) const {
            if(a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        }
    };
    
    map<string, int> mp;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(int i = 0; i < words.size(); i++) {
            if(mp.count(words[i]) == 0) {
                mp.insert(make_pair(words[i], 1));
            }
            else {
                mp[words[i]]++;
            }
        }
        priority_queue<psi, vector<psi>, qcmp> q;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            cout << it->first << ": " << it->second << endl;
            q.push(*it);
        }
        vector<string> ans;
        while(k-- && !q.empty()) {
            psi t = q.top(); q.pop();
            ans.push_back(t.first);
        }
        return ans;
    }
};