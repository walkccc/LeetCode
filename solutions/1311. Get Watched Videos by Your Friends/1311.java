class Solution {
  public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends,
                                             int id, int level) {
    boolean[] visited = new boolean[friends.length];
    visited[id] = true;
    Queue<Integer> queue = new ArrayDeque<>();
    queue.add(id);
    Map<String, Integer> count = new HashMap<>();

    for (int i = 0; i < level; ++i)
      for (int j = queue.size(); j > 0; --j) {
        for (int friend : friends[queue.peek()])
          if (visited[friend] == false) {
            visited[friend] = true;
            queue.add(friend);
          }
        queue.poll();
      }

    for (int friend : queue)
      for (final String video : watchedVideos.get(friend))
        count.put(video, count.getOrDefault(video, 0) + 1);

    List<String> ans = new ArrayList<>(count.keySet());

    ans.sort((a, b) -> count.get(a) == count.get(b) ? a.compareTo(b) : count.get(a) - count.get(b));

    return ans;
  }
}
