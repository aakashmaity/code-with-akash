# Write your MySQL query statement below
select p.firstName,p.lastName,a.city,a.state
FROM Person p
Left join Address a
on p.personId=a.personId