class Solution {
  public int[] countMentions(int numberOfUsers, List<List<String>> events) {
    record OfflineUser(int returnTimestamp, int userId) {}
    int[] ans = new int[numberOfUsers];
    boolean[] online = new boolean[numberOfUsers];
    Arrays.fill(online, true);
    // min-heap to track users that are offline
    Queue<OfflineUser> offlineQueue =
        new PriorityQueue<>(Comparator.comparingInt(OfflineUser::returnTimestamp));
    int allMentionsCount = 0;

    events.sort(
        Comparator.comparingInt((List<String> event) -> Integer.parseInt(event.get(1)))
            .thenComparing((List<String> event) -> event.get(0), Comparator.reverseOrder()));

    for (List<String> event : events) {
      final String eventType = event.get(0);
      final int timestamp = Integer.parseInt(event.get(1));
      // Bring users back online if their offline period has ended.
      while (!offlineQueue.isEmpty() && offlineQueue.peek().returnTimestamp <= timestamp)
        online[offlineQueue.poll().userId] = true;
      if (eventType.equals("MESSAGE")) {
        String mentionsString = event.get(2);
        if (mentionsString.equals("ALL")) {
          ++allMentionsCount;
        } else if (mentionsString.equals("HERE")) {
          for (int userId = 0; userId < numberOfUsers; ++userId)
            if (online[userId])
              ++ans[userId];
        } else {
          for (final int userId : getUserIds(mentionsString))
            ++ans[userId];
        }
      } else if (eventType.equals("OFFLINE")) {
        final int userId = Integer.parseInt(event.get(2));
        online[userId] = false;
        // Add to queue to bring back online after 60 units
        offlineQueue.offer(new OfflineUser(timestamp + 60, userId));
      }
    }

    // Add the "ALL" mentions to all users.
    for (int userId = 0; userId < numberOfUsers; ++userId)
      ans[userId] += allMentionsCount;

    return ans;
  }

  private List<Integer> getUserIds(final String s) {
    List<Integer> integers = new ArrayList<>();
    for (String part : s.split(" "))
      integers.add(Integer.parseInt(part.substring(2)));
    return integers;
  }
}
