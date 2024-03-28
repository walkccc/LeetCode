SELECT ROUND(
    MIN(SQRT(POW(P1.x - P2.x, 2) + POW(P1.y - P2.y, 2))),
    2
  ) AS shortest
FROM Point2D AS P1
LEFT JOIN Point2D AS P2
  ON (P1.x, P1.y) != (P2.x, P2.y);
