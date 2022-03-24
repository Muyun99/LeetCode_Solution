class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if(size % 2 == 1)    return false;

        unordered_map<char, char> hashmap = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> charstack;
        
        
        for(int i = 0; i < size; ++i){
            if(hashmap.count(s[i]))
                if(charstack.empty() || charstack.top() != hashmap[s[i]])
                    return false;
                else
                    charstack.pop();
            
            else
                charstack.push(s[i]);
        }
        return charstack.empty();

    }
};