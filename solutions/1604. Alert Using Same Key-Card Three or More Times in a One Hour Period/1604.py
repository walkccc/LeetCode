class Solution:
  def alertNames(self, keyName: list[str], keyTime: list[str]) -> list[str]:
    nameToMinutes = collections.defaultdict(list)

    for name, time in zip(keyName, keyTime):
      minutes = self._getMinutes(time)
      nameToMinutes[name].append(minutes)

    return sorted([name for name, minutes in nameToMinutes.items()
                   if self._hasAlert(minutes)])

  def _hasAlert(self, minutes: list[int]) -> bool:
    if len(minutes) > 70:
      return True
    minutes.sort()
    for i in range(2, len(minutes)):
      if minutes[i - 2] + 60 >= minutes[i]:
        return True
    return False

  def _getMinutes(self, time: str) -> int:
    h, m = map(int, time.split(':'))
    return 60 * h + m
