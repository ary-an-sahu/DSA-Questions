class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mps;
        unordered_map<char,int>mpt;
        int n = s.size();
        int m = t.size();

        if(n != m)return false;

        for(int i=0; i<n;i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }  

        for(int i=0; i<m ;i++){
            if(mps[s[i]] != mpt[s[i]]){
                return false;
            }
        }

        return true;

         
    }
};