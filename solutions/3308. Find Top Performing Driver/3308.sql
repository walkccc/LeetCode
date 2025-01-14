WITH
  DriverPerformance AS (
    SELECT
      Vehicles.fuel_type,
      Vehicles.driver_id,
      Drivers.accidents,
      ROUND(AVG(Trips.rating), 2) AS rating,
      SUM(Trips.distance) AS distance
    FROM Vehicles
    INNER JOIN Trips
      USING (vehicle_id)
    INNER JOIN Drivers
      USING (driver_id)
    GROUP BY 1, 2
  ),
  RankedDrivers AS (
    SELECT
      *,
      RANK() OVER(
        PARTITION BY fuel_type
        ORDER BY rating DESC, distance DESC, accidents
      ) AS `rank`
    FROM DriverPerformance
  )
SELECT fuel_type, driver_id, rating, distance
FROM RankedDrivers
WHERE `rank` = 1
ORDER BY 1;
