
using System;

public class Program
{
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(new string[] { "muzi", "frodo", "apeach", "neo" },
            new string[] { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" }, 2);
    }


}

public class Solution
{
    public int[] solution(string[] id_list, string[] report, int k)
    {
        int idLength = id_list.Length;
        int[] answer = new int[idLength];

        Dictionary<string, List<string>> map = new Dictionary<string, List<string>>();

        foreach (var item in report)
        {
            string[] temp = item.Split(' ');

            if (map.ContainsKey(temp[1]))
            {
                if (!map[temp[1]].Contains(temp[0]))
                    map[temp[1]].Add(temp[0]);
            }
            else
                map.Add(temp[1], new List<string>() { temp[0]});
        }

        foreach (var item in map)
        {
            if ( item.Value.Count >= k)
            {
                foreach (var item2 in item.Value)
                {
                    for (int i = 0; i < idLength; i++)
                    {
                        if (item2.Equals(id_list[i]))
                            answer[i]++;
                    }

                }
            }

        }





        return answer;
    }



}