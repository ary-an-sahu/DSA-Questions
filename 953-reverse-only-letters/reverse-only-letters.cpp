class Solution {
public:
    // string reverseOnlyLetters(string s) {
    //     int l=0;
    //     int h = s.size()-1;

    //     while(l<h){
    //         if(isalpha(s[l]) && isalpha(s[h])){
    //             swap(s[l],s[h]);
    //             l++;
    //             h--;

    //         }

    //         else if(!isalpha(s[l])){
    //             //s[l] ---> non - alphabet 
    //             l++;
    //         }

    //         else{
    //             // s[h] --> non - alphabet 
    //             h--;
    //         }


    //     }
    //     return s;
    // }

    string reverseOnlyLetters(string s){
        int l= 0;
        int h = s.size() -1;

        while(l<=h){
            


            if(isalpha(s[l]) && isalpha(s[h])){
                swap(s[l],s[h]);
                l++;
                h--;
            }

            else if(isalpha(s[l])){
                h--;
            }
            else{
                l++;
            }
        }
        return s;
    }

};