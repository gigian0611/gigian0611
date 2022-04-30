
using System;

public class Program
{
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(new int[] { 44, 1, 0, 0, 31, 25 },
            new int[] { 31, 10, 45, 1, 6, 19 });
    }


}

public class Solution
{
    public int[] solution(int[] lottos, int[] win_nums)
    {
        int length = lottos.Length;
        int[] answer = new int[2];
        int hitCount = 0;
        int zeroCount = 0;
        for (int i = 0; i < length; i++)
        {
            int num = lottos[i];

            if (num == 0)
            {
                zeroCount++;
                continue;
            }

            foreach (var item in win_nums)
            {
                if (num == item)
                    hitCount++;
            }
        }

        int number = 7 - hitCount;
        answer[1] = number > 6 ? 6 : number;

        number = 7 - (hitCount + zeroCount);
        answer[0] = number > 6 ? 6 : number;

        return answer;
    }



}