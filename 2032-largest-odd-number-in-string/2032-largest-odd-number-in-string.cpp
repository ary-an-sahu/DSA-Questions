class Solution {
public:
    string largestOddNumber(string num) {
        // Traverse from right to left
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1); // keep prefix ending at this odd digit
            }
        }
        return ""; // no odd digit found
    }
};
