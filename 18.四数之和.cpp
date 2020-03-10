/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int len = nums.size();
        if(len < 4)
            return res;

        bool last_i_flag = false;

        for(int i = 0; i < len; i++) {
            
            if(last_i_flag && nums[i] == nums[i-1])
                continue;
            last_i_flag = true;
            bool last_j_flag = false;

            for(int j = i + 1; j < len; j++) {

                if(last_j_flag && nums[j] == nums[j-1])
                    continue;
                last_j_flag = true;

                int m = j + 1;
                int n = len - 1;

                bool last_m_flag = false;

                while(m < n) {
                    int sum = nums[i] + nums[j] + nums[m] + nums[n];
                    if(sum == target) {
                        if(!last_m_flag || (nums[m] != nums[m-1])){
                            res.push_back({nums[i], nums[j], nums[m], nums[n]});
                        }
                        last_m_flag = true;
                        m++;
                        n--;
                    }
                    else if(sum > target) {
                        last_m_flag = false;
                        n--;
                    }
                    else {
                        last_m_flag = false;
                        m++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

