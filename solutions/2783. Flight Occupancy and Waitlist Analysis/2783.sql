SELECT
  Flights.flight_id,
  LEAST(Flights.capacity, COUNT(Passengers.flight_id)) AS booked_cnt,
  GREATEST(0, COUNT(Passengers.flight_id) - Flights.capacity) AS waitlist_cnt
FROM Flights
LEFT JOIN Passengers
  USING (flight_id)
GROUP BY 1
ORDER BY 1;
