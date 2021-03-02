class Solution {
  public Node intersect(Node quadTree1, Node quadTree2) {
    if (quadTree1.isLeaf)
      return quadTree1.val ? quadTree1 : quadTree2;
    if (quadTree2.isLeaf)
      return quadTree2.val ? quadTree2 : quadTree1;

    Node topLeft = intersect(quadTree1.topLeft, quadTree2.topLeft);
    Node topRight = intersect(quadTree1.topRight, quadTree2.topRight);
    Node bottomLeft = intersect(quadTree1.bottomLeft, quadTree2.bottomLeft);
    Node bottomRight = intersect(quadTree1.bottomRight, quadTree2.bottomRight);

    if (topLeft.val == topRight.val &&
        topLeft.val == bottomLeft.val &&
        topLeft.val == bottomRight.val &&
        topLeft.isLeaf && topRight.isLeaf &&
        bottomLeft.isLeaf && bottomRight.isLeaf)
      return new Node(topLeft.val, true);
    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
  }
}
