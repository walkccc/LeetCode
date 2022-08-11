class Solution:
  def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
    idToTimes = defaultdict(set)

    for id, time in logs:
      idToTimes[id].add(time)

    c = Counter(len(times) for times in idToTimes.values())
    return [c[i] for i in range(1, k + 1)]
