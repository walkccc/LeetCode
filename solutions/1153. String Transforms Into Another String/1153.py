class Solution:
  def canConvert(self, str1: str, str2: str) -> bool:
    if str1 == str2:
      return True

    mappings = {}

    # No char in str1 can be mapped to > 1 char in str2
    for a, b in zip(str1, str2):
      if mappings.get(a, b) != b:
        return False
      mappings[a] = b

    # No char in str1 maps to > 1 char in str2 and
    # there is at lest one temp char can break any loops
    return len(set(str2)) < 26
