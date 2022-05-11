#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;


string solution(string new_id) {
    string answer = "";

    int length = new_id.length();
    int dotCount = 0;
    for (size_t i = 0; i < length; i++)
    {
        char c = new_id[i];

        if (isupper(c))
            c = tolower(c);

        if (islower(c) == 0 && isdigit(c) == 0 && c != '-' && c != '_' && c != '.')
            c = NULL;
        else if (c == '.')
            dotCount++;
        else
            dotCount = 0;


        if (c != NULL && dotCount <= 1)
        {
            answer += c;
        }
    }

    if (answer.length() != 0 && answer[0] == '.')
        answer.erase(answer.begin());

    if (answer.length() != 0 && answer[answer.length() - 1] == '.')
        answer.erase(answer.end() - 1);

    if (answer.length() == 0)
        answer.push_back('a');

    if (answer.length() >= 16)
        answer.erase(answer.begin() + 15, answer.end());

    if (answer.length() != 0 && answer[0] == '.')
        answer.erase(answer.begin());

    if (answer.length() != 0 && answer[answer.length() - 1] == '.')
        answer.erase(answer.end() - 1);

    while (answer.length() <= 2)
    {
        answer += answer[answer.length() - 1];
    }

    return answer;
}

int main()
{


    //vector<string>a{ "N~F=0", "R~T>2" };

    string ss = solution("123_.def");

    return 0;
}

