class Solution {
public:
    int reverse(int x) {
        int f = 1;
        if(x == -2147483648) return 0;
        if(x < 0) { f = -1; x = -x; }
        int ans = 0;
        long long ans2 = 0;
        while(x > 0) {
            int t = x - (x/10)*10;
            ans2 = (long long) ans2 * 10 + (long long) t;
            if(ans2 > 2147483647) return 0;
            ans = ans*10+t;
            x /= 10;
        }
        // if(ans2 > 2147483647) return 0;
        return f*ans;
    }
};