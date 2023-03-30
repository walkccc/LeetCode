class Solution:
  def nextGreatestLetter(self, letters: List[str], target: str) -> str:
    l = bisect.bisect_right(range(len(letters)), target,
                            key=lambda m: letters[m])
    return letters[l % len(letters)]
