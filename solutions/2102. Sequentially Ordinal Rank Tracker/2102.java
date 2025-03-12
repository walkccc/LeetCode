class SORTracker {
  public void add(String name, int score) {
    l.offer(new Location(name, score));
    if (l.size() > k + 1)
      r.offer(l.poll());
  }

  public String get() {
    final String name = l.peek().name;
    if (!r.isEmpty())
      l.offer(r.poll());
    ++k;
    return name;
  }

  private record Location(String name, int score) {}

  private Queue<Location> l =
      new PriorityQueue<>(Comparator.comparing((Location a) -> a.score)
                              .thenComparing((Location a) -> a.name, Comparator.reverseOrder()));
  private Queue<Location> r =
      new PriorityQueue<>(Comparator.comparing((Location a) -> a.score, Comparator.reverseOrder())
                              .thenComparing((Location a) -> a.name));
  private int k;
}
