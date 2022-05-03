#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;


string solution(int n) {
    string answer = "";

    while (n != 0)
    {
        int a = n % 3;
        n =  n / 3;
        
        if (a == 0)
        {
            answer += "4";
            n--;
        }
        else if (a == 1)
            answer += "1";
        else if (a == 2)
            answer += "2";
    }
    return answer;
}

int main()
{


    //vector<string>a{ "N~F=0", "R~T>2" };

    string ss = solution(10);

    return 0;
}

