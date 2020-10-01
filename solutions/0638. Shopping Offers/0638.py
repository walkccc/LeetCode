class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        def dfs(s: int) -> int:
            ans = 0
            for i, need in enumerate(needs):
                ans += need * price[i]

            for i in range(s, len(special)):
                if all(special[i][j] <= need for j, need in enumerate(needs)):
                    for j, need in enumerate(needs):
                        needs[j] -= special[i][j]
                    ans = min(ans, special[i][-1] + dfs(i))
                    for j, need in enumerate(needs):
                        needs[j] += special[i][j]

            return ans

        return dfs(0)
