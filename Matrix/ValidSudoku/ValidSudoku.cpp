#include "ValidSudoku.h"
#include <unordered_map>
#include <unordered_set>

bool ValidSudoku::Solve(std::vector<std::vector<char>>& board)
{
    if(board.size() != 9)
      return false;

    std::unordered_map<int, char> map;
    for(size_t i = 0; i < board.size(); ++i)
    {
        if(board[i].size() != 9)
            return false;

        for(size_t j = 0; j < board[i].size(); ++j)
        {
            int key = (i+1) * 10 + j + 1;
            map[key] = board[i][j];
        }
    }
    bool bResult = true;

    std::vector<std::unordered_set<char>> colSets;
    for(int i = 0; i < 9; ++i)
    {   
        for(int j = 0; j < 9; ++j)
        {
            std::unordered_set<char> rowSet;
            int key = (i+1)*10 + j + 1;
            char ch = map[key];
            if (ch = '.')
              continue;
            if (rowSet.count(ch))
            {
                return false;
            }else
            {
                rowSet.insert(ch);
            }

        }
    }
}