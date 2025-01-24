class Solution:
  def minimumMoves(self, nums: list[int], k: int, maxChanges: int) -> int:
    # Dylan has two actions for collecting '1's in a sequence:
    # Action 1: Put a '1' next to him and pick it up.
    #           The cost is 2.
    # Action 2: Swap a '1' towards him and collect it.
    #           The cost equals the distance to the '1'.
    #
    # To minimize the swapping cost, Dylan can use a sliding window strategy,
    # selecting the optimal position (middle '1' in the window) for efficient
    # collection. The window's size is crucial:

    # The minimum window size: min(0, k - maxChanges), ensuring the window
    # isn't too small.
    # The maximum window size: min(k, minOnesByTwo + 3, the number of ones),
    # preventing overly ambitious swaps.
    #
    # Note that if needing to move a '1' beyond `minOnesByTwo + 3`, it's
    # cheaper to use Action 1.

    # At most three indices, (dylanIndex - 1, dylanIndex, dylanIndex + 1), have
    # a distance <= 1 from dylanIndex, implying that we'll be taking at most
    # `maxOnesByTwo + 3` using Action 2. Any more Action 2 is not optimal and
    # should be replaced with Action 1.
    kNumOfIndicesWithinOneDistance = 3
    ans = math.inf
    oneIndices = [i for i, num in enumerate(nums) if num == 1]
    prefix = list(itertools.accumulate(oneIndices, initial=0))

    minOnesByTwo = max(0, k - maxChanges)
    maxOnesByTwo = min(
        k, minOnesByTwo + kNumOfIndicesWithinOneDistance, len(oneIndices))

    for onesByTwo in range(minOnesByTwo, maxOnesByTwo + 1):
      for l in range(len(prefix) - onesByTwo):
        r = l + onesByTwo  # Collect 1s in oneIndices[l - 1..r - 1].
        cost1 = (k - onesByTwo) * 2
        cost2 = ((prefix[r] - prefix[(l + r) // 2]) -
                 (prefix[(l + r + 1) // 2] - prefix[l]))
        ans = min(ans, cost1 + cost2)

    return ans
