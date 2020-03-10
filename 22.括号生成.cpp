/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start


// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

class Solution {
public:

    void dfs(int left, int right, int n, string &comb, vector<string> &res)
    {
        if(left == n && right == n) {
            res.push_back(comb);
            return;
        }

        if(left < n) {
            comb.push_back('(');
            dfs(left+1, right, n, comb, res);
            comb.pop_back();
        }

        if(right < left) {
            comb.push_back(')');
            dfs(left, right+1, n, comb, res);
            comb.pop_back();
        }
        
        
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string comb;
        dfs(0, 0, n, comb, res);

        return res;

    }
};
// @lc code=end

