class SeatManager {
  public SeatManager(int n) {}

  public int reserve() {
    if (pq.isEmpty())
      return ++num;
    return pq.poll();
  }

  public void unreserve(int seatNumber) {
    pq.offer(seatNumber);
  }

  private PriorityQueue<Integer> pq = new PriorityQueue<>();
  private int num = 0;
}
