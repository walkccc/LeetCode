class Solution:
  def numberOfLines(self, widths: List[int], s: str) -> List[int]:
    numLines = 1
    runningWidth = 0

    for c in s:
      width = widths[ord(c) - ord('a')]
      if runningWidth + width <= 100:
        runningWidth += width
      else:
        numLines += 1
        runningWidth = width

    return [numLines, runningWidth]
