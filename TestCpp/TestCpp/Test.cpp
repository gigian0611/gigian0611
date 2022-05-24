#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#pragma warning (disable : 4996)
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    int length = stages.size();
    vector<int> stop;
    vector<int> up;
    map<int, float> temp;

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 0; j < length; j++)
        {
            int item = stages[j];
            if (i >= item && i - 1 < item)
                stop.push_back(j);
            else if (i - 1 < item)
                up.push_back(j);
        }

        int stop_size = stop.size();
        int up_size = up.size();
        float fail = float(stop_size / float(up_size + stop_size));

        temp.insert({i, fail});
    
        stop.clear();
        up.clear();
    }

    vector<pair<int, float>> vec(temp.begin(), temp.end());

    sort(vec.begin(), vec.end(), [](const pair<int, float>& a, const pair<int, float>& b)
    {
        if (a.second > b.second)
            return true;
        else if (a.second == b.second)
        {
            if (a.first > b.first)
                return false;
            else
                return true;
        }
        else
            return false;
    });

    for (auto i : vec)
        answer.push_back(i.first);
    return answer;
}
int main()
{
    vector<int> a{ 2, 1, 2, 6, 2, 4, 3, 3 };
    //vector<string> b{ "stanko", "ana", "mislav" };

    vector<int> ss = solution(5,a);


    return 0;
}

