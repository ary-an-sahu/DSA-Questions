class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // the freq of each elememt

        unordered_map<int,int> freqMap;
        for(auto num: nums){
            freqMap[num]++;
        }
        
        // pair<int,int> -> shows => freq, num
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> minHeap;

        for(auto entry: freqMap){
            minHeap.push({entry.second , entry.first});
            if(minHeap.size() > k){
                minHeap.pop(); //removing the least frequent element
            }
        }

        // at this point my min heap has top k element
        vector<int> ans;
        while(!minHeap.empty()){
            // pair<int,int> top = minHeap.top();
            // auto top = minHeap.top();

            auto [freq, num] = minHeap.top();
            minHeap.pop();
            // ans.push_back(top.second);
            ans.push_back(num);
        }

        return ans;

    }
};