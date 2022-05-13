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

void get(vector<int>a, vector<int>b, int n, int m, vector<vector<int>>& temp)
{
    if (m == 0)
    {
        temp.push_back(a);
        return;
    }

    if (n >= b.size())
    {
        return;
    }

    a.push_back(b[n]);
    get(a, b, n + 1, m - 1,temp);

    a.pop_back();
    get(a, b, n + 1, m, temp);
}

int solution(vector<int>b)
{

    vector<vector<int>> temp;

    vector<int> a;
    get(a, b, 0, 4, temp);
    
       
   

    return temp.size();
}
int main()
{
    vector<int>b{ 1, 2, 3,5,6,7 };

    int ss = solution(b );

    return 0;
}

