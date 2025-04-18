# """
# This is FontInfo's API interface.
# You should not implement it, or speculate about its implementation
# """
# class FontInfo(object):
#   Return the width of char ch when fontSize is used.
#   def getWidth(self, fontSize: int, ch: str) -> int:
#     pass
#
#   def getHeight(self, fontSize: int) -> int:
#     pass
class Solution:
  def maxFont(
      self,
      text: str,
      w: int,
      h: int,
      fonts: list[int],
      fontInfo: 'FontInfo',
  ) -> int:
    count = collections.Counter(text)
    l = 0
    r = len(fonts) - 1

    while l < r:
      m = (l + r + 1) // 2
      if fontInfo.getHeight(
              fonts[m]) <= h and self._getWidthSum(
              count, fonts[m],
              fontInfo) <= w:
        l = m
      else:
        r = m - 1

    return fonts[l] if self._getWidthSum(count, fonts[l], fontInfo) <= w else -1

  def _getWidthSum(
      self,
      count: list[int],
      font: int,
      fontInfo: 'FontInfo',
  ) -> int:
    width = 0
    for c in string.ascii_lowercase:
      width += count[c] * fontInfo.getWidth(font, c)
    return width
