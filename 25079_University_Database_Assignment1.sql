create database university_27079;
use university_27079;
create table department(department_name varchar(255) primary key, building int not null, budget int not null);
create table student (student_id varchar(255) primary key, student_name varchar(255) not null, total_credits int default 190, department_name varchar(255), foreign key(department_name) references department(department_name));
create table instructor (instructor_id int primary key, instructor_name varchar(255) not null, salary int not null, department_name varchar(255),foreign key(department_name) references department(department_name));
create table course(course_id varchar(255) primary key, course_title varchar(255) not null, credits int not null, department_name varchar(255), foreign key(department_name) references department(department_name));
create table classroom (building varchar(255), room_number varchar(255), capacity int default 60, primary key(building, room_number));
create table time_slot(time_slot_id varchar(255) primary key, day varchar(255) not null, start_time time not null, end_time time not null);
