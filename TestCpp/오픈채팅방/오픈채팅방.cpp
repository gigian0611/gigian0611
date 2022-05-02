
#include <string>
#include <vector>
#include <cstring>
#include <map>
#pragma warning (disable : 4996)
using namespace std;



vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> id_map; 
    int length = record.size();
    for (int i = 0; i < length; i++)
    {
        string str = record[i];


        char* c = strtok(&str[0], " ");
        vector<string> temp{ c };
        while (c != NULL)
        {
            c = strtok(NULL, " ");

            if (c == NULL)
                break;

            temp.push_back(c);
        }

        if (id_map.find(temp[1]) == id_map.end())
        {
            if ( temp.size() == 2 )
                id_map.insert({ temp[1],"" });
            else 
                id_map.insert({ temp[1], temp[2] });
        }
           
        else if (temp.size() != 2)
        {
            id_map[temp[1]] = temp[2];
        }
    }

    for (int i = 0; i < length; i++)
    {
        string str = record[i];

        char* c = strtok(&str[0], " ");
        vector<string> temp{ c };
        while (c != NULL)
        {
            c = strtok(NULL, " ");

            if (c == NULL)
                break;

            temp.push_back(c);
        }

        if (temp[0] == "Enter")
            answer.push_back(id_map[temp[1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        else if (temp[0] == "Leave")
            answer.push_back(id_map[temp[1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
    }
    return answer;
}



int main()
{
    vector<string>a{ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };

    //1, 1, 1, 1, 1
    solution(a);

    return 0;
}

