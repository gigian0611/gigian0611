
using System;

public class Program
{  
    static void Main(string[] args)
    {
        Solution test = new Solution();

        test.solution(new int[] { 1, 2, 3, 4 });
    }


}

public class Solution
{
    public int solution(int[] nums)
    {
        int answer = 0;
        int length = nums.Length;

        for (int i = 0; i < length; i++)
        {
            int sum = nums[i];
            for (int j = i + 1; j < length; j++)
            {
                sum += nums[j];
                for (int k = j + 1; k < length; k++)
                {
                    sum += nums[k];

                    if (sum == 2)
                        answer++;

                    else if (sum % 2 != 0)
                    {
                        bool check = false;
                        for (int h = 3; h < sum; h++)
                        {
                            if (sum % h == 0)
                            {
                                check = true;
                                break;
                            }
                        }
                        if (!check)
                            answer++;
                    }

                    sum = nums[i] + nums[j];
                }

                sum = nums[i];
            }

            
            /*else
            {
                for (int j = 0; j < length2; j++)
                {
                    sum += nums[j + (i + 1)] + nums[j + (i + 2)];

                    if (sum == 2)
                        answer++;

                    else if (sum % 2 != 0)
                    {
                        bool check = false;
                        for (int k = 3; k < sum; k++)
                        {
                            if (sum % k == 0)
                            {
                                check = true;
                                break;
                            }
                        }
                        if (!check)
                            answer++;
                    }
                    sum = nums[i];
                }
            }*/
        }

        return answer;
    }



}