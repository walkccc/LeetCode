class Solution:
  def numberOfWays(self, n: int, m: int, k: int, source: List[int], dest: List[int]) -> int:
    kMod = 1_000_000_007
    # the number of ways of `source` to `dest` using steps so far
    ans = int(source == dest)
    # the number of ways of `source` to dest's row using steps so far
    row = int(source[0] == dest[0] and source[1] != dest[1])
    # the number of ways of `source` to dest's col using steps so far
    col = int(source[0] != dest[0] and source[1] == dest[1])
    # the number of ways of `source` to others using steps so far
    others = int(source[0] != dest[0] and source[1] != dest[1])

    for _ in range(k):
      nextAns = (row + col) % kMod
      nextRow = (ans * (m - 1) +  # -self
                 row * (m - 2) +  # -self, -center
                 others) % kMod
      nextCol = (ans * (n - 1) +  # -self
                 col * (n - 2) +  # -self, -center
                 others) % kMod
      nextOthers = (row * (n - 1) +  # -self
                    col * (m - 1) +  # -self
                    others * (m + n - 1 - 3)) % kMod  # -self, -row, -col
      ans = nextAns
      row = nextRow
      col = nextCol
      others = nextOthers

    return ans
