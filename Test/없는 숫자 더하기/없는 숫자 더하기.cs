
using System;

public class Program
{  
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(new int[] { 1, 2, 3, 4, 6, 7, 8, 0 });
    }


}

public class Solution
{
    public int solution(int[] numbers)
    {
        int answer = 0;

        for (int i = 0; i < 10; i++)
        {
            int index = Array.IndexOf(numbers, i);

            if (index == -1)
                answer += i;

        }
        return answer;
    }


}