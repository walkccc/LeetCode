from sortedcontainers import SortedDict


class Solution:
  def mostFrequentIDs(self, nums: list[int], freq: list[int]) -> list[int]:
    ans = []
    numCount = collections.Counter()  # {num: freq}
    freqCount = SortedDict()  # {num's freq: freq}

    for num, f in zip(nums, freq):
      if numCount[num] > 0:
        numFreq = numCount[num]
        freqCount[numFreq] -= 1
        if freqCount[numFreq] == 0:
          del freqCount[numFreq]
      newFreq = numCount[num] + f
      if newFreq == 0:
        del numCount[num]
      else:
        numCount[num] = newFreq
        freqCount[newFreq] = freqCount.get(newFreq, 0) + 1
      ans.append(freqCount.peekitem(-1)[0] if freqCount else 0)

    return ans
