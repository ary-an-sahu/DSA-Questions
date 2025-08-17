class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>narr;

        int i=0;
        int j =0;

        while(i<m && j<n){

            if(nums1[i]> nums2[j]){
                narr.push_back(nums2[j]);
                j++;
            }else{
                narr.push_back(nums1[i]);
                i++;
            }
        }

        while(i<m){
            narr.push_back(nums1[i]);
            i++;
        }

        while(j<n){
            narr.push_back(nums2[j]);
            j++;
        }

        int k = m+n;
        double median = 0;

        if(k %2 == 0){
            int first = narr[k/2 - 1];
            int second = narr[k/2];

            median = (first+ second)/2.0;
            
        }else{

            median = narr[(k+1)/2 - 1 ];
        }

        return median;
    }
};