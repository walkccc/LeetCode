class Solution:
  def numTeams(self, rating: List[int]) -> int:
    ans = 0

    for i in range(1, len(rating) - 1):
      # Calculate soldiers on the left with less//greater ratings.
      leftLess = 0
      leftGreater = 0
      for j in range(i):
        if rating[j] < rating[i]:
          leftLess += 1
        elif rating[j] > rating[i]:
          leftGreater += 1
      # Calculate soldiers on the right with less//greater ratings.
      rightLess = 0
      rightGreater = 0
      for j in range(i + 1, len(rating)):
        if rating[j] < rating[i]:
          rightLess += 1
        elif rating[j] > rating[i]:
          rightGreater += 1
      ans += leftLess * rightGreater + leftGreater * rightLess

    return ans
