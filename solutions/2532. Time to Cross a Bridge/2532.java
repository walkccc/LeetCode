class Solution {
  public int findCrossingTime(int n, int k, int[][] time) {
    int ans = 0;
    // (leftToRight + rightToLeft, i)
    Queue<Pair<Integer, Integer>> leftBridgeQueue = createMaxHeap();
    Queue<Pair<Integer, Integer>> rightBridgeQueue = createMaxHeap();
    // (time to be idle, i)
    Queue<Pair<Integer, Integer>> leftWorkers = createMinHeap();
    Queue<Pair<Integer, Integer>> rightWorkers = createMinHeap();

    for (int i = 0; i < k; ++i)
      leftBridgeQueue.offer(new Pair<>(
          /*leftToRight*/ time[i][0] + /*rightToLeft*/ time[i][2], i));

    while (n > 0 || !rightBridgeQueue.isEmpty() || !rightWorkers.isEmpty()) {
      // Idle left workers get on the left bridge.
      while (!leftWorkers.isEmpty() && leftWorkers.peek().getKey() <= ans) {
        final int i = leftWorkers.poll().getValue();
        leftBridgeQueue.offer(new Pair<>(
            /*leftToRight*/ time[i][0] + /*rightToLeft*/ time[i][2], i));
      }
      // Idle right workers get on the right bridge.
      while (!rightWorkers.isEmpty() && rightWorkers.peek().getKey() <= ans) {
        final int i = rightWorkers.poll().getValue();
        rightBridgeQueue.offer(new Pair<>(
            /*leftToRight*/ time[i][0] + /*rightToLeft*/ time[i][2], i));
      }

      if (!rightBridgeQueue.isEmpty()) {
        // If the bridge is free, the worker waiting on the right side of the
        // bridge gets to cross the bridge. If more than one worker is waiting
        // on the right side, the one with the lowest efficiency crosses first.
        final int i = rightBridgeQueue.poll().getValue();
        ans += /*rightToLeft*/ time[i][2];
        leftWorkers.offer(new Pair<>(ans + /*putNew*/ time[i][3], i));
      } else if (!leftBridgeQueue.isEmpty() && n > 0) {
        // If the bridge is free and no worker is waiting on the right side, and
        // at least one box remains at the old warehouse, the worker on the left
        // side of the river gets to cross the bridge. If more than one worker
        // is waiting on the left side, the one with the lowest efficiency
        // crosses first.
        final int i = leftBridgeQueue.poll().getValue();
        ans += /*leftToRight*/ time[i][0];
        rightWorkers.offer(new Pair<>(ans + /*pickOld*/ time[i][1], i));
        --n;
      } else {
        // Advance the time of the last crossing worker.
        ans = Math.min(!leftWorkers.isEmpty() && n > 0 ? leftWorkers.peek().getKey()
                                                       : Integer.MAX_VALUE,
                       !rightWorkers.isEmpty() ? rightWorkers.peek().getKey() : Integer.MAX_VALUE);
      }
    }

    return ans;
  }

  private Queue<Pair<Integer, Integer>> createMaxHeap() {
    return new PriorityQueue<>((a, b)
                                   -> a.getKey().equals(b.getKey()) ? b.getValue() - a.getValue()
                                                                    : b.getKey() - a.getKey());
  }

  private Queue<Pair<Integer, Integer>> createMinHeap() {
    return new PriorityQueue<>((a, b)
                                   -> a.getKey().equals(b.getKey()) ? a.getValue() - b.getValue()
                                                                    : a.getKey() - b.getKey());
  }
}
