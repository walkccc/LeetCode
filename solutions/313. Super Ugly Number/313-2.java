class Solution {
  public int nthSuperUglyNumber(int n, int[] primes) {
    // index := the next index in `uglyNums`
    // value := prime * uglyNums[index]
    record UglyNum(int prime, int index, long value) {}
    Queue<UglyNum> minHeap = new PriorityQueue<>(Comparator.comparingLong(UglyNum::value));
    int[] uglyNums = new int[n];
    uglyNums[0] = 1;

    for (final int prime : primes)
      minHeap.offer(new UglyNum(prime, 1, (long) prime * uglyNums[0]));

    for (int i = 1; i < n; ++i) {
      uglyNums[i] = (int) minHeap.peek().value;
      while (minHeap.peek().value == uglyNums[i]) {
        final UglyNum u = minHeap.poll();
        minHeap.offer(new UglyNum(u.prime, u.index + 1, (long) u.prime * uglyNums[u.index]));
      }
    }

    return uglyNums[n - 1];
  }
}
