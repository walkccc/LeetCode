from sortedcontainers import SortedSet


class FileSharing:
  def __init__(self, m: int):
    self.userToChunks: dict[int, SortedSet[int]] = {}
    self.chunkToUsers: dict[int, SortedSet[int]] = {}
    self.availableUserIds: list[int] = []

  def join(self, ownedChunks: list[int]) -> int:
    userId = (heapq.heappop(self.availableUserIds) if self.availableUserIds
              else len(self.userToChunks) + 1)
    self.userToChunks[userId] = SortedSet(ownedChunks)
    for chunk in ownedChunks:
      self.chunkToUsers.setdefault(chunk, SortedSet()).add(userId)
    return userId

  def leave(self, userID: int) -> None:
    if userID not in self.userToChunks:
      return
    for chunk in self.userToChunks[userID]:
      self.chunkToUsers[chunk].discard(userID)
      if not self.chunkToUsers[chunk]:
        del self.chunkToUsers[chunk]
    del self.userToChunks[userID]
    heapq.heappush(self.availableUserIds, userID)

  def request(self, userID: int, chunkID: int) -> list[int]:
    if chunkID not in self.chunkToUsers:
      return []
    userIds = list(self.chunkToUsers[chunkID])
    self.userToChunks[userID].add(chunkID)
    self.chunkToUsers[chunkID].add(userID)
    return userIds
