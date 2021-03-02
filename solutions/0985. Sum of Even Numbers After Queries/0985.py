class Solution:
  def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
    ans = []
    summ = sum(a for a in A if a % 2 == 0)

    for query in queries:
      if A[query[1]] % 2 == 0:
        summ -= A[query[1]]
      A[query[1]] += query[0]
      if A[query[1]] % 2 == 0:
        summ += A[query[1]]
      ans.append(summ)

    return ans
