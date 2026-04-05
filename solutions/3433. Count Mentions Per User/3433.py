from dataclasses import dataclass


@dataclass(frozen=True)
class OfflineUser:
  returnTimestamp: int
  userId: int

  def __lt__(self, other):
    return self.returnTimestamp < other.returnTimestamp


class Solution:
  def countMentions(
      self,
      numberOfUsers: int,
      events: list[list[str]]
  ) -> list[int]:
    ans = [0] * numberOfUsers
    online = [True] * numberOfUsers
    offlineQueue = []  # min-heap to track users that are offline
    allMentionsCount = 0

    events.sort(key=lambda x: (int(x[1]), -ord(x[0][0])))

    for eventType, t, messageContent in events:
      timestamp = int(t)
      # Bring users back online if their offline period has ended.
      while offlineQueue and offlineQueue[0].returnTimestamp <= timestamp:
        user = heapq.heappop(offlineQueue)
        online[user.userId] = True
      if eventType == "MESSAGE":
        match messageContent:
          case "ALL":
            allMentionsCount += 1
          case "HERE":
            for userId in range(numberOfUsers):
              if online[userId]:
                ans[userId] += 1
          case _:
            for userId in [int(part[2:]) for part in messageContent.split()]:
              ans[userId] += 1
      elif eventType == "OFFLINE":
        userId = int(messageContent)
        online[userId] = False
        # Add to queue to bring back online after 60 units.
        heapq.heappush(offlineQueue, OfflineUser(timestamp + 60, userId))

    # Add the "ALL" mentions to all users.
    for userId in range(numberOfUsers):
      ans[userId] += allMentionsCount
    return ans
