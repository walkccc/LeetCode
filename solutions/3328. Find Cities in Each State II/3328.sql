SELECT
  state,
  GROUP_CONCAT(city ORDER BY city SEPARATOR ', ') AS cities,
  SUM(LEFT(city, 1) = LEFT(state, 1)) AS matching_letter_count
FROM Cities
GROUP BY 1
HAVING COUNT(*) >= 3 AND matching_letter_count > 0
ORDER BY matching_letter_count DESC, state;
