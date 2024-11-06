WITH
  AccumulatedQueue AS (
    SELECT
      person_name,
      SUM(weight) OVER(ORDER BY turn) AS accumulated_weight
    FROM Queue
  )
SELECT person_name
FROM AccumulatedQueue
WHERE accumulated_weight <= 1000
ORDER BY accumulated_weight DESC
LIMIT 1;
