WITH
  AvgEvents AS (
    SELECT
      business_id,
      AVG(occurences) OVER(PARTITION BY event_type) AS event_avg_occurences,
      occurences
    FROM Events
  )
SELECT business_id
FROM AvgEvents
GROUP BY 1
HAVING SUM(IF(occurences > event_avg_occurences, 1, 0)) > 1;
