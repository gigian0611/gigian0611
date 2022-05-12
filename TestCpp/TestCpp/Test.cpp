#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void get(vector<int>b, int depth, int n, int m, vector<vector<int>> &temp)
{

    if (m == 0)
    {
        temp.push_back(b);
        return;

    }

    for (size_t i = 0; i < m; i++)
    {
        swap(b[n], b[depth + i]);

        get(b, n + 1, depth + 1, m - 1, temp);

        swap(b[n], b[depth + i]);
    }
}

int solution(vector<int>b)
{

    vector<vector<int>> temp;

    get(b, 0, 0, b.size(), temp);


    return 3;
}
int main()
{


    //vector<vector<int>>a{ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int>b{ 1, 2, 3,4,5,6 };

    int ss = solution(b );

    return 0;
}

