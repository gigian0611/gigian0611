#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int length = moves.size();
    int length2 = board.size();

    vector<int>select;

    for (size_t i = 0; i < length; i++)
    {
        int index = moves[i] - 1;

        for (size_t j = 0; j < length2; j++)
        {
            int index2 = board[j][index];

            if (index2 != 0)
            {
                board[j][index] = 0;
                
                if (select.size() == 0)
                    select.push_back(index2);
                else
                {
                    if (select[select.size() - 1] == index2)
                    {
                        select.erase(select.end() - 1);
                        answer+=2;
                    }
                    else 
                        select.push_back(index2);
                }

                break;
            }
        }
    }

    return answer;
}

int main()
{


    vector<vector<int>>a{ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int>b{ 1, 5, 3, 5, 1, 2, 1, 4 };

    int ss = solution(a,b );

    return 0;
}

