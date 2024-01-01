class Solution:
  # If sorted(nums)[i + 1] - sorted(nums)[i] > 1, then there's a gap. Instead
  # of determining the number of gaps in each subarray, let's find out how many
  # subarrays contain each gap.
  def sumImbalanceNumbers(self, nums: List[int]) -> int:
    n = len(nums)
    # Note that to avoid double counting, only `left` needs to check nums[i].
    # This adjustment ensures that i represents the position of the leftmost
    # element of nums[i] within the subarray.

    # left[i] := the maximum index l s.t. nums[l] = nums[i] or nums[i] + 1
    left = [0] * n
    # right[i] := the minimum index r s.t. nums[r] = nums[i]
    right = [0] * n

    numToIndex = [-1] * (n + 2)
    for i, num in enumerate(nums):
      left[i] = max(numToIndex[num], numToIndex[num + 1])
      numToIndex[num] = i

    numToIndex = [n] * (n + 2)
    for i in range(n - 1, -1, -1):
      right[i] = numToIndex[nums[i] + 1]
      numToIndex[nums[i]] = i

    # The gap above nums[i] persists until encountering nums[i] or nums[i] + 1.
    # Consider subarrays nums[l..r] with l <= i <= r, where l in [left[i], i]
    # and r in [i, right[i] - 1]. There are (i - left[i]) * (right[i] - i)
    # subarrays satisfying this condition.
    #
    # Subtract n * (n + 1) / 2 to account for the overcounting of elements
    # initially assumed to have a gap. This adjustment is necessary as the
    # maximum element of every subarray does not have a gap.
    return sum((i - left[i]) * (right[i] - i)
               for i in range(n)) - n * (n + 1) // 2
