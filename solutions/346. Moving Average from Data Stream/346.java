class MovingAverage {
  public MovingAverage(int size) {
    this.size = size;
  }

  public double next(int val) {
    if (q.size() == size)
      sum -= q.poll();
    sum += val;
    q.offer(val);
    return sum / q.size();
  }

  private int size = 0;
  private double sum = 0;
  private Queue<Integer> q = new ArrayDeque<>();
}
