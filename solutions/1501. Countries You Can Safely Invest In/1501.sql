SELECT Country.name AS country
FROM Person
INNER JOIN Country
  ON (SUBSTRING(Person.phone_number, 1, 3) = Country.country_code)
INNER JOIN Calls
  ON (Person.id IN (Calls.caller_id, Calls.callee_id))
GROUP BY 1
HAVING AVG(Calls.duration) > (
    SELECT AVG(duration) FROM Calls
  );
