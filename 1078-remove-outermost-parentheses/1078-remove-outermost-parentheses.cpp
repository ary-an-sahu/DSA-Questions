class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int cnt = 0;

        if(s.empty()){
            return "";
        }

        vector<string>store;
        int start =0;

        for(int i=0; i<n ; i++){

            if(s[i] == '('){
                cnt++;
                
            }else if(s[i] == ')'){
                cnt --;
            }

            if(cnt == 0){
                string sym = s.substr(start, i - start +1);
                store.push_back(sym);
                start = i+1;
            }

        }
        string final = "";
        for(int i=0; i<store.size();i++){
            int len = store[i].size();

            string stt = store[i].substr(1,len-2);
            final += stt;
        }

        return final;
    
    }
};