class Event {
  public int x;
  public int y1;
  public int y2;
  public char type;
  public Event(int x, int y1, int y2, char type) {
    this.x = x;
    this.y1 = y1;
    this.y2 = y2;
    this.type = type;
  }
}

class Solution {
  public int rectangleArea(int[][] rectangles) {
    final int kMod = 1_000_000_007;
    List<Event> events = new ArrayList<>();

    for (int[] r : rectangles) {
      events.add(new Event(r[0], r[1], r[3], 's'));
      events.add(new Event(r[2], r[1], r[3], 'e'));
    }

    Collections.sort(events, (a, b) -> a.x - b.x);

    long ans = 0;
    int prevX = 0;
    List<Pair<Integer, Integer>> yPairs = new ArrayList<>();

    for (Event e : events) {
      if (e.x > prevX) {
        final int width = e.x - prevX;
        ans = (ans + width * getHeight(yPairs)) % kMod;
        prevX = e.x;
      }
      if (e.type == 's') {
        yPairs.add(new Pair<>(e.y1, e.y2));
        Collections.sort(yPairs, Comparator.comparing(Pair::getKey));
      } else { // type == 'e'
        yPairs.remove(new Pair<>(e.y1, e.y2));
      }
    }

    return (int) (ans % kMod);
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
