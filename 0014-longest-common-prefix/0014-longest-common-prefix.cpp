class Solution {
public:
    //optimized approach
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        //sorting is done so that first and last element can differ much and common between them can be extracted without finding the common of middle element between them.
        sort(strs.begin(), strs.end());

        string first = strs[0];
        int l1 = first.length();
        string last = strs[strs.size() -1];
        int l2 = last.length();

        int size = min(l1, l2);
        string word = "";

        for(int i=0; i<size; i++){

            if(first[i] == last[i]){
                word += first[i];
            }
            else{
                break;
            }
        }

        
        return word;
    }
};