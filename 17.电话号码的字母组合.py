#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#

# @lc code=start
class Solutiobaoffffsadfasdfff
    def letterCombinations(self, digits: str) -> List[str]:
        '''
        dfs
        combination 保存已经遍历的字符
        next_dights 保存剩下的数字
        '''

        phone = [
            "",
            "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"]
        

        def dfs(combination, next_dights):
            # 没有数字了 结束递归 将遍历的字符保存到结果当中
            if len(next_dights) == 0:
                res.append(combination) # res是list 不用说明是全局变量就可以修改
                return 
            
            # 遍历数字对应的字符串中的每个字符 将字符加到combination中
            # 使用右值可以不用修改combination
            for letter in phone[int(next_dights[0])]:
                dfs(combination + letter, next_dights[1:])
            

        res = []
        if digits:
            dfs("", digits)

        return res

# @lc code=end

