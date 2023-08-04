class Solution:
  def floodFill(self, image: List[List[int]],
                sr: int, sc: int, newColor: int) -> List[List[int]]:
    startColor = image[sr][sc]
    seen = set()

    def dfs(i: int, j: int) -> None:
      if i < 0 or i == len(image) or j < 0 or j == len(image[0]):
        return
      if image[i][j] != startColor or (i, j) in seen:
        return

      image[i][j] = newColor
      seen.add((i, j))

      dfs(i + 1, j)
      dfs(i - 1, j)
      dfs(i, j + 1)
      dfs(i, j - 1)

    dfs(sr, sc)
    return image
