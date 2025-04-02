class Solution {
public:
    // int strStr(string haystack, string needle) {
    //     int n = haystack.size();
    //     int m = needle.size();

    //     for(int i=0;i<= n-m;i++){
    //         for(int j=0;j<m;j++){
    //             if(needle[j] !=haystack[i+j]){
    //                 break;
    //             }
    //             if(j== m-1){
    //                 return i;
    //             }
    //         }
    //     }
    //     return -1;
    // }

    int strStr(string haystack, string needle){
        
        // most easy method - 
        // return haystack.find(needle);

        for(int i=0; i<haystack.size();i++){
            for(int j=i; j<haystack.size();j++){

                string sub = haystack.substr(i,j-i+1);
                if(sub== needle){
                    return i;
                }
            }
        }
        return -1;


    }

};