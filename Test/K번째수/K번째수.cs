
using System;

public class Program
{
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(new int[] { 1, 5, 2, 6, 3, 7, 4 }, new int[,] { { 2, 5, 3 },{ 4, 4, 1 },{ 1, 7, 3 } });
    }


}

public class Solution
{
    public int[] solution(int[] array, int[,] commands)
    {
        
        int length = commands.GetLength(0);
        int[] answer = new int[length];
        for (int i = 0; i < length; i++)
        {
            int tempLength = commands[i, 1] - commands[i, 0] + 1;
            int[] temp = new int[tempLength];
            for (int j = 0; j < tempLength; j++)
            {
                temp[j] = array[ (commands[i, 0] - 1) + j];
                
            }

            Array.Sort(temp);

            answer[i] = temp[commands[i, 2] - 1];
        }




        return answer;
    }



}