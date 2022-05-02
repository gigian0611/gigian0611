
#include <string>
#include <vector>
#include <cstring>
using namespace std;



int solution(string s) {
    int length = s.length();

    int answer = length;
    //소수 체크
    //if (length % 2 != 0)
    //{
    //    bool check = false;
    //    for (int i = 3; i < length; i++)
    //    {
    //        if (length % i == 0)
    //        {
    //            check = true;
    //            break;
    //        }
    //    }

    //    if (!check)
    //        return length;
    //}


    for (int i = 1; i < length; i++)
    {
        string temp = s;
        string sum = "";

        for (int j = 0; j < length; j+=i)
        {
            string str = temp.substr(j, i);
            int cnt = 1;
            for (int k = j + i; k < length; k+=i)
            {
                string str2 = temp.substr(k, i);
                if (str._Equal(str2))
                    cnt++;
                else
                    break;
            }
            if (cnt >= 2)
            {
                sum = sum.insert(sum.length(), (to_string(cnt) + str));
                j = j + cnt * i - i;
            }
            else 
                sum = sum.insert(sum.length(),  str);
        }

        if (answer > sum.length())
            answer = sum.length();
        

        
    }


    return answer;
}



int main()
{
    vector<int>numbers{ 4, 1, 2, 1 };

    //1, 1, 1, 1, 1
    solution("xababcdcdababcdcd");

    return 0;
}

