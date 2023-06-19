class Solution:
  def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
    idToTimes = collections.defaultdict(set)

    for id, time in logs:
      idToTimes[id].add(time)

    c = collections.Counter(len(times) for times in idToTimes.values())
    return [c[i] for i in range(1, k + 1)]
