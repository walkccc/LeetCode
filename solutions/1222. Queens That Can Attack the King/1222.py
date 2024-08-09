class Solution:
  def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
    ans = []
    queens = {(i, j) for i, j in queens}

    for d in [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]:
      i = king[0] + d[0]
      j = king[1] + d[1]
      while 0 <= i < 8 and 0 <= j < 8:
        if (i, j) in queens:
          ans.append([i, j])
          break
        i += d[0]
        j += d[1]

    return ans
