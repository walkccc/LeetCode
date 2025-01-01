class DataStream {
  public DataStream(int value, int k) {
    this.value = value;
    this.k = k;
  }

  public boolean consec(int num) {
    if (q.size() == k && q.poll() == value)
      --count;
    if (num == value)
      ++count;
    q.offer(num);
    return count == k;
  }

  private int value;
  private int k;
  private Queue<Integer> q = new ArrayDeque<>();
  private int count = 0;
}
