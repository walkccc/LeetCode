class Solution:
  def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
    ans = []
    summ = sum(a for a in A if a % 2 == 0)

    for q in queries:
      if A[q[1]] % 2 == 0:
        summ -= A[q[1]]
      A[q[1]] += q[0]
      if A[q[1]] % 2 == 0:
        summ += A[q[1]]
      ans.append(summ)

    return ans
