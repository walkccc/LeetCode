class Solution 
{ 
    public int minCost(String colors, int[] neededTime) 
    { 
        if (colors.length()==0) 
        { 
            return 0; 
        }
         char prev = colors.charAt(0);
          int ans = 0; 
          for (int i=1; i<neededTime.length; i++) 
          { 
              if (colors.charAt(i)==prev) 
              { 
                  int curr = Math.min(neededTime[i], neededTime[i-1]); 
                  ans+=curr; 
                  neededTime[i] = Math.max(neededTime[i], neededTime[i-1]); 
                } 
                else 
                { 
                    prev = colors.charAt(i); 
                } 
            } 
            return ans; 
        } 
    }