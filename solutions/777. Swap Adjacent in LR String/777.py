class Solution:
  def canTransform(self, start: str, end: str) -> bool:
    if start.replace('X', '') != end.replace('X', ''):
      return False

    i = 0  # start's index
    j = 0  # end's index

    while i < len(start) and j < len(end):
      while i < len(start) and start[i] == 'X':
        i += 1
      while j < len(end) and end[j] == 'X':
        j += 1
      if i == len(start) and j == len(end):
        return True
      if i == len(start) or j == len(end):
        return False
      # L can only move to left.
      if start[i] == 'L' and i < j:
        return False
      # R can only move to right.
      if start[i] == 'R' and i > j:
        return False
      i += 1
      j += 1

    return True
