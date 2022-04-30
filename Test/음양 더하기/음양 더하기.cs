
using System;

public class Program
{  
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(new int[] { 4, 7, 12 }, new bool[] { true, false, true });
    }


}

public class Solution
{
    public int solution(int[] absolutes, bool[] signs)
    {
        int answer = 0;
        int length = absolutes.Length;

        for (int i = 0; i < length; i++)
        {
            int num = absolutes[i];

            answer += signs[i] ? num : -num;                
        }


        return answer;
    }


}