class Solution:
  def maximumTime(self, time: str) -> str:
    ans = list(time)
    if time[0] == '?':
      ans[0] = '2' if time[1] == '?' or time[1] < '4' else '1'
    if time[1] == '?':
      ans[1] = '3' if ans[0] == '2' else '9'
    if time[3] == '?':
      ans[3] = '5'
    if time[4] == '?':
      ans[4] = '9'
    return ''.join(ans)
