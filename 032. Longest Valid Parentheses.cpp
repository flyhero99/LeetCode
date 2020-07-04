#define fi first
#define se second
#define mp make_pair
typedef pair<int, char> pic;


// 相比于普通的括号匹配，要解决的问题：（（（）（）这种连续多个()，如何把长度叠加
// 直接做法。思路：用栈存左括号下标，每次遇到右括号时更新长度 / 更新起点
// 1. 遇到左括号：下标入栈
// 2. 遇到右括号：
//    2.1 栈为空：说明上来就不符合，直接start = index + 1，前移一格
//    2.2 栈不为空：取出一个作为当前的匹配。此时：
//        2.2.1 取出后栈为空：max_len = max(max_len, index-start+1)
//        2.2.2 取出后栈不为空，相当于前一个左括号后面的都纳入计算：max_len = max(max_len, index-stack.top())
// start的目的是记录（）（）这种连续匹配时的栈为空的话先前被取出的开头左括号。如果栈不为空则可以用取出后的栈顶元素计算。

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int start = 0, max_len = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(st.empty())
                    start = i+1;
                else {
                    st.pop();
                    if(st.empty())
                        max_len = max(max_len, i-start+1);
                    else // 截止到前一个左括号（即栈顶元素），后面都是本次的匹配长度
                        max_len = max(max_len, i-st.top());
                }
            }
        }
        return max_len;
    }
};