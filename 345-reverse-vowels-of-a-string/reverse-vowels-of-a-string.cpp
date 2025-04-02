class Solution {
public:

    // bool isVowel(char ch){
    //     ch = tolower(ch);
    //     return ch=='a'|| ch== 'e'||ch == 'i'|| ch=='o'|| ch=='u';
    // }

    // string reverseVowels(string s) {
    //     int l=0, h= s.size()-1;

    //     while(l<h){
    //         if(isVowel(s[l])&& isVowel(s[h])){
    //             swap(s[l],s[h]);
    //             l++,h--;
    //         }

    //         else if(isVowel(s[l])== 0){
    //             l++;
    //         }

    //         else{
    //             h--;
    //         }
    //     }
    //     return s;

    // }
    bool isVowel(char ch){
        if(ch=='a'|| ch=='A'|| ch=='e'|| ch=='E' || ch=='i'|| ch=='I' || ch=='o'|| ch=='O' || ch=='u'|| ch=='U'){

            return true;
        }

        else{
            return false;
        }
    }

    string reverseVowels(string s){
        int l =0;
        int h= s.size()-1;
        
        while(l<=h){
            if(isVowel(s[l]) && isVowel(s[h])){
                swap(s[l], s[h]);
                l++;
                h--;
            }

            else if(isVowel(s[l])){
                // s[h] -> not a vowel 
                h--;
            }
            else{
                l++;
            }
        }

        return s;

    }
};