class Solution {
  public int maxRemoval(int[] nums, int[][] queries) {
    int queryIndex = 0;
    Queue<Integer> available = new PriorityQueue<>(Collections.reverseOrder()); // available `r`s
    Queue<Integer> running = new PriorityQueue<>();                             // running `r`s

    Arrays.sort(queries, Comparator.comparingInt((int[] query) -> query[0]));

    for (int i = 0; i < nums.length; ++i) {
      while (queryIndex < queries.length && queries[queryIndex][0] <= i)
        available.offer(queries[queryIndex++][1]);
      while (!running.isEmpty() && running.peek() < i)
        running.poll();
      while (nums[i] > running.size()) {
        if (available.isEmpty() || available.peek() < i)
          return -1;
        running.offer(available.poll());
      }
    }

    return available.size();
  }
}
