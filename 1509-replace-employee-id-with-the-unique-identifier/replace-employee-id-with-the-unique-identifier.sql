# Write your MySQL query statement below
select  r.unique_id,l.name from employees l left join employeeuni r on l.id = r.id 