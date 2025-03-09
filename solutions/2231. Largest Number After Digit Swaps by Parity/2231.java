class Solution {
  public int largestInteger(int num) {
    final String s = String.valueOf(num);
    int ans = 0;
    // maxHeap[0] := the odd digits
    // maxHeap[1] := the even digits
    Queue<Integer>[] maxHeap = new Queue[2];

    for (int i = 0; i < 2; ++i)
      maxHeap[i] = new PriorityQueue<>(Comparator.reverseOrder());

    for (final char c : s.toCharArray()) {
      final int digit = c - '0';
      maxHeap[digit % 2].offer(digit);
    }

    for (final char c : s.toCharArray()) {
      final int i = c - '0' & 1;
      ans = (ans * 10 + maxHeap[i].poll());
    }

    return ans;
  }
}
