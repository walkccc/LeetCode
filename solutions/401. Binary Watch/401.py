class Solution:
  def readBinaryWatch(self, turnedOn: int) -> list[str]:
    ans = []
    hours = [1, 2, 4, 8]
    minutes = [1, 2, 4, 8, 16, 32]

    def dfs(turnedOn: int, s: int, h: int, m: int) -> None:
      if turnedOn == 0:
        time = str(h) + ":" + (str(m).zfill(2))
        ans.append(time)
        return

      for i in range(s, len(hours) + len(minutes)):
        if i < 4 and h + hours[i] < 12:
          dfs(turnedOn - 1, i + 1, h + hours[i], m)
        elif i >= 4 and m + minutes[i - 4] < 60:
          dfs(turnedOn - 1, i + 1, h, m + minutes[i - 4])

    dfs(turnedOn, 0, 0, 0)
    return ans
