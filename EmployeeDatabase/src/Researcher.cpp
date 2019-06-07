//
//  Researcher.cpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#include "Researcher.hpp"

Researcher::Researcher()
:Employee(), mPhdThesisTitle("Not Set"), mPhdSchool("Not Set")
{ mType = "Researcher"; }

Researcher::Researcher(
                       std::string firstName, std::string lastName, std::string type, float salary,
                       std::string phdSchool, std::string phdThesisTitle
                       )
:Employee(firstName, lastName, type, salary),
mPhdSchool(phdSchool),
mPhdThesisTitle(phdThesisTitle)
{}

std::string Researcher::getPhdSchool() {
    return mPhdSchool;
}

std::string Researcher::getPhdThesisTitle() {
    return mPhdThesisTitle;
}

void Researcher::setPhdSchool(std::string s) {
    mPhdSchool = s;
}

void Researcher::setPhdThesisTitle(std::string p) {
    mPhdThesisTitle = p;
}

void Researcher::printInformation() {
    std::cout << "*====================*"  << std::endl;
    std::cout << "Name: " << getFullName()  << std::endl;
    std::cout << "Position: " << getType() << std::endl;
    std::cout << "School (PhD): " << mPhdSchool << std::endl;
    std::cout << "Thesis: " << mPhdThesisTitle << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "*====================*"  << std::endl;
}


void Researcher::saveSelfToDataBase(fstream& database) {
    if (!database.is_open()) {
        std::cout << "Database currently not available..." << std::endl;
        return;
    }
    
    database << "Account Type: " << getType() << std::endl;
    database << "First Name: " << getFirstName() << std::endl;
    database << "Last Name: "<< getLastName() << std::endl;
    database << "PhD School: "<< mPhdSchool << std::endl;
    database << "Thesis: "<< mPhdThesisTitle << std::endl;
    database << "Salary: " << getSalary() << std::endl;
    database << "--END--" << std::endl;
}