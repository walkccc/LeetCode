class Solution:
  def getFinalState(
      self,
      nums: list[int],
      k: int,
      multiplier: int
  ) -> list[int]:
    if multiplier == 1:
      return nums

    kMod = 1_000_000_007
    n = len(nums)
    maxNum = max(nums)
    ans = [0] * n
    minHeap = [(num, i) for i, num in enumerate(nums)]

    heapq.heapify(minHeap)

    # Keep multiplying the minimum number as close as possible to the maximum
    # number in the array. After that, stop multiplying the minimum number
    # because it will be greater than the maximum number in the array and break
    # the circularity.
    while k > 0 and minHeap[0][0] * multiplier <= maxNum:
      num, i = heapq.heappop(minHeap)
      heapq.heappush(minHeap, (num * multiplier, i))
      k -= 1

    sortedIndexedNums = sorted(minHeap)
    multipliesPerNum, remainingK = divmod(k, n)

    # Evenly distribute the remaining multiplications to each number by using
    # fast exponentiation.
    for index, (num, i) in enumerate(sortedIndexedNums):
      sortedIndexedNums[index] = (
          sortedIndexedNums[index][0] *
          pow(multiplier, multipliesPerNum, kMod) % kMod, i)

    # Distribute the remaining multiplications to the minimum `remainingK`
    # numbers.
    for index in range(remainingK):
      sortedIndexedNums[index] = (
          sortedIndexedNums[index][0] * multiplier % kMod,
          sortedIndexedNums[index][1])

    for num, i in sortedIndexedNums:
      ans[i] = num

    return ans
