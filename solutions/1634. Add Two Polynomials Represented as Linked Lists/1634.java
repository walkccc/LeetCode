/**
 * Definition for polynomial singly-linked list.
 * class PolyNode {
 *   int coefficient, power;
 *   PolyNode next = null;
 *   PolyNode() {}
 *   PolyNode(int x, int y) { this.coefficient = x; this.power = y; }
 *   PolyNode(int x, int y, PolyNode next) {
 *     this.coefficient = x;
 *     this.power = y;
 *     this.next = next;
 *   }
 * }
 */

class Solution {
  public PolyNode addPoly(PolyNode poly1, PolyNode poly2) {
    PolyNode dummy = new PolyNode();
    PolyNode curr = dummy;
    PolyNode p = poly1; // poly1's pointer
    PolyNode q = poly2; // poly2's pointer

    while (p != null && q != null) {
      if (p.power > q.power) {
        curr.next = new PolyNode(p.coefficient, p.power);
        curr = curr.next;
        p = p.next;
      } else if (p.power < q.power) {
        curr.next = new PolyNode(q.coefficient, q.power);
        curr = curr.next;
        q = q.next;
      } else { // p.power == q.power
        final int sumCoefficient = p.coefficient + q.coefficient;
        if (sumCoefficient != 0) {
          curr.next = new PolyNode(sumCoefficient, p.power);
          curr = curr.next;
        }
        p = p.next;
        q = q.next;
      }
    }

    while (p != null) {
      curr.next = new PolyNode(p.coefficient, p.power);
      curr = curr.next;
      p = p.next;
    }

    while (q != null) {
      curr.next = new PolyNode(q.coefficient, q.power);
      curr = curr.next;
      q = q.next;
    }

    return dummy.next;
  }
}
