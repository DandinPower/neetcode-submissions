class Solution {
public:
    bool isValid(string s) {
        vector<char> record;
        record.reserve(s.size());
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                record.push_back(ch);
            }
            else {
                char expected_ch;
                if (ch == ')') {
                    expected_ch = '(';
                }
                else if (ch == '}') {
                    expected_ch = '{';
                }
                else {
                    expected_ch = '[';
                }

                if (record.size() ==0 || record.back() != expected_ch) {
                    return false;
                }
                record.pop_back();
             }
        }
        if (record.size() > 0) {
            return false;
        }
        return true;
    }
};
