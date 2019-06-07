//
//  Manager.cpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#include "Manager.hpp"


Manager::Manager()
:Employee(), mMeetingsPerWeek(0), mVacationsPerYear(0)
{ mType = "Manager"; }

Manager::Manager(
                 std::string firstName, std::string lastName, std::string type,
                 float salary, int meetingsPerWeek, int vacationsPerYear
                 )
:Employee(firstName, lastName, type, salary),
mMeetingsPerWeek(meetingsPerWeek),
mVacationsPerYear(vacationsPerYear)
{}

void Manager::setMeetingsPerWeek(int m) {
    mMeetingsPerWeek = m;
}

void Manager::setVacationsPerYear(int v) {
    mVacationsPerYear = v;
}

int Manager::getMeetingsPerWeek() {
    return mMeetingsPerWeek;
}

int Manager::getVacationsPerYear() {
    return mVacationsPerYear;
}

void Manager::printInformation() {
    std::cout << "*====================*"  << std::endl;
    std::cout << "Name: " << getFullName()  << std::endl;
    std::cout << "Position: " << getType() << std::endl;
    std::cout << "Meetings Per Week: " << mMeetingsPerWeek << std::endl;
    std::cout << "Vacations Per Year: " << mVacationsPerYear << std::endl;
     std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "*====================*"  << std::endl;
}

void Manager::saveSelfToDataBase(fstream& database) {
    if (!database.is_open()) {
        std::cout << "Database currently not available..." << std::endl;
        return;
    }
    
    database << "Account Type: " << getType() << std::endl;
    database << "First Name: " << getFirstName() << std::endl;
    database << "Last Name: "<< getLastName() << std::endl;
    database << "Meetings Per Week: "<< mMeetingsPerWeek << std::endl;
    database << "Vacations Per Year: " << mVacationsPerYear << std::endl;
    database << "Salary: " << getSalary() << std::endl;
    database << "--END--" << std::endl;
}