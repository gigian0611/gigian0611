#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;


long long solution(int w, int h) {
    long long answer = 1;

    int r;
    int a = w;
    int b = h;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return (w * h) - (w + h - a);
}

int main()
{


    //vector<string>a{ "N~F=0", "R~T>2" };

    int a = solution(8, 12);

    return 0;
}

