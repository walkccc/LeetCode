class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        st,ct,total=0,1,0
        sm=neededTime[0]
        mx=neededTime[0]
        for i in range(1,len(colors)):
            if colors[i]==colors[i-1]:
                ct+=1
                sm+=neededTime[i]
                mx=max(mx,neededTime[i])
            else:
                if ct>1:
                    total+=(sm-mx)
                ct=1
                st=i
                sm=neededTime[i]
                mx=neededTime[i]
        if ct>1:
            total+=(sm-mx)
        return total