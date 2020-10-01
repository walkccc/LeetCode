class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sellTwo = 0
        holdTwo = float('-inf')
        sellOne = 0
        holdOne = float('-inf')

        for price in prices:
            sellTwo = max(sellTwo, holdTwo + price)
            holdTwo = max(holdTwo, sellOne - price)
            sellOne = max(sellOne, holdOne + price)
            holdOne = max(holdOne, -price)

        return sellTwo
