class Solution:
  def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
    visited = [False] * 100
    visited[id] = True
    queue = deque([id])
    count = Counter()

    for _ in range(level):
      for _ in range(len(queue)):
        curr = queue.popleft()
        for friend in friends[curr]:
          if not visited[friend]:
            visited[friend] = True
            queue.append(friend)

    for friend in queue:
      for video in watchedVideos[friend]:
        count[video] += 1

    return sorted(count.keys(), key=lambda video: (count[video], video))
