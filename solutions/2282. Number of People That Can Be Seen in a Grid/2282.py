class Solution:
  def seePeople(self, heights: List[List[int]]) -> List[List[int]]:
    m = len(heights)
    n = len(heights[0])
    ans = [[0] * n for _ in range(m)]

    for i, row in enumerate(heights):
      stack = []
      for j, height in enumerate(row):
        hasEqualHeight = False
        while stack and row[stack[-1]] <= height:
          if row[stack[-1]] == height:
            # edge case: [4, 2, 1, 1, 3]
            hasEqualHeight = True
          ans[i][stack.pop()] += 1
        if stack and not hasEqualHeight:
          ans[i][stack[-1]] += 1
        stack.append(j)

    for j, col in enumerate(zip(*heights)):
      stack = []
      for i, height in enumerate(col):
        hasEqualHeight = False
        while stack and col[stack[-1]] <= height:
          if col[stack[-1]] == height:
            hasEqualHeight = True
          ans[stack.pop()][j] += 1
        if stack and not hasEqualHeight:
          ans[stack[-1]][j] += 1
        stack.append(i)

    return ans
