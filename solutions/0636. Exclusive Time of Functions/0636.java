class Solution {
  public int[] exclusiveTime(int n, List<String> logs) {
    int[] ans = new int[n];
    Deque<Integer> stack = new ArrayDeque<>(); // [oldest_id, ..., latest_id]
    int prevTime = -1;

    for (final String log : logs) {
      final String[] splits = log.split(":");
      // get function_id, label, and timestamp
      final int id = Integer.parseInt(splits[0]);        // {function_id}
      final char label = splits[1].charAt(0);            // {"s" ("start") | "e" ("end") }
      final int timestamp = Integer.parseInt(splits[2]); // {timestamp}
      if (label == 's') {
        if (!stack.isEmpty())
          ans[stack.peek()] += timestamp - prevTime;
        stack.push(id);
        prevTime = timestamp;
      } else {
        ans[stack.pop()] += timestamp - prevTime + 1;
        prevTime = timestamp + 1;
      }
    }

    return ans;
  }
}
