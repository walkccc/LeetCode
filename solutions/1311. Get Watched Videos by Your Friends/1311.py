class Solution:
  def watchedVideosByFriends(
      self,
      watchedVideos: list[list[str]],
      friends: list[list[int]],
      id: int,
      level: int,
  ) -> list[str]:
    seen = [False] * 100
    seen[id] = True
    q = collections.deque([id])
    count = collections.Counter()

    for _ in range(level):
      for _ in range(len(q)):
        curr = q.popleft()
        for friend in friends[curr]:
          if not seen[friend]:
            seen[friend] = True
            q.append(friend)

    for friend in q:
      for video in watchedVideos[friend]:
        count[video] += 1

    return sorted(count, key=lambda video: (count[video], video))
