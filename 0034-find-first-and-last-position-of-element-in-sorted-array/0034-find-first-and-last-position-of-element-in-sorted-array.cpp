class Solution {
public:

    int firstOccur(vector<int>& nums, int target, int &firstOcc) {
        int s = 0, e = nums.size() - 1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                firstOcc = mid;
                e = mid - 1; // keep searching left for earlier occurrence
            }
            else if (nums[mid] < target) {
                s = mid + 1; // move right
            } 
            else {
                e = mid - 1; // move left
            }
        }
        return firstOcc;
    }

    int lastOccur(vector<int>& nums, int target, int &lastOcc) {
        int s = 0, e = nums.size() - 1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                lastOcc = mid;
                s = mid + 1; // keep searching right for later occurrence
            }
            else if (nums[mid] < target) {
                s = mid + 1; // move right
            } 
            else {
                e = mid - 1; // move left
            }
        }
        return lastOcc;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOcc = -1, lastOcc = -1;

        firstOccur(nums, target, firstOcc);
        lastOccur(nums, target, lastOcc);

        return {firstOcc, lastOcc};
    }
};
