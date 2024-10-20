class Solution:
  def numberOfLines(self, widths: list[int], s: str) -> list[int]:
    numLines = 1
    runningWidth = 0

    for c in s:
      width = widths[string.ascii_lowercase.index(c)]
      if runningWidth + width <= 100:
        runningWidth += width
      else:
        numLines += 1
        runningWidth = width

    return [numLines, runningWidth]
