class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int balance =0;
        int deficit =0;

        // for(int i=0; i<gas.size();i++){

        //     balance = balance + gas[i] - cost[i];

        //     if(balance < 0 ){
        //         deficit+= abs(balance);
        //         //iska mtlb hum aage nhi jaa payenge 
        //         // iska matlab start ko update kro 
        //         start = i+1;
        //         //deficit hai toh balance ko agle wale ke liye fir se 0 kr do
        //         balance =0;
        //     }
        // }

        // if(balance - deficit >=0){
        //     //cycle successfully complete ho gya h
        //     return start;
        // }

        // else{
        //     //cycle complete nhi ho paya for any element taking as a start
        //     return -1;
        // }


        //method 2 - 

        for(int i=0; i<gas.size();i++){

            if(balance+ gas[i]< cost[i]){
                deficit = deficit + abs(balance+ gas[i]- cost[i]);
                //is case me aage jana hoga ie start ko aage badhna hoga
                start = i+1;
                balance =0;
            }
            else{
                balance  = balance+ gas[i]- cost[i] ;
            }
        }

        if(balance - deficit >= 0){
            return start;
        }
        else{
            return -1;
        }


        
    }
};