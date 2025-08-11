class Solution:
  def maxSubarrays(self, n: int, conflictingPairs: list[list[int]]) -> int:
    validSubarrays = 0
    maxLeft = 0
    secondMaxLeft = 0
    # gains[i] := the number of additional valid subarrays we can gain if the
    # restriction at index `i` is removed
    gains = [0] * (n + 1)
    # conflicts[r] := left endpoints that conflict with subarrays ending in r
    conflicts = [[] for _ in range(n + 1)]

    for a, b in conflictingPairs:
      conflicts[max(a, b)].append(min(a, b))

    for right in range(1, n + 1):
      for left in conflicts[right]:
        if left > maxLeft:
          secondMaxLeft = maxLeft
          maxLeft = left
        elif left > secondMaxLeft:
          secondMaxLeft = left
      # Subarrays [maxLeft + 1..right],
      #           [maxLeft + 2..right],
      #           ...
      #           [right..right] are valid.
      validSubarrays += right - maxLeft
      # If we remove `maxLeft` (the most restrictive conflict), we gain
      # `maxLeft - secondMaxLeft` new subarrays:
      # [secondMaxLeft + 1..right],
      # [secondMaxLeft + 2..right],
      # ...
      # [maxLeft..right].
      gains[maxLeft] += maxLeft - secondMaxLeft

    return validSubarrays + max(gains)
