class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        if(n!= m )return false;
        //now if we think then can s+s contain goal if yes then its true or its false otherwise.

        string newS = s+s;

        string temp;
        if(newS.find(goal) != string::npos){
            return true;
        }

        return false;





    }
};