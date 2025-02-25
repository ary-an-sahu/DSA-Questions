class Solution {
public:

    void solve(string &output,unordered_map<char,string> mapping,vector<string> &ans,string digits, int i){
        //base case -

        if(i>= digits.length()){
            if(output.length()>0){
                ans.push_back(output);
            }
        }

        //ek case hum solve karenge aur baki recursion kar dega-

        char digit = digits[i];
        string mappedString = mapping[digit];

        for(char ch: mappedString){
            //har character ke liye recursive call marnin hai 
            output.push_back(ch);
            solve(output,mapping, ans, digits,i+1);
            // backtrack code
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;

        unordered_map<char,string> mapping ;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        string output = "";
        int i =0;

        solve(output,mapping,ans,digits,i);
        return ans;

    }
};