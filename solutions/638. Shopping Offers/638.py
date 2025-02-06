class Solution:
  def shoppingOffers(
      self,
      price: list[int],
      special: list[list[int]],
      needs: list[int]
  ) -> int:
    def dfs(s: int) -> int:
      ans = 0
      for i, need in enumerate(needs):
        ans += need * price[i]

      for i in range(s, len(special)):
        offer = special[i]
        if all(offer[j] <= need for j, need in enumerate(needs)):
          # Use the special[i].
          for j in range(len(needs)):
            needs[j] -= offer[j]
          ans = min(ans, offer[-1] + dfs(i))
          # Unuse the special[i] (backtracking).
          for j in range(len(needs)):
            needs[j] += offer[j]

      return ans

    return dfs(0)
