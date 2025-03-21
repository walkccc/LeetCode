class Solution {
  public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
    List<Integer> ans = new ArrayList<>();
    int[] times = new int[k];
    TreeSet<Integer> idleServers = new TreeSet<>();
    // (endTime, server)
    Queue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));

    for (int i = 0; i < k; ++i)
      idleServers.add(i);

    for (int i = 0; i < arrival.length; ++i) {
      // Pop all the servers that are available now.
      while (!minHeap.isEmpty() && minHeap.peek().getKey() <= arrival[i]) {
        idleServers.add(minHeap.peek().getValue());
        minHeap.poll();
      }
      // Get the next available server.
      final int server = getNextAvailableServer(idleServers, i, k);
      if (server == -1)
        continue;
      ++times[server];
      minHeap.offer(new Pair<>(arrival[i] + load[i], server));
      idleServers.remove(server);
    }

    final int busiest = Arrays.stream(times).max().getAsInt();
    for (int i = 0; i < k; ++i)
      if (times[i] == busiest)
        ans.add(i);
    return ans;
  }

  private int getNextAvailableServer(TreeSet<Integer> idleServers, int ithRequest, int k) {
    if (idleServers.isEmpty())
      return -1;
    Integer server = idleServers.ceiling(ithRequest % k);
    return server == null ? idleServers.first() : server;
  }
}
