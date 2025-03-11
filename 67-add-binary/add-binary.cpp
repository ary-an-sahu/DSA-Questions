class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i = a.size() - 1 , j = b.size() - 1;
        string ans;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry)  
        {
            int bit1 = (i >= 0) ? a[i--] - '0' : 0;
            int bit2 = (j >= 0) ? b[j--] - '0' : 0;
            int sum = bit1 ^ bit2 ^ carry;
            // ans = to_string(sum) + ans;
            ans.push_back(sum + '0');
            carry = (bit1 & bit2) | (bit2 & carry) | (carry & bit1);
        }
        if (carry) 
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};