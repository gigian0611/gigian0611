#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;


int solution(vector<int> nums)
{
    int answer = 0;

    int count = nums.size() * 0.5f;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    if (count <= nums.size())
        answer = count;
    else
        answer = nums.size();

    return answer;
}
int main()
{


    //vector<vector<int>>a{ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int>b{ 3, 1, 2, 3 };

    int ss = solution(b );

    return 0;
}

