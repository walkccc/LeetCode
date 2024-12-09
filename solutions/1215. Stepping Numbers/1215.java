class Solution {
  public List<Integer> countSteppingNumbers(int low, int high) {
    List<Integer> ans = new ArrayList<>();
    if (low == 0)
      ans.add(0);

    Queue<Long> q = new ArrayDeque<>();

    for (long i = 1; i <= 9; ++i)
      q.offer(i);

    while (!q.isEmpty()) {
      final long curr = q.poll();
      if (curr > high)
        continue;
      if (curr >= low)
        ans.add((int) curr);
      final long lastDigit = curr % 10;
      if (lastDigit > 0)
        q.offer(curr * 10 + lastDigit - 1);
      if (lastDigit < 9)
        q.offer(curr * 10 + lastDigit + 1);
    }

    return ans;
  }
}
