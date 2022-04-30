
using System;

public class Program
{
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution("one4seveneight55seveneight");
    }


}

public class Solution
{
    public int solution(string s)
    {
        List<string> str = new List<string>  {  "zero","one","two","three","four","five","six","seven","eight","nine" };

        int length = str.Count;

        for (int i = 0; i < length; i++)
        {
            string item = str[i];
            int index = s.IndexOf(item);

            if (index == -1)
                continue;

            s = s.Remove(index, item.Length);
            s = s.Insert(index, i.ToString());
            i = 0;
        }

        return int.Parse(s);
    }



}