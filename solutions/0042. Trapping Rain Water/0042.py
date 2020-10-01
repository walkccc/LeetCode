class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        l = 0
        r = len(height) - 1
        maxLeft = 0
        maxRight = 0

        while l < r:
            if height[l] < height[r]:
                maxLeft = max(maxLeft, height[l])
                ans += maxLeft - height[l]
                l += 1
            else:
                maxRight = max(maxRight, height[r])
                ans += maxRight - height[r]
                r -= 1

        return ans
