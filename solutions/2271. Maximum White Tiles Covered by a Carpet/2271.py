class Solution:
  def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
    if any(tile[1] - tile[0] + 1 >= carpetLen for tile in tiles):
      return carpetLen

    ans = 0
    prefix = [0] * (len(tiles) + 1)

    tiles.sort()
    starts = [tile[0] for tile in tiles]

    for i, tile in enumerate(tiles):
      length = tile[1] - tile[0] + 1
      prefix[i + 1] = prefix[i] + length

    for i, (s, _) in enumerate(tiles):
      carpetEnd = s + carpetLen - 1
      endIndex = bisect_right(starts, carpetEnd) - 1
      notCover = max(0, tiles[endIndex][1] - carpetEnd)
      ans = max(ans, prefix[endIndex + 1] - prefix[i] - notCover)

    return ans
