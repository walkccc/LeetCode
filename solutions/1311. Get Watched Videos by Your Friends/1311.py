class Solution:
  def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]],
                             id: int, level: int) -> List[str]:
    visited = [False] * 100
    visited[id] = True
    q = deque([id])
    count = Counter()

    for _ in range(level):
      for _ in range(len(q)):
        curr = q.popleft()
        for friend in friends[curr]:
          if not visited[friend]:
            visited[friend] = True
            q.append(friend)

    for friend in q:
      for video in watchedVideos[friend]:
        count[video] += 1

    return sorted(count.keys(), key=lambda video: (count[video], video))
