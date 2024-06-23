class Solution:
  def kthSmallestPath(self, destination: List[int], k: int) -> str:
    ans = []
    v, h = destination

    for _ in range(h + v):
      # If pick 'H', then we're able to reack 1, 2, ..., availableRank.
      availableRank = math.comb(h + v - 1, v)
      if availableRank >= k:  # Should pick 'H'.
        ans.append('H')
        h -= 1
      else:  # Should pick 'V'.
        k -= availableRank
        ans.append('V')
        v -= 1

    return ''.join(ans)
