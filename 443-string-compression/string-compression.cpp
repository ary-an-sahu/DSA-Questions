class Solution {
public:

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
                    //count reverse order me store hua hai
                    // mtlb 12 hai toh 21 hua hai
                    //isliye reverse karna hoga .
                    // start and index equal nhi kyoki index++ hua hai
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