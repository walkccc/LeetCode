class T {
  public int weight;
  public int index;
  public int freeTime;
  public T(int weight, int index, int freeTime) {
    this.weight = weight;
    this.index = index;
    this.freeTime = freeTime;
  }
}

class Solution {
  public int[] assignTasks(int[] servers, int[] tasks) {
    final int n = servers.length;
    final int m = tasks.length;
    int[] ans = new int[m];
    Queue<T> free = new PriorityQueue<>(
        Comparator.comparing((T t) -> t.weight).thenComparing((T t) -> t.index));
    Queue<T> used = new PriorityQueue<>(Comparator.comparing((T t) -> t.freeTime)
                                            .thenComparing((T t) -> t.weight)
                                            .thenComparing((T t) -> t.index));

    for (int i = 0; i < n; ++i)
      free.offer(new T(servers[i], i, 0));

    for (int i = 0; i < m; ++i) { // i := the current time
      final int executionTime = tasks[i];
      // Poll all servers that'll be free at time i.
      while (!used.isEmpty() && used.peek().freeTime <= i)
        free.offer(used.poll());
      if (free.isEmpty()) {
        T server = used.poll();
        ans[i] = server.index;
        server.freeTime += executionTime;
        used.offer(server);
      } else {
        T server = free.poll();
        ans[i] = server.index;
        server.freeTime = i + executionTime;
        used.offer(server);
      }
    }

    return ans;
  }
}
