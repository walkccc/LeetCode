class Solution:
  def toArray(self, head: 'Optional[Node]') -> List[int]:
    ans = []
    curr = head

    while curr:
      ans.append(curr.val)
      curr = curr.next

    return ans
