
#include <string>
#include <vector>
#include <cstring>
#include <map>
#pragma warning (disable : 4996)
using namespace std;

void swap(string& a, string& b)
{
    string temp = a;
    a = b;
    b = temp;
}

void solution(vector<string>&result, vector<string> data, int depth, int n, int m)
{
    if (depth >= m)
    {
        string str;

        for (int i = 0; i < m; i++)
            str += data[i];
        result.push_back(str);
        return;
    }
    else
    {
        for (int i = depth; i < n; i++)
        {
            swap(data[depth], data[i]);
            solution(result, data, depth + 1, n, m);
            swap(data[i], data[depth]);
        }
    }
}


int main()
{
    vector<string>a{ "a", "b", "c", "d"};

    vector<string> result;
    solution(result, a, 0, 4, 4);

    return 0;
}

