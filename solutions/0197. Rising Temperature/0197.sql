SELECT Today.id
FROM Weather AS Today
INNER JOIN Weather AS Yesterday
  ON (DATE_SUB(Today.recordDate, INTERVAL 1 DAY) = Yesterday.recordDate)
WHERE Today.temperature > Yesterday.temperature;
