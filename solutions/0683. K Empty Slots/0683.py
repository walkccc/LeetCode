class Solution:
  def kEmptySlots(self, bulbs: List[int], k: int) -> int:
    n = len(bulbs)
    ans = math.inf
    # day[i] := the day when bulbs[i] is turned on
    day = [0] * n

    for i, bulb in enumerate(bulbs):
      day[bulb - 1] = i + 1

    # find a subarray of day[l..r], where its length is k + 2
    # for all that l < i < r, day[i] > max(day[l], day[r])
    l = 0
    r = l + k + 1
    i = 1
    while r < n:
      if i == r:
        ans = min(ans, max(day[l], day[r]))
        l = i
        r = i + k + 1
      elif day[i] < max(day[l], day[r]):
        l = i
        r = i + k + 1
      i += 1

    return -1 if ans == math.inf else ans
