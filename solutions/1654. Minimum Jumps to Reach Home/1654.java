enum Direction { kForward, kBackward }

class Solution {
  public int minimumJumps(int[] forbidden, int a, int b, int x) {
    int furthest = x + a + b;
    Set<Integer> seenForward = new HashSet<>();
    Set<Integer> seenBackward = new HashSet<>();

    for (final int pos : forbidden) {
      seenForward.add(pos);
      seenBackward.add(pos);
      furthest = Math.max(furthest, pos + a + b);
    }

    // (direction, position)
    Queue<Pair<Direction, Integer>> q =
        new ArrayDeque<>(List.of(new Pair<>(Direction.kForward, 0)));

    for (int ans = 0; !q.isEmpty(); ++ans)
      for (int sz = q.size(); sz > 0; --sz) {
        Direction dir = q.peek().getKey();
        final int pos = q.poll().getValue();
        if (pos == x)
          return ans;
        final int forward = pos + a;
        final int backward = pos - b;
        if (forward <= furthest && seenForward.add(forward))
          q.offer(new Pair<>(Direction.kForward, forward));
        // It cannot jump backward twice in a row.
        if (dir == Direction.kForward && backward >= 0 && seenBackward.add(backward))
          q.offer(new Pair<>(Direction.kBackward, backward));
      }

    return -1;
  }
}
