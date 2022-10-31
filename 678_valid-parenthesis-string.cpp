class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star;
        stack<int> left;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                left.push(i);
            }
            if (c == '*') {
                star.push(i);
            }
            if (c == ')') {
                if (!left.empty()) {
                    left.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }

        while (!left.empty()) {
            int posL = left.top();
            if (star.empty()) return false;
            int posS = star.top();
            if (posS > posL) {
                star.pop();
                left.pop();
            } else {
                return false;
            }
        }

        return true;
    }
};
