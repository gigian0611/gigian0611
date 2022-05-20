#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#pragma warning (disable : 4996)
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> a;
    string res, temp;
    int length = participant.size();

    for (int i = 0; i < length; i++)
    {
        temp = participant[i];
        if (!a.count(temp))
            a.insert({ temp, 1 });
        else
            a[temp]++;

    }

    length = completion.size();
    for (int i = 0; i < length; i++)
    {
        temp = completion[i];
        a[completion[i]]--;
    }

    for (auto i : a)
    {
        if (i.second == 1)
        {
            res = i.first;
            break;
        }
    }

            
    return res;
}
int main()
{
    vector<string> a{ "mislav", "stanko", "mislav", "ana" };
    vector<string> b{ "stanko", "ana", "mislav" };

    string ss = solution(a,b);


    return 0;
}

