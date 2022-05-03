//https://ansohxxn.github.io/algorithm/combination/
#include <string>
#include <vector>
#include <cstring>
#include <map>
#pragma warning (disable : 4996)
using namespace std;

void solution(vector<string>&result, vector<string> data,int depth, int n, int m)
{
    if (m == 0)
    {
        string sum;
        for (int i = 0; i < depth; i++)
        {
            sum += data[i];
        }
        result.push_back(sum);
        //
        return;
    }
        

    if (n == data.size())
        return;

    data[depth] = data[n];
    solution(result, data, depth + 1, n + 1, m - 1);
    solution(result, data, depth, n + 1, m);
}


int main()
{
    vector<string>a{ "a", "b", "c", "d", "e"};

    vector<string> result;
    solution(result, a,0, 0, 5);

    return 0;
}

