#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> a;
    string res;
    for (size_t i = 0; i < participant.size(); i++)
        a.insert({ participant[i], i });

    for (size_t i = 0; i < completion.size(); i++)
        a.erase(a.find(completion[i]));

    for (auto i : a)
        res = i.first;
   
    return res;
}
int main()
{
    vector<string> a{ "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> b{ "josipa", "filipa", "marina", "nikola" };

    string ss = solution(a,b);

    return 0;
}

