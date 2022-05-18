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
    //vector<string> a{ "marina", "josipa", "nikola", "vinko", "filipa" };
    //vector<string> b{ "josipa", "filipa", "marina", "nikola" };

    //string ss = solution(a,b);


    int r, g, b, src, dst, res;
    float dstR, dstG, dstB, srcA, srcR, srcG, srcB;

    srcA = 128 / 255.0f;
    srcR = 199;
    srcG = 147;
    srcB = 72;

    dstR = 132;
    dstG = 199;
    dstB = 68;

    r = (srcR - dstR) * srcA + dstR;
    g = (srcG - dstG) * srcA + dstG;
    b = (srcB - dstB) * srcA + dstB;

    res = r | g | b;

    return 0;
}

