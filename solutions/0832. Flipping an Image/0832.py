class Solution:
  def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
    for row in A:
      for i in range((len(row) + 1) // 2):
        row[i], row[~i] = row[~i] ^ 1, row[i] ^ 1

    return A
