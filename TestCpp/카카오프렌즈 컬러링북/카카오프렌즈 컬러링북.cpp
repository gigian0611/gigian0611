
#include <string>
#include <vector>
#include <cstring>
#include <map>
#pragma warning (disable : 4996)
using namespace std;

int start_picture(vector<vector<int>> &picture, int m, int n, int x, int y, int item)
{
    if (x >= m || x < 0)
        return 0;
    else if (y >= n || y < 0)
        return 0;

    int curt = picture[x][y];

    if (curt != item)
        return 0;

    picture[x][y] = 0;

    //╩С
    int a = start_picture( picture, m, n, x - 1, y, curt);
    //го
    int b = start_picture( picture, m, n, x + 1, y, curt);
    //аб
    int c = start_picture( picture, m, n, x, y - 1, curt);
    //©Л
    int d = start_picture( picture, m, n, x, y + 1, curt);

    return a + b + c + d + 1;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] == 0)
                continue;
            else
            {
                number_of_area++;
                int temp = start_picture(picture, m, n, i, j, picture[i][j]);
                if (temp > max_size_of_one_area)
                    max_size_of_one_area = temp;
            }
        }
    }



    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}


int main()
{
    vector<vector<int>>a{ {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} };

    //1, 1, 1, 1, 1
    solution(6,4, a);

    return 0;
}

