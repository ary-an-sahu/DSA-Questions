class Solution {
public:
    // int compress(vector<char>& s) {
    //     int index=0, count=1;
    //     char prev = s[0];
         
    //     for(int i=1;i<s.size();++i){
    //         if(s[i]==prev){
    //             count++;
    //         }
    //         else{
    //             s[index++]=prev;
    //             if(count>1){
    //                 int start = index;
    //                 while(count){
    //                     s[index++] = (count%10)+ '0';
    //                     count/=10;
    //                 }
    //                 reverse(s.begin()+ start,s.begin()+index);
    //             }
    //             prev = s[i];
    //             count=1;
    //         }
    //     }
    //     s[index++] = prev;
    //     if(count>1){
    //         int start = index;
    //         while(count){
    //             s[index++] = (count%10)+ '0';
    //             count/=10;

    //         }
    //         reverse(s.begin()+ start,s.begin()+index);

    //     }
    //     return index;
    // }

    // int compress(vector<char>& s){
    //     int prev =0;
    //     int next = 1;
    //     vector<char>ans;

    

    //     for(int i=0; i<s.size(); i++){
    //         int count =1;
    //         if(s[prev] == s[next] && (prev< s.size() && next< s.size())){
    //             count++;
    //             prev++;
    //             next++;
    //         }
    //         ans.push_back(s[i]);
    //         if(count>=10){
    //             while(count--){
    //                 ans.push_back(count%10);
    //                 count/=10;
    //             }
    //         }
    //         else{
    //             if(count!= 1){
    //                 ans.push_back(count);
    //             }
    //         }

    //         count= 1;
    //         if(s[prev]!= s[next] && (prev< s.size() && next< s.size())){
    //             prev++;
    //             next++;
    //         }

    //     }
    //     // ans.reverse();
    //     return ans.size();
            
    
    // }

    int compress(vector<char>& s){

        int index =0;
        int count =1;
        char prev =s[0];

        for(int i=1;i<s.size();i++){
            if(s[i] == prev){
                count++;
            }
            else{
                s[index++] = prev;
                if(count >1){
                    int start = index;
                    while(count){
                        
                        s[index++] = count%10 + '0';
                        count/=10;
                    }
                    reverse(s.begin()+ start, s.begin()+index);
                    
                }
                prev = s[i];
                count = 1;
            }
        }
        // out of bound hone ke baad - 
        //for last element we have to store it separately as it is ignored in loop - 

        s[index++] = prev;
        if(count>1){
            int start = index;
            while(count){
                
                s[index++] = count%10 + '0';
                count/=10;
            }
            reverse(s.begin()+ start, s.begin()+index);
        }

        return index;
    }
};