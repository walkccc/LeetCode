from sortedcontainers import SortedList


class TweetCounts:
  def __init__(self):
    self.tweetNameToTimes = collections.defaultdict(SortedList)

  def recordTweet(self, tweetName: str, time: int) -> None:
    self.tweetNameToTimes[tweetName].add(time)

  def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
    counts = []
    times = self.tweetNameToTimes[tweetName]
    chunk = 60 if freq == 'minute' else 3600 if freq == 'hour' else 86400

    # I := startTime of each chunk
    for i in range(startTime, endTime + 1, chunk):
      j = min(i + chunk, endTime + 1)  # EndTime of each chunk
      counts.append(bisect_left(times, j) - bisect_left(times, i))

    return counts
