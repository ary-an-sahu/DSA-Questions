class Solution {
public:
    void generate(string s, int lc, int rc ,vector<string> &ans ,int n ){

        if(lc == n && rc == n){
            ans.push_back(s);
            return;
        }

        if(lc < n){
            generate(s + '(', lc+1 , rc, ans,n );
        }

        if(rc<lc){
            generate(s + ')' , lc , rc+1 , ans, n);
        }

    }


    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string s = "";
        generate(s, 0,0,ans, n);

        return ans;
    }
};