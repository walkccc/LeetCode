class Solution:
  def areSimilar(self, mat: List[List[int]], k: int) -> bool:
    n = len(mat[0])
    for row in mat:
      for j in range(n):
        if row[j] != row[(j + k) % n]:
          return False
    return True
