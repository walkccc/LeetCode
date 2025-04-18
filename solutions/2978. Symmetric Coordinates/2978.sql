WITH
  SymmetricCoordinates AS (
    SELECT DISTINCT C1.x, C1.y
    FROM Coordinates AS C1
    INNER JOIN Coordinates AS C2
      ON (C1.x, C1.y) = (C2.y, C2.x)
    WHERE C1.x < C1.y
    UNION ALL
    SELECT x, y
    FROM Coordinates
    WHERE x = y
    GROUP BY 1
    HAVING COUNT(*) > 1
  )
SELECT x, y
FROM SymmetricCoordinates
ORDER BY 1, 2;
