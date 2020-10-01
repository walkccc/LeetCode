class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        def dfs(i: int, j: int) -> None:
            if not 0 <= i < len(image) or not 0 <= j < len(image[0]):
                return
            if image[i][j] != startColor or seen[i][j]:
                return

            image[i][j] = newColor
            seen[i][j] = True

            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        startColor = image[sr][sc]
        seen = [[False] * len(image[0]) for _ in range(len(image))]

        dfs(sr, sc)

        return image
