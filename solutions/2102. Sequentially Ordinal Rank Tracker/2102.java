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

  private Queue<Location> l = new PriorityQueue<>(
      (a, b) -> a.score == b.score ? -a.name.compareTo(b.name) : Integer.compare(a.score, b.score));
  private Queue<Location> r = new PriorityQueue<>(
      (a, b) -> a.score == b.score ? a.name.compareTo(b.name) : Integer.compare(b.score, a.score));
  private int k;
}
