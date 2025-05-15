from sortedcontainers import SortedSet


class AuthenticationManager:
  def __init__(self, timeToLive: int):
    self.timeToLive = timeToLive
    self.tokenIdToExpiryTime = {}
    self.times = SortedSet()

  def generate(self, tokenId: str, currentTime: int) -> None:
    self.tokenIdToExpiryTime[tokenId] = currentTime
    self.times.add(currentTime)

  def renew(self, tokenId: str, currentTime: int) -> None:
    if (tokenId not in self.tokenIdToExpiryTime or
            currentTime >= self.tokenIdToExpiryTime[tokenId] + self.timeToLive):
      return
    self.times.remove(self.tokenIdToExpiryTime[tokenId])
    self.tokenIdToExpiryTime[tokenId] = currentTime
    self.times.add(currentTime)

  def countUnexpiredTokens(self, currentTime: int) -> int:
    i = self.times.bisect_left(currentTime - self.timeToLive + 1)
    # Remove expired tokens.
    for _ in range(i):
      self.times.remove(self.times[0])
    return len(self.times)
