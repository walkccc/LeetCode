class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
    
        n = len(boxes)
        dp = [[[0] * n for _ in range(n)] for _ in range(n)]

        def cacl_point(boxes, l, r, k):
          
            if l > r:
                return 0
           
            if dp[l][r][k] != 0:
                return dp[l][r][k]
            
            while l < r and boxes[r] == boxes[r-1] :
                r -= 1
                k += 1
            
            dp[l][r][k] = cacl_point(boxes, l, r-1, 0) + (k+1)*(k+1)
            for x in range(l, r-1):
                if boxes[x] == boxes[r]:
                    dp[l][r][k] = max(dp[l][r][k], cacl_point(boxes, x+1, r-1, 0)+cacl_point(boxes, l, x, k+1))
            return dp[l][r][k]

        return cacl_point(boxes, 0, n-1, 0)
