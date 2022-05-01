
using System;
using System.Collections.Generic;
using System.Linq;
public class Program
{
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(new int[] { 95, 90, 99, 99, 80, 99 }, new int[] { 1, 1, 1, 1, 1, 1 }); 
    }


}

public class Solution
{
    public int[] solution(int[] progresses, int[] speeds)
    {
        int length = progresses.Length;

        int[] temp = new int[length];
        for (int i = 0; i < length; i++)
        {
            int pos = progresses[i];
            int spd = speeds[i];

            int rest = 100 - pos;
            int day = (rest / spd);

            if (rest % spd != 0)
                day++;

            temp[i] = day;
        }

        for (int i = 1; i < length; i++)
        {
            if (temp[i - 1] > temp[i])
                temp[i] = temp[i - 1];
        }

        Array.Sort(temp);
        List<int> result = new List<int>() { 1 };
        int cnt = temp[0];
        for (int i = 1; i < length; i++)
        {
            if (cnt == temp[i])
                result[result.Count - 1]++;
            else
            {
                result.Add(1);
                cnt = temp[i];
            }

        }


        return result.ToArray() ;
    }



}