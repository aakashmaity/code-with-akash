# Write your MySQL query statement below
Select employee_id,department_id 
From Employee
where primary_flag = 'Y'
    OR employee_id in ( 
        select employee_id from Employee group by employee_id having count(*) = 1)