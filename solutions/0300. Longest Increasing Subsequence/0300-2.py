class Solution:
  def lengthOfLIS(self, nums: List[int]) -> int:
    # tail[i] := the minimum tail of all increasing subseqs having length i + 1
    # it's easy to see that tail must be an increasing array
    tail = []

    for num in nums:
      if not tail or num > tail[-1]:
        tail.append(num)
      else:
        tail[bisect_left(tail, num)] = num

    return len(tail)
