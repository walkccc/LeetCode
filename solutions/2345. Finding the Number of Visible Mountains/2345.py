class Solution:
  def visibleMountains(self, peaks: List[List[int]]) -> int:
    count = Counter((x, y) for x, y in peaks)
    peaks = sorted([k for k, v in count.items() if v == 1])
    stack = []

    # returns True if `peak1` is hidden by `peak2`
    def isHidden(peak1: List[int], peak2: List[int]) -> bool:
      x1, y1 = peak1
      x2, y2 = peak2
      return x1 - y1 >= x2 - y2 and x1 + y1 <= x2 + y2

    for i, peak in enumerate(peaks):
      while stack and isHidden(peaks[stack[-1]], peak):
        stack.pop()
      if stack and isHidden(peak, peaks[stack[-1]]):
        continue
      stack.append(i)

    return len(stack)
