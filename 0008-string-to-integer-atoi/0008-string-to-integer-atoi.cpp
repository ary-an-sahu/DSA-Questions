class Solution {
public:
    int myAtoi(string s) {

        int i = 0, sign = 1;
        long ans = 0;

        // skip spaces safely
        while (i < s.size() && s[i] == ' ')
            i++;

        if (i == s.size()) return 0;

        s = s.substr(i);

        // sign
        if (s[0] == '-')
            sign = -1;

        i = (s[0] == '-' || s[0] == '+') ? 1 : 0;

        while (i < s.size() && isdigit(s[i])) {

            if (ans > INT_MAX / 10 ||
               (ans == INT_MAX / 10 && s[i] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        return sign * ans;
    }
};
