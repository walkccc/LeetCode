class Solution:
  def findHighAccessEmployees(self, access_times: list[list[str]]) -> list[str]:
    ans = set()

    access_times.sort()

    for i in range(len(access_times) - 2):
      name = access_times[i][0]
      if name in ans:
        continue
      if name != access_times[i + 2][0]:
        continue
      if int(access_times[i + 2][1]) - int(access_times[i][1]) < 100:
        ans.add(name)

    return list(ans)
