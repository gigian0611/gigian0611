#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void permutation(int &cnt, vector<string> condition, vector<string> data, int depth, int n, int m)
{
   

    if (depth == m)
    {
        int length = condition.size();
        string item0, item1;
        bool check = false;
        for (int i = 0; i < length; i++)
        {

            item0 += condition[i][0];
            item1 += condition[i][2];

            int index0 = find(data.begin(), data.end(), item0) - data.begin();
            int index1 = find(data.begin(), data.end(), item1) - data.begin();

            if ((item0 == data[index0] || item1 == data[index0]) && (item0 == data[index1] || item1 == data[index1]))
            {
               int res = abs(index0- index1);
               int num = atoi(&condition[i][4]);
               switch (condition[i][3])
               {
               case '=':
                   if ((res - 1) != num)
                       check = true;
                   break;
               case '<':
               {
                   if (res - 1 >= num)
                       check = true;
               }break;
               case '>':
               {
                   if (res - 1 <= num)
                       check = true;
               }break;
               }
            }

            if (check)
                break;

            item0.clear();
            item1.clear();
        }

        if (!check)
            cnt++;

        return;

    }

    for (int i = depth; i < m; i++)
    {
        //int length = condition.size();
        //string item0, item1;
        //bool check = false;
        //for (int j = 0; j < length; j++)
        //{

        //    item0 += condition[j][0];
        //    item1 += condition[j][2];

        //    int index0 = depth;
        //    int index1 = i;

        //    if ((item0 == data[index0] || item1 == data[index0]) && (item0 == data[index1] || item1 == data[index1]))
        //    {
        //        int res = index0 >= index1 ? index0 - index1 : index1 - index0;
        //        int num = atoi(&condition[j][4]);
        //        switch (condition[j][3])
        //        {
        //        case '=':
        //            if ((res - 1) != num)
        //                cnt--;
        //            break;
        //        case '<':
        //        {
        //            if (res - 1 >= num)
        //                cnt--;
        //        }break;
        //        case '>':
        //        {
        //            if (res - 1 <= num)
        //                cnt--;
        //        }break;
        //        }
        //    }

        //    if (check)
        //        break;

        //    item0.clear();
        //    item1.clear();
        //}

        //if (check)
        //    return;

        swap(data[depth], data[i]);
        permutation(cnt, condition, data, depth + 1, n, m);
        swap(data[i], data[depth]);
    }
}

int solution(int n, vector<string> data) {

    vector<string> name{ "A", "C", "F", "J", "M", "N","R", "T" };

    int answer = 0;
    permutation(answer, data, name, 0, 8, 8);




    return answer;
}

int main()
{


    vector<string>a{ "N~F=0", "R~T>2" };

    solution(2, a);

    return 0;
}

