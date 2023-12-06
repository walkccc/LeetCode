# Definition for polynomial singly-linked list.
# class PolyNode:
#   def __init__(self, x=0, y=0, next=None):
#     self.coefficient = x
#     self.power = y
#     self.next = next

class Solution:
  def addPoly(self, poly1: 'PolyNode', poly2: 'PolyNode') -> 'PolyNode':
    dummy = PolyNode()
    curr = dummy
    p = poly1  # poly1's pointer
    q = poly2  # poly2's pointer

    while p and q:
      if p.power > q.power:
        curr.next = PolyNode(p.coefficient, p.power)
        curr = curr.next
        p = p.next
      elif p.power < q.power:
        curr.next = PolyNode(q.coefficient, q.power)
        curr = curr.next
        q = q.next
      else:  # p.power == q.power
        sumCoefficient = p.coefficient + q.coefficient
        if sumCoefficient != 0:
          curr.next = PolyNode(sumCoefficient, p.power)
          curr = curr.next
        p = p.next
        q = q.next

    while p:
      curr.next = PolyNode(p.coefficient, p.power)
      curr = curr.next
      p = p.next

    while q:
      curr.next = PolyNode(q.coefficient, q.power)
      curr = curr.next
      q = q.next

    return dummy.next
