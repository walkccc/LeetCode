class Solution:
  def hardestWorker(self, n: int, logs: list[list[int]]) -> int:
    ans = logs[0][0]
    maxWorkingTime = logs[0][1]

    for (_, prevLeaveTime), (id, leaveTime) in zip(logs, logs[1:]):
      workingTime = leaveTime - prevLeaveTime
      if workingTime > maxWorkingTime:
        ans = id
        maxWorkingTime = workingTime
      elif workingTime == maxWorkingTime:
        ans = min(ans, id)

    return ans
