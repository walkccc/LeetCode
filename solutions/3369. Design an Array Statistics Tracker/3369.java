class StatisticsTracker {
  public void addNumber(int number) {
    q.offer(number);
    count.merge(number, 1, Integer::sum);
    sortedList.merge(number, 1, Integer::sum);
    modeMaxHeap.offer(new Pair<>(count.get(number), number));
    sum += number;
  }

  public void removeFirstAddedNumber() {
    final int number = q.poll();
    count.merge(number, -1, Integer::sum);
    if (count.get(number) == 0)
      count.remove(number);
    sortedList.merge(number, -1, Integer::sum);
    if (sortedList.get(number) == 0)
      sortedList.remove(number);
    sum -= number;
  }

  public int getMean() {
    return (int) (sum / q.size());
  }

  public int getMedian() {
    final int midIndex = q.size() / 2; // Median depends on the queue size.
    int count = 0;
    for (Map.Entry<Integer, Integer> entry : sortedList.entrySet()) {
      count += entry.getValue();
      if (count > midIndex)
        return entry.getKey();
    }
    throw new IllegalArgumentException();
  }

  public int getMode() {
    // Removes stale entries from the top of the heap.
    while (!modeMaxHeap.isEmpty()) {
      final int frequency = modeMaxHeap.peek().getKey();
      final int number = modeMaxHeap.peek().getValue();
      if (count.containsKey(number) && count.get(number) == frequency)
        return number;
      modeMaxHeap.poll();
    }
    throw new IllegalArgumentException();
  }

  private Queue<Integer> q = new LinkedList<>();
  private Map<Integer, Integer> count = new HashMap<>();
  private TreeMap<Integer, Integer> sortedList = new TreeMap<>();
  // (frequency, number)
  private PriorityQueue<Pair<Integer, Integer>> modeMaxHeap =
      new PriorityQueue<>(Comparator.comparingInt(Pair<Integer, Integer>::getKey)
                              .reversed()
                              .thenComparingInt(Pair<Integer, Integer>::getValue));
  private long sum = 0;
}
