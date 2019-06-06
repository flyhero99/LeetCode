class Solution {
public:
    typedef pair<int, int> pii;
    pii a[100005];
    string convert(string s, int numRows) {
        if(s.length()==0 || numRows==1) return s;
        int i = 0, x = 1, y = 1, up = 1;
        while(i < s.length()) {
            if(up) {
                while(i < s.length() && x < numRows) {
                    a[++i] = make_pair(x++, y);
                }
                up = 0;
            }
            else {
                while(i < s.length() && x > 1) {
                    a[++i] = make_pair(x--, y++);
                }
                up = 1;
            }
        }
        // for(int ii = 1; ii <= i; ii++) {
        //     cout << a[ii].first << ' ' << a[ii].second << endl;
        // }
        string ans = "";
        for(int ii = 1; ii <= numRows; ii++) {
            for(int jj = 1; jj <= i; jj++) {
                // cout << "a[jj].first: " << a[jj].first << " ii: " << ii << endl;
                if(a[jj].first == ii) ans.push_back(s[jj-1]);
            }
        }
        // cout << endl;
        return ans;
    }
};