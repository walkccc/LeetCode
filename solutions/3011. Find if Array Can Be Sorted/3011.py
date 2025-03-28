class Solution:
  def canSortArray(self, nums: list[int]) -> int:
    # Divide the array into distinct segments where each segment is comprised
    # of consecutive elements sharing an equal number of set bits. Ensure that
    # for each segment, when moving from left to right, the maximum of a
    # preceding segment is less than the minimum of the following segment.
    prevSetBits = 0
    prevMax = -math.inf  # the maximum of the previous segment
    currMax = -math.inf  # the maximum of the current segment
    currMin = math.inf   # the minimum of the current segment

    for num in nums:
      setBits = num.bit_count()
      if setBits != prevSetBits:  # Start a new segment.
        if prevMax > currMin:
          return False
        prevSetBits = setBits
        prevMax = currMax
        currMax = num
        currMin = num
      else:  # Continue with the current segment.
        currMax = max(currMax, num)
        currMin = min(currMin, num)

    return prevMax <= currMin
