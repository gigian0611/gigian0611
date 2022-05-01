
using System;
using System.Collections.Generic;
public class Program
{
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(7, new int[] {2,3,4}, new int[] {1,2,3,6}); // 6
    }


}

public class Solution
{
    public int solution(int n, int[] lost, int[] reserve)
    {
        int length = reserve.Length;
        int length2 = lost.Length;
        int cnt = 0;

        Array.Sort(lost);
        Array.Sort(reserve);

        List<int> lost_temp = lost.ToList();
        List<int> reserve_temp = reserve.ToList();

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length2; j++)
            {
                if (reserve[i] == lost[j])
                {
                    lost_temp.Remove(lost[j]);
                    reserve_temp.Remove(reserve[i]);
                }
            }
        }

        lost = lost_temp.ToArray();
        reserve = reserve_temp.ToArray();
        length = reserve.Length;
        for (int i = 0; i < length; i++)
        {
            int front = reserve[i] - 1;
            int back = reserve[i] + 1;

            int front_index = Array.FindIndex(lost, o => o == front);
            int back_index = Array.FindIndex(lost, o => o == back);

            if (front_index != -1)
            {
                lost[front_index] = -1;
                cnt++;
            }

            else if (back_index != -1)
            {
                lost[back_index] = -1;
                cnt++;
            }
        }

        return (n - lost.Length ) + cnt;
    }



}