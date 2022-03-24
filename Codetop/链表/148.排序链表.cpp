// 一刷：2022 03 19 会做

// 直接用栈模拟
// 时间复杂度：O(n)
// 空间复杂度：O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> charstack;
        int size = s.size();
        char top;
        for(int i = 0; i < size; ++i){
            if(s[i] == '}'){
                if(charstack.empty() || charstack.top() != '{')
                    return false;
                else
                    charstack.pop();
            }
            else if(s[i] == ')'){
                if(charstack.empty() || charstack.top() != '(')
                    return false;
                else
                    charstack.pop();
            }
            else if(s[i] == ']') {
                if(charstack.empty() || charstack.top() != '[')
                    return false;
                else
                    charstack.pop();
            }
            else 
                charstack.push(s[i]);
        }
        if(charstack.empty())
            return true;
        else
            return false;
    }
};

// 用字典+栈
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};