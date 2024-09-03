class Twitter:
  def __init__(self):
    self.timer = itertools.count(step=-1)
    self.tweets = collections.defaultdict(deque)
    self.followees = collections.defaultdict(set)

  def postTweet(self, userId: int, tweetId: int) -> None:
    self.tweets[userId].appendleft((next(self.timer), tweetId))
    if len(self.tweets[userId]) > 10:
      self.tweets[userId].pop()

  def getNewsFeed(self, userId: int) -> list[int]:
    tweets = list(
        heapq.merge(
            *
            (self.tweets[followee]
             for followee in self.followees[userId] | {userId})))
    return [tweetId for _, tweetId in tweets[:10]]

  def follow(self, followerId: int, followeeId: int) -> None:
    self.followees[followerId].add(followeeId)

  def unfollow(self, followerId: int, followeeId: int) -> None:
    self.followees[followerId].discard(followeeId)
