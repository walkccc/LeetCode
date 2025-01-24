class Solution {
  public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends,
                                             int id, int level) {
    Queue<Integer> q = new ArrayDeque<>(List.of(id));
    boolean[] seen = new boolean[friends.length];
    seen[id] = true;
    Map<String, Integer> count = new HashMap<>();

    for (int i = 0; i < level; ++i)
      for (int sz = q.size(); sz > 0; --sz) {
        for (final int friend : friends[q.peek()])
          if (!seen[friend]) {
            seen[friend] = true;
            q.offer(friend);
          }
        q.poll();
      }

    for (final int friend : q)
      for (final String video : watchedVideos.get(friend))
        count.merge(video, 1, Integer::sum);

    List<String> ans = new ArrayList<>(count.keySet());
    ans.sort((a, b)
                 -> count.get(a).equals(count.get(b)) ? a.compareTo(b)
                                                      : count.get(a).compareTo(count.get(b)));
    return ans;
  }
}
