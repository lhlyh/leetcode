/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start

// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

class Solution {
public:

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void reverse(vector<int>& nums, int begin) {
        int i = begin, j = nums.size() - 1;
        while(i < j) {
            swap(nums, i, j);
            i++, j--;
        }

    }
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();

        for(int i = len-1; i > 0; i--) {
            if(nums[i] > nums[i-1]) {
                reverse(nums, i);
                for(int j = i; j < len; j++) {
                    if(nums[j] > nums[i-1]) {
                        swap(nums, i-1, j);
                        return;
                    }
                }
            }
        }
        reverse(nums, 0);
    }
};

// int main() {

//     Solution s;
//     vector<int> nums = {1,2,3};
//     s.nextPermutation(nums);
//     for(auto & num : nums) {
//         cout << num << " ";
//     }
//     cout << endl;
// }
// @lc code=end

