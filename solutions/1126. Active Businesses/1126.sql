WITH
  AvgEvents AS (
    SELECT
      business_id,
      AVG(occurrences) OVER(PARTITION BY event_type) AS event_avg_occurrences,
      occurrences
    FROM Events
  )
SELECT business_id
FROM AvgEvents
GROUP BY 1
HAVING SUM(IF(occurrences > event_avg_occurrences, 1, 0)) > 1;
