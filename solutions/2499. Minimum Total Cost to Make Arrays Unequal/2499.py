class Solution:
  def minimumTotalCost(self, nums1: List[int], nums2: List[int]) -> int:
    n = len(nums1)
    ans = 0
    maxFreq = 0
    maxFreqNum = 0
    shouldBeSwapped = 0
    conflictedNumCount = [0] * (n + 1)

    # Collect the indices i s.t. num1 == num2 and record their `maxFreq`
    # and `maxFreqNum`.
    for i, (num1, num2) in enumerate(zip(nums1, nums2)):
      if num1 == num2:
        conflictedNum = num1
        conflictedNumCount[conflictedNum] += 1
        if conflictedNumCount[conflictedNum] > maxFreq:
          maxFreq = conflictedNumCount[conflictedNum]
          maxFreqNum = conflictedNum
        shouldBeSwapped += 1
        ans += i

    # Collect the indices with num1 != num2 that contribute less cost.
    # This can be greedily achieved by iterating from 0 to n - 1.
    for i, (num1, num2) in enumerate(zip(nums1, nums2)):
      # Since we have over `maxFreq * 2` spaces, `maxFreqNum` can be
      # successfully distributed, so no need to collectextra spaces.
      if maxFreq * 2 <= shouldBeSwapped:
        break
      if num1 == num2:
        continue
      # The numbers == `maxFreqNum` worsen the result since they increase the
      # `maxFreq`.
      if num1 == maxFreqNum or num2 == maxFreqNum:
        continue
      shouldBeSwapped += 1
      ans += i

    return -1 if maxFreq * 2 > shouldBeSwapped else ans
