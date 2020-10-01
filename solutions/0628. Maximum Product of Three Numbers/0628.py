class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        mini = float('inf')
        secondMin = float('inf')
        maxi = float('-inf')
        secondMax = float('-inf')
        thirdMax = float('-inf')

        for num in nums:
            if num <= mini:
                secondMin = mini
                mini = num
            elif num <= secondMin:
                secondMin = num

            if num >= maxi:
                thirdMax = secondMax
                secondMax = maxi
                maxi = num
            elif num >= secondMax:
                thirdMax = secondMax
                secondMax = num
            elif num >= thirdMax:
                thirdMax = num

        return max(mini * secondMin * maxi, maxi * secondMax * thirdMax)
