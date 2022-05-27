/* Write your PL/SQL query statement below */
SELECT Person.firstName,person.lastName,Address.city,Address.state
FROM Person
LEFT JOIN Address ON Person.personId=Address.personId;