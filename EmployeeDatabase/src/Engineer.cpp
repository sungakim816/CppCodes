//
//  Engineer.cpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#include "Engineer.hpp"

Engineer::Engineer()
:Employee() , mKnowCpp(false), mYearsOfExperience(0), mTypeOfEngineer("Not Set")
{ mType = "Engineer"; }

Engineer::Engineer(std::string firstName, std::string lastName, std::string type,
                   float salary, std::string engineerType, int yearsOfExperience, bool cpp
                   )
:Employee(firstName, lastName, type, salary),
mTypeOfEngineer(engineerType),
mYearsOfExperience(yearsOfExperience),
mKnowCpp(cpp)
{}

bool Engineer::knowcpp() {
    return mKnowCpp;
}

int Engineer::getYearsOfExperience() {
    return mYearsOfExperience;
}

void Engineer::setKnowCpp(bool c) {
    mKnowCpp = c;
}

void Engineer::setYearsOfExperience(int y) {
    mYearsOfExperience = y;
}

void Engineer::printInformation() {
    std::cout << "*====================*"  << std::endl;
    std::cout << "Name: " << getFullName()  << std::endl;
    std::cout << "Position: " << getType() <<"(" << mTypeOfEngineer << ") " << std::endl;
    std::cout << "Years of Experience: " << mYearsOfExperience << std::endl;
    std::string knowCpp = "";
    knowCpp = (mKnowCpp)? "Yes": "No";
    std::cout << "Know C++: "<< knowCpp << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "*====================*"  << std::endl;
}

void Engineer::saveSelfToDataBase(fstream& database) {
    if (!database.is_open()) {
        std::cout << "Database currently not available..." << std::endl;
        return;
    }
    
    database << "Account Type: "<< getType() << std::endl;
    database << "First Name: " << getFirstName() << std::endl;
    database << "Last Name: " << getLastName() << std::endl;
    database << "Field: " << mTypeOfEngineer << std::endl;
    database << "Years Of Experience: " << mYearsOfExperience << std::endl;
    database << "Know C++: "<< mKnowCpp << std::endl;
    database << "Salary: " << getSalary() << std::endl;
    database << "--END--" << std::endl;
}