class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        typedef long long ll;
        ll xx = x, ans = 0;
        while(x > 0) {
            int t = x - (x/10)*10;
            ans = (ll) ans*10 + (ll) t;
            x /= 10;
        }
        return xx == ans;
    }
};