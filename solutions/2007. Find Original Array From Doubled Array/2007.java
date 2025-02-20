class Solution {
  public int[] findOriginalArray(int[] changed) {
    List<Integer> ans = new ArrayList<>();
    Queue<Integer> q = new ArrayDeque<>();

    Arrays.sort(changed);

    for (final int num : changed)
      if (!q.isEmpty() && num == q.peek()) {
        q.poll();
      } else {
        q.offer(num * 2);
        ans.add(num);
      }

    return q.isEmpty() ? ans.stream().mapToInt(Integer::intValue).toArray() : new int[] {};
  }
}
