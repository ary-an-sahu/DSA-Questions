class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &v){

        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size(),-1);
        
        for(int i = v.size()-1; i>=0; i--){
            while(st.top()!= -1 && v[st.top()]>v[i] ){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }


    vector<int> prevSmallerElement(vector<int> &v){

        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size(),-1);
        
        for(int i = 0; i<v.size(); i++){
            while(st.top()!= -1 && v[st.top()]>=v[i] ){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
      auto prev =  prevGreaterElement(arr);
      auto next =  nextGreaterElement(arr); 

      long long sum =  0;
    //   const int mod = 1e9 + 7;

      for(int i =0 ; i<arr.size();i++){
        long long previ = prev[i];
        long long nexti = next[i]==-1 ? arr.size() : next[i];
        long long left = i-previ;
        long long right = nexti - i;

        sum = sum + left* right * arr[i];
      }
      return sum;

    }

    vector<int> nextGreaterElement(vector<int> &v){

        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size(),-1);
        
        for(int i = v.size()-1; i>=0; i--){
            while(st.top()!= -1 && v[st.top()]<v[i] ){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }


    vector<int> prevGreaterElement(vector<int> &v){

        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size(),-1);
        
        for(int i = 0; i<v.size(); i++){
            while(st.top()!= -1 && v[st.top()]<=v[i] ){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }



    long long sumSubarrayMaxs(vector<int>& arr) {
      auto prev =  prevSmallerElement(arr);
      auto next =  nextSmallerElement(arr); 

      long long sum =  0;
    //   const int mod = 1e9 + 7;

      for(int i =0 ; i<arr.size();i++){
        long long previ = prev[i];
        long long nexti = next[i]==-1 ? arr.size() : next[i];
        long long left = i-previ;
        long long right = nexti - i;
        // long long no_of_times = ((left% mod) * (right%mod)) % mod;
        // long long total = (no_of_times * arr[i])% mod;
        // sum = (sum + total)% mod;
        sum = sum + left* right * arr[i];
      }
      return sum;

      
     

    }

    long long subArrayRanges(vector<int>& nums) {
        auto sumOfMaximums = sumSubarrayMaxs(nums);
        auto sumOfMinimums = sumSubarrayMins(nums);

        return  sumOfMinimums - sumOfMaximums ;
    }
};