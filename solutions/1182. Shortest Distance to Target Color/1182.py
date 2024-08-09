class Solution:
  def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
    kNumColor = 3
    n = len(colors)
    ans = []
    # left[i][c] := the closest index of color c in index i to the left
    left = [[0] * (kNumColor + 1) for _ in range(n)]
    # right[i][c] := the closest index of color c in index i to the right
    right = [[0] * (kNumColor + 1) for _ in range(n)]

    colorToLatestIndex = [0, -1, -1, -1]  # 0-indexed, -1 means N//A
    for i, color in enumerate(colors):
      colorToLatestIndex[color] = i
      for c in range(1, kNumColor + 1):
        left[i][c] = colorToLatestIndex[c]

    colorToLatestIndex = [0, -1, -1, -1]  # Reset.
    for i in range(n - 1, -1, -1):
      colorToLatestIndex[colors[i]] = i
      for c in range(1, kNumColor + 1):
        right[i][c] = colorToLatestIndex[c]

    for i, c in queries:
      leftDist = math.inf if left[i][c] == -1 else i - left[i][c]
      rightDist = math.inf if right[i][c] == -1 else right[i][c] - i
      minDist = min(leftDist, rightDist)
      ans.append(-1 if minDist == math.inf else minDist)

    return ans
