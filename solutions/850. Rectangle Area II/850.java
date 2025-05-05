class Solution {
  public int rectangleArea(int[][] rectangles) {
    record Event(int x, int y1, int y2, char type) {}
    final int MOD = 1_000_000_007;
    List<Event> events = new ArrayList<>();

    for (int[] r : rectangles) {
      events.add(new Event(r[0], r[1], r[3], 's'));
      events.add(new Event(r[2], r[1], r[3], 'e'));
    }

    Collections.sort(events, Comparator.comparingInt(Event::x));

    long ans = 0;
    int prevX = 0;
    List<Pair<Integer, Integer>> yPairs = new ArrayList<>();

    for (Event e : events) {
      if (e.x > prevX) {
        final int width = e.x - prevX;
        ans = (ans + width * getHeight(yPairs)) % MOD;
        prevX = e.x;
      }
      if (e.type == 's') {
        yPairs.add(new Pair<>(e.y1, e.y2));
        Collections.sort(yPairs, Comparator.comparingInt(Pair::getKey));
      } else { // type == 'e'
        yPairs.remove(new Pair<>(e.y1, e.y2));
      }
    }

    return (int) (ans % MOD);
  }

  private long getHeight(List<Pair<Integer, Integer>> yPairs) {
    int height = 0;
    int prevY = 0;

    for (Pair<Integer, Integer> pair : yPairs) {
      final int y1 = pair.getKey();
      final int y2 = pair.getValue();
      prevY = Math.max(prevY, y1);
      if (y2 > prevY) {
        height += y2 - prevY;
        prevY = y2;
      }
    }

    return height;
  }
}
