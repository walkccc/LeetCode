WITH
  NumbersMetadata AS (
    SELECT
      *,
      SUM(frequency) OVER(ORDER BY num) AS running_frequency,
      (SUM(frequency) OVER()) / 2 AS median_frequency
    FROM Numbers
  )
SELECT AVG(num) AS median
FROM NumbersMetadata
WHERE median_frequency BETWEEN running_frequency - frequency AND running_frequency;
