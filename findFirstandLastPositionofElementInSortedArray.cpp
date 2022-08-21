#include<vector>

// Binary search solution

class Solution {
public:

    std::vector<int> searchRange(std::vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int start = -1;
        int end = -1;

        std::vector<int> ans;

        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] == target) {
                int temp = mid;

                while(mid > 0 && nums[mid-1] == target) {
                    mid--;
                }
                start = mid;
                while(temp < nums.size()-1 && nums[temp+1] == target) {
                    temp++;
                }
                end = temp;

                ans.push_back(start);
                ans.push_back(end);
                return ans;

            } else if(nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        ans.push_back(-1);
        ans.push_back(-1);

        return ans;

    }
};