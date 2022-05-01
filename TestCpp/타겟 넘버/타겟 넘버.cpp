
#include <string>
#include <vector>

using namespace std;

void targetAction(vector<int> numbers, int& answer, int target, int index, int sum)
{
    if (index >= numbers.size() - 1)
    {
        if (sum + numbers[index] == target)
            answer++;

        if (sum - numbers[index] == target)
            answer++;

        return;
    }

    int temp = sum + numbers[index];
    targetAction(numbers, answer, target, index + 1, temp);
    temp = sum - numbers[index];
    targetAction(numbers, answer, target, index + 1, temp);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int length = numbers.size();

    targetAction(numbers, answer, target, 0, 0 );

    return answer;
}



int main()
{
    vector<int>numbers{ 4, 1, 2, 1 };

    //1, 1, 1, 1, 1
    solution(numbers, 4);

    return 0;
}

