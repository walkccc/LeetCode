class Solution:
  def canConvert(self, str1: str, str2: str) -> bool:
    if str1 == str2:
      return True

    mappings = {}

    for a, b in zip(str1, str2):
      if mappings.get(a, b) != b:
        return False
      mappings[a] = b

    # No letter in the str1 maps to > 1 letter in the str2 and there is at
    # lest one temporary letter can break any loops.
    return len(set(str2)) < 26
