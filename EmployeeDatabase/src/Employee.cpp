//
//  Employee.cpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#include "Employee.hpp"

Employee::Employee() {
    mSalary = 0.0f;
    mType = "Not Set";
    mFirstName = "Not Set";
    mLastName = "Not Set";
}

Employee::Employee(std::string firstName, std::string lastName, std::string type, float salary) {
    mFirstName = firstName;
    mLastName = lastName;
    mType = type;
    mSalary = salary;
}

void Employee::setFullName(std::string firstName, std::string lastName) {
    mFirstName = firstName;
    mLastName = lastName;
}

void Employee::setFirstName(std::string firstName) {
    mFirstName = firstName;
}

void Employee::setLastName(std::string lastName) {
    mLastName = lastName;
}

void Employee::setType(std::string t) {
    mType = t;
}

void Employee::setSalary(float s) {
    mSalary = s;
}

Employee::~Employee() {
    
}

