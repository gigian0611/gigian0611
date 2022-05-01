
using System;
using System.Collections.Generic;
public class Program
{
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(new int[] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    }


}

public class Solution
{
    public int[] solution(int[] answers)
    {
        int[] answer = new int[3];

        int[] tempA = new int[] { 1, 2, 3, 4, 5 };
        int[] tempB = new int[] { 2, 1, 2, 3, 2, 4, 2, 5 };
        int[] tempC = new int[] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

        int length = answers.Length;

        for (int i = 0; i < length; i++)
        {
            int ans = answers[i];

            if (ans == tempA[i % tempA.Length])
                answer[0]++;

            if (ans == tempB[i % tempB.Length])
                answer[1]++;

            if (ans == tempC[i % tempC.Length])
                answer[2]++;
        }

        int number = 0;
        for (int i = 0; i < 3; i++)
        {
            if (answer[i] > number)
            {
                number = answer[i];
            }
        }

        int size = 0;
        for (int i = 0; i < 3; i++)
        {
            if (answer[i] == number)
            {
                answer[size] = i + 1;
                size++;
            }
                
        }

        Array.Resize(ref answer, size);

        return answer;
    }



}