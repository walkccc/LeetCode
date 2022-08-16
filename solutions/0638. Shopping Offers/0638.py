class Solution:
  def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
    def dfs(s: int) -> int:
      ans = 0
      for i, need in enumerate(needs):
        ans += need * price[i]

      for i in range(s, len(special)):
        offer = special[i]
        if all(offer[j] <= need for j, need in enumerate(needs)):
          # use special[i]
          for j in range(len(needs)):
            needs[j] -= offer[j]
          ans = min(ans, offer[-1] + dfs(i))
          # backtracking - unuse special[i]
          for j in range(len(needs)):
            needs[j] += offer[j]

      return ans

    return dfs(0)
