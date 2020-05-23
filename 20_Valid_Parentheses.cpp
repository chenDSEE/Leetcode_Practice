class Solution {
public:
    bool isValid(string s) {
//        if (s.size() % 2 == 1)
//            return false;
// work by "return tmp_stack.empty()"

        stack<char> tmp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                tmp.push(')');
            else if (s[i] == '[')
                tmp.push(']');
            else if (s[i] == '{')
                tmp.push('}');
            else {
                if (tmp.empty() && s[i] != tmp.top())
                    return false;
                else
                    tmp.pop();
            }
        }

        return tmp.empty();
    }
};