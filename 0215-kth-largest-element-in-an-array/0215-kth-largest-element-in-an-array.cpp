class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {

        //min heap creation
        priority_queue<int, vector<int> , greater<int>> pq;

        //we need to insert first k elements in min heap
        for(int i=0; i<k ;i++){
            pq.push(arr[i]);
        }    

        //now we have to only insert the greater element than top element in min heap
        //and if we gonna insert we need to pop the older top element and insert new

        for(int i=k ; i< arr.size() ; i++){
            int element = arr[i];
            if(element > pq.top()){
                pq.pop();
                pq.push(element);
            }
        }


        int ans = pq.top();
        return ans;
    }
};