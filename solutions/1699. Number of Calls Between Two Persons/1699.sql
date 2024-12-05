SELECT
  LEAST(from_id, to_id) AS person1,
  GREATEST(from_id, to_id) AS person2,
  COUNT(*) AS call_count,
  SUM(duration) AS total_duration
FROM Calls
GROUP BY 1, 2;
