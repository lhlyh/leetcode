/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start


// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        short raw[9] = {0};
        short col[9] = {0}; 
        short square[9] = {0};

        for(char i = 0; i < 9; i++) {
            for(char j = 0; j < 9; j++) {
                if(board[i][j] >= '0' && board[i][j] <= '9') {
                    short res = 1<<(board[i][j]-'0');
                    if((raw[i] & res) || (col[j] & res) || (square[3*(i/3) + j/3] & res)) {
                        return false;
                    }
                    raw[i] |= res;
                    col[j] |= res;
                    square[3*(i/3) + j/3] |= res;
                }
            }
        }
        return true;
    }
};

// int main() {
//     vector<vector<char>> board = {
//         {'5','3','.','.','7','.','.','.','.'},
//         {'6','.','.','1','9','5','.','.','.'},
//         {'.','9','8','.','.','.','.','6','.'},
//         {'8','.','.','.','6','.','.','.','3'},
//         {'4','.','.','8','.','3','.','.','1'},
//         {'7','.','.','.','2','.','.','.','6'},
//         {'.','6','.','.','.','.','2','8','.'},
//         {'.','.','.','4','1','9','.','.','5'},
//         {'.','.','.','.','8','.','.','7','9'}};

//     Solution s;
//     s.isValidSudoku(board);
// }
// @lc code=end

