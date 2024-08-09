class Solution:
  def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
    # dp[i] := the minimum height to place the first i books
    dp = [0] + [math.inf] * len(books)

    for i in range(len(books)):
      sumThickness = 0
      maxHeight = 0
      # Place books[j..i] on a new shelf.
      for j in range(i, -1, -1):
        thickness, height = books[j]
        sumThickness += thickness
        if sumThickness > shelfWidth:
          break
        maxHeight = max(maxHeight, height)
        dp[i + 1] = min(dp[i + 1], dp[j] + maxHeight)

    return dp[-1]
