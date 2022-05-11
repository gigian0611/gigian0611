#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;


string solution(vector<int> numbers, string hand) {
    string answer = "";

    int L[2]{ 3,0 };
    int R[2]{ 3,2 };
    int length = numbers.size();

    for (size_t i = 0; i < length; i++)
    {
        int number = numbers[i];

        if (number == 1 || number == 4 || number == 7)
        {
            if (number == 1)
                L[0] = 0;
            else if (number == 4)
                L[0] = 1;
            else
                L[0] = 2;
            
            L[1] = 0;
            answer += "L";
        }

        else if (number == 3 || number == 6 || number == 9)
        {
            if (number == 3)
                R[0] = 0;
            else if (number == 6)
                R[0] = 1;
            else
                R[0] = 2;

            R[1] = 2;
            answer += "R";
        }

        else
        {
            int n = 0, m = 1;
            if (number == 2)
                n = 0;
            else if (number == 5)
                n = 1;
            else if (number == 8)
                n = 2;
            else
                n = 3;

            int resultL = (abs(L[0] - n) + abs(L[1] - m));
            int resultR = (abs(R[0] - n) + abs(R[1] - m));

            if (resultL < resultR)
            {
                L[0] = n;
                L[1] = m;
                answer += "L";
            }
            else if (resultL > resultR)
            {
                R[0] = n;
                R[1] = m;
                answer += "R";
            }
            else
            {
                if (hand == "left")
                {
                    L[0] = n;
                    L[1] = m;
                    answer += "L";
                }
                else
                {
                    R[0] = n;
                    R[1] = m;
                    answer += "R";
                }
            }

        }

    }

    return answer;
}

int main()
{


    vector<int>a{ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };

    string ss = solution(a,"left" );

    return 0;
}

