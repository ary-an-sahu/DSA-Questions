class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        //first windown process
        for(int i=0;i<k;i++){
            int element = nums[i];
            // ye element queue ke andar innsert hoga hi hoga
            //pr abhi tk jitni queue bni hui hai usme check kro faltu element koin hai
            //faltu -> chote elements
            // hume unhe pop krna hai

            while(!dq.empty() && nums[dq.back()]<element){
                dq.pop_back();
            }

            //current element ko insert kro
            dq.push_back(i);
        }
        //get answer for first window
        int index = dq.front();
        int element = nums[index];
        ans.push_back(element);


        //process remaining window 
        for(int i =k ; i<nums.size();i++){
            //removal
            if(i-dq.front()>=k ){
                dq.pop_front();
            }

            //addition
            int element = nums[i];
            while(!dq.empty() && nums[dq.back()]< element){
                dq.pop_back();
            }

            //current element ko insert kro
            dq.push_back(i);


            // store ans
            int index = dq.front();
            int ansElement = nums[index];
            ans.push_back(ansElement);

        }
        return ans; 
    }
};