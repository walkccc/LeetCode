class RecentCounter {
  public int ping(int t) {
    q.offer(t);
    while (q.peek() < t - 3000)
      q.poll();
    return q.size();
  }

  private Queue<Integer> q = new LinkedList<>();
}
