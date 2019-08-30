class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0) return 0;
        auto it = str.begin();
        while(*it == ' ') str.erase(it);
        if(str.length() == 0) return 0;
        int st = 0, f = 1;
        long long x = 0;
        if(str[0] == '+') {
            f = 1; st++;
        }
        else if(str[0] == '-') {
            f = -1; st++;
        }
        for(int i = st; i < str.length(); i++) {
            if(!('0' <= str[i] && str[i] <= '9'))
                return (int) x*f;
            x = x * 10 + str[i] - '0';
            if(f == 1 && x > 2147483647) return 2147483647;
            if(f == -1 && x > 2147483647) return -2147483648;
        }
        return (int) x*f;
    }
};