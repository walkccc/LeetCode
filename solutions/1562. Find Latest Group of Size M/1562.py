class Solution:
  def findLatestStep(self, arr: list[int], m: int) -> int:
    if len(arr) == m:
      return len(arr)

    ans = -1
    step = 0
    # sizes[i] := the size of the group starting from i or ending in i
    # (1-indexed)
    sizes = [0] * (len(arr) + 2)

    for i in arr:
      step += 1
      # In the previous step, there exists a group with a size of m.
      if sizes[i - 1] == m or sizes[i + 1] == m:
        ans = step - 1
      head = i - sizes[i - 1]
      tail = i + sizes[i + 1]
      sizes[head] = tail - head + 1
      sizes[tail] = tail - head + 1

    return ans
