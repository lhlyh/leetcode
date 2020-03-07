/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

// #include <vector>
// #include <string>
// using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> letter = {
            "",
            "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"};

        vector<string> res;

        if(digits.size() == 0)
            return res;

        string s;
        dfs(0, res, s, digits, letter);
        return res;
    }

    void dfs(int index, vector<string> &res, string &s, const string &digits, const vector<string> &letter)
    {
        if(index == digits.size())
        {
            res.push_back(s);
            return;
        }

        for(const char &let : letter[digits[index]-'0'])
        {
            s.push_back(let);
            dfs(index+1, res, s, digits, letter);
            s.pop_back();
        }
        
    }
};
// @lc code=end

