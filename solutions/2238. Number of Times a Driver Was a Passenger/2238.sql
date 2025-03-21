WITH
  DriverIds AS (
    SELECT DISTINCT driver_id FROM Rides
  )
SELECT
  DriverIds.driver_id,
  COUNT(Rides.passenger_id) AS cnt
FROM DriverIds
LEFT JOIN Rides
  ON (DriverIds.driver_id = Rides.passenger_id)
GROUP BY 1;
