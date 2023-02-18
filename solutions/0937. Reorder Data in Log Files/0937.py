class Solution:
  def reorderLogFiles(self, logs: List[str]) -> List[str]:
    digitLogs = []
    letterLogs = []

    for log in logs:
      i = log.index(' ')
      if log[i + 1].isdigit():
        digitLogs.append(log)
      else:
        letterLogs.append((log[:i], log[i + 1:]))

    letterLogs.sort(key=lambda l: (l[1], l[0]))

    return [identifier + ' ' + letters for identifier, letters in letterLogs] + digitLogs
