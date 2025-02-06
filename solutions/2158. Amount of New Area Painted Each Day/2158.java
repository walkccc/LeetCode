enum Type { kEntering, kLeaving }

class Event {
  public int day;
  public int index;
  public Type type;
  public Event(int day, int index, Type type) {
    this.day = day;
    this.index = index;
    this.type = type;
  }
}

class Solution {
  public int[] amountPainted(int[][] paint) {
    final int n = paint.length;
    final int minDay = Arrays.stream(paint).mapToInt(x -> x[0]).min().getAsInt();
    final int maxDay = Arrays.stream(paint).mapToInt(x -> x[1]).max().getAsInt();
    int[] ans = new int[n];
    // Stores the indices of paints that are available now.
    TreeSet<Integer> runningIndices = new TreeSet<>();
    List<Event> events = new ArrayList<>();

    for (int i = 0; i < n; ++i) {
      final int start = paint[i][0];
      final int end = paint[i][1];
      events.add(new Event(start, i, Type.kEntering)); // 1 := entering
      events.add(new Event(end, i, Type.kLeaving));    // -1 := leaving
    }

    Collections.sort(events, (a, b) -> Integer.compare(a.day, b.day));

    int i = 0; // events' index
    for (int day = minDay; day < maxDay; ++day) {
      while (i < events.size() && events.get(i).day == day) {
        if (events.get(i).type == Type.kEntering)
          runningIndices.add(events.get(i).index);
        else
          runningIndices.remove(events.get(i).index);
        ++i;
      }
      if (!runningIndices.isEmpty())
        ++ans[runningIndices.first()];
    }

    return ans;
  }
}
