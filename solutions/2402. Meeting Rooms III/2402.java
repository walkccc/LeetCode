class T {
  public long endTime;
  public int roomId;
  public T(long endTime, int roomId) {
    this.endTime = endTime;
    this.roomId = roomId;
  }
}

class Solution {
  public int mostBooked(int n, int[][] meetings) {
    int[] count = new int[n];

    Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));

    Queue<T> occupied =
        new PriorityQueue<>((a, b)
                                -> a.endTime == b.endTime ? Integer.compare(a.roomId, b.roomId)
                                                          : Long.compare(a.endTime, b.endTime));
    Queue<Integer> availableRoomIds = new PriorityQueue<>();

    for (int i = 0; i < n; ++i)
      availableRoomIds.offer(i);

    for (int[] meeting : meetings) {
      final int start = meeting[0];
      final int end = meeting[1];
      // Push meetings ending before this `meeting` in occupied to the
      // `availableRoomsIds`.
      while (!occupied.isEmpty() && occupied.peek().endTime <= start)
        availableRoomIds.offer(occupied.poll().roomId);
      if (availableRoomIds.isEmpty()) {
        T t = occupied.poll();
        ++count[t.roomId];
        occupied.offer(new T(t.endTime + (end - start), t.roomId));
      } else {
        final int roomId = availableRoomIds.poll();
        ++count[roomId];
        occupied.offer(new T(end, roomId));
      }
    }

    int maxIndex = 0;
    for (int i = 0; i < n; ++i)
      if (count[i] > count[maxIndex])
        maxIndex = i;
    return maxIndex;
  }
}
