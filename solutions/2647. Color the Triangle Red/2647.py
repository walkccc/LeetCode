class Solution:
  def colorRed(self, n: int) -> list[list[int]]:
    ans = []
    tipSize = n % 4

    # The tip of the triangle is always painted red.
    if tipSize >= 1:
      ans.append([1, 1])

    # Pamost right and most left elements at the following rows.
    for i in range(2, tipSize + 1):
      ans.append([i, 1])
      ans.append([i, 2 * i - 1])

    # Pa4-row chunks.
    for i in range(tipSize + 1, n, 4):
      # Fill the first row of the chunk.
      ans.append([i, 1])
      # Fill the second row.
      for j in range(1, i + 1):
        ans.append([i + 1, 2 * j + 1])
      # Fill the third row.
      ans.append([i + 2, 2])
      # Fill the fourth row.
      for j in range(i + 2 + 1):
        ans.append([i + 3, 2 * j + 1])

    return ans
