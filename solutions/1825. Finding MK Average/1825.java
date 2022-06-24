class MKAverage {
  public MKAverage(int m, int k) {
    this.m = m;
    this.k = k;
  }

  public void addElement(int num) {
    q.offer(num);
    add(mid, num);
    midSum += num;

    if (q.size() > m) {
      final int removed = q.poll();
      if (top.containsKey(removed)) {
        remove(top, removed);
        --topSize;
      } else if (mid.containsKey(removed)) {
        remove(mid, removed);
        midSum -= removed;
      } else {
        remove(bot, removed);
        --botSize;
      }
    }

    // move item(s) from mid to top to fill k slots
    while (!mid.isEmpty() && topSize < k) {
      midSum -= mid.lastKey();
      add(top, remove(mid, mid.lastKey()));
      ++topSize;
    }

    // rebalance mid and top
    while (!mid.isEmpty() && mid.lastKey() > top.firstKey()) {
      midSum -= mid.lastKey();
      midSum += top.firstKey();
      add(top, remove(mid, mid.lastKey()));
      add(mid, remove(top, top.firstKey()));
    }

    // move item(s) from mid to bot to fill k slots
    while (!mid.isEmpty() && botSize < k) {
      midSum -= mid.firstKey();
      add(bot, remove(mid, mid.firstKey()));
      ++botSize;
    }

    // rebalance mid and bot
    while (!mid.isEmpty() && mid.firstKey() < bot.lastKey()) {
      midSum -= mid.firstKey();
      midSum += bot.lastKey();
      add(bot, remove(mid, mid.firstKey()));
      add(mid, remove(bot, bot.lastKey()));
    }
  }

  public int calculateMKAverage() {
    return q.size() == m ? (int) (midSum / (m - 2 * k)) : -1;
  }

  private final int m;
  private final int k;
  private Queue<Integer> q = new ArrayDeque<>();
  private TreeMap<Integer, Integer> top = new TreeMap<>();
  private TreeMap<Integer, Integer> mid = new TreeMap<>();
  private TreeMap<Integer, Integer> bot = new TreeMap<>();
  private int topSize = 0;
  private int botSize = 0;
  private long midSum = 0;

  private void add(TreeMap<Integer, Integer> map, int num) {
    map.merge(num, 1, Integer::sum);
  }

  private int remove(TreeMap<Integer, Integer> map, int num) {
    map.put(num, map.get(num) - 1);
    if (map.get(num) == 0)
      map.remove(num);
    return num;
  }
}
