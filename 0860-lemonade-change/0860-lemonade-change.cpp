class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;

        int n = bills.size();

        for(int i=0; i<n; i++){

            

            int remaining = bills[i] - 5;

            if(remaining > 0){

                if(remaining == 5){

                    if(mp[5] >= 1){
                        mp[5]--;
                    }else{
                        return false;
                    }

                }
                else if(remaining == 10){

                    if(mp[10]>= 1){
                        mp[10]--;
                    }
                    else if(mp[5] >= 2){
                        mp[5] = mp[5] -2;
                    }else{
                        return false;
                    }
                }

                else if(remaining == 15){
                    if(mp[10]>= 1 && mp[5]>= 1){
                        mp[10]--;
                        mp[5]--;
                    }else if(mp[5] >= 3){
                        mp[5] -= 3;
                    }else{
                        return false;
                    }
                }

            }


            mp[bills[i]]++;
        }

        return true;
    }
};