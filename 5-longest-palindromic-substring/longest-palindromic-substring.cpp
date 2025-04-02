class Solution {
public:

    // bool isPalindrome(string &s,int start,int end){
    //     while(start<end){
    //         if(s[start]!=s[end]){
    //             return false;
    //         }
    //         start++,end--;
    //     }
    //     return true;
    // }

    // string longestPalindrome(string s) {
    //     string ans="";
        
    //     for(int i=0;i<s.size();i++){
    //         for(int j=i;j<s.size();j++){
    //             if(isPalindrome(s,i,j)){
    //                 string t = s.substr(i,j-i+1);
    //                 ans= t.size()>ans.size()?t : ans;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    bool isPalindrome(string &s, int l, int h){

        

        while(l<=h){
            if(s[l]== s[h]){
                l++;
                h--;
            }

            else{
                return false;
            }
        }
        return true;

    }

    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            for(int j=i; j<s.size();j++){

                if(isPalindrome(s,i,j)){

                    string sub = s.substr(i,j-i+1);

                    ans = sub.size()> ans.size()? sub : ans;
                }
            }

        }

        return ans;

    }
};