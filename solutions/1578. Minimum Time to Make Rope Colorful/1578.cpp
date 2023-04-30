class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int n = colors.size(), i=0, j=0;
        while(j<n){
            int curCost = 0, maxTime = 0;
            while(j<n && colors[i]==colors[j]){
                curCost += neededTime[j];
                maxTime = max(maxTime, neededTime[j]);
                ++j;
            }
            cost += curCost - maxTime;
            i=j;
        }
        return cost;
    }
};