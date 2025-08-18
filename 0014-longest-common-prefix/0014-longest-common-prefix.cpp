class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

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