#include<vector>
//merge sort
class Solution {
public:

    void merge(std::vector<int> &count, std::vector<std::pair<int, int>> &arr, int left, int mid, int right) {

        std::vector<std::pair<int, int>> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        int rightSideSmaller = 0;

        while(i <= mid && j <= right) {

            if(arr[i].first <= arr[j].first) {
                count[arr[i].second] += rightSideSmaller;
                temp[k++] = arr[i++];
            }  else {
                rightSideSmaller++;
                temp[k++] = arr[j++];
            }

        }

        while(i <= mid) {
            count[arr[i].second] += rightSideSmaller;
            temp[k++] = arr[i++];
        }

        while(j <= right) {
            temp[k++] = arr[i++];
        }

        for(int i = left; i <= right; i++) {
            arr[i] = temp[i - left];
        }

    }

 //  void mergeSort(std::vector<int> &count, std::vector<std::pair<int, int>> &arr, int left, int right) {

       // if(left >= right) {
       //     return;
     //   }
        
    //    int mid = left + (right-left)/2;
       // mergeSort(count, arr, left, mid);
      //  mergeSort(count, arr, mid+1, right);
      //  merge(count, arr, left, mid, right);

   // }

    std::vector<int> countSmaller(std::vector<int>& nums) {

        int n = nums.size();
        std::vector<std::pair<int, int>> arr(n);

        for(int i = 0; i < n; i++) {
           // arr[i] = makePair(nums[i], i);
        }

        std::vector<int> count(n, 0);
        mergeSort(count, arr, 0, n-1);
        return count;
        
    }

};