class UglyNum:
  def __init__(self, prime: int, index: int, value: int):
    self.prime = prime
    self.index = index  # Point the next index of uglyNums.
    self.value = value  # prime * uglyNums[index]


class Solution:
  def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
    minHeap = []  # (value, prime, index)
    uglyNums = [1]

    for prime in primes:
      heapq.heappush(minHeap, (prime * uglyNums[0], prime, 1))

    while len(uglyNums) < n:
      uglyNums.append(minHeap[0][0])
      while minHeap[0][0] == uglyNums[-1]:
        _, prime, index = heapq.heappop(minHeap)
        heapq.heappush(minHeap, (prime * uglyNums[index], prime, index + 1))

    return uglyNums[-1]
