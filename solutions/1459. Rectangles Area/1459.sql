SELECT
  P1.id AS p1,
  P2.id AS p2,
  ABS(p1.x_value - p2.x_value) * ABS(p1.y_value - p2.y_value) AS area
FROM Points AS P1, Points AS P2
WHERE
  P1.id < P2.id
  AND P1.x_value != P2.x_value
  AND P1.y_value != P2.y_value
ORDER BY area DESC, p1, p2;
