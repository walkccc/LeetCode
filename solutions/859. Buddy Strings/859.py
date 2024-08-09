class Solution:
  def buddyStrings(self, s: str, goal: str) -> bool:
    if len(s) != len(goal):
      return False
    if s == goal and len(set(s)) < len(s):
      return True
    diffIndices = [i for i, (a, b) in enumerate(zip(s, goal))
                   if a != b]
    return len(diffIndices) == 2 and \
        s[diffIndices[0]] == goal[diffIndices[1]] and \
        s[diffIndices[1]] == goal[diffIndices[0]]
