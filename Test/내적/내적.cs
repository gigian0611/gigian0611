
using System;

public class Program
{  
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(new int[] { 1, 2, 3, 4 }, new int[] { -3, -1, 0, 2 });
    }


}

public class Solution
{
    public int solution(int[] a, int[] b)
    {
        int answer = 0;
        int length = a.Length;

        for (int i = 0; i < length; i++)
            answer += a[i] * b[i];
        

        return answer;
    }

}