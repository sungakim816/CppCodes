//
//  Researcher.hpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#ifndef Researcher_hpp
#define Researcher_hpp

#include "Employee.hpp"
#include <fstream>
#include <iostream>
#include <string>

using std::fstream;

class Researcher : public Employee {
public:
    Researcher();
    Researcher(
               std::string firstName, std::string lastName, std::string type, float salary,
               std::string phdSchool, std::string phdThesisTitle
               );
    std::string getPhdThesisTitle();
    std::string getPhdSchool();
    void setPhdThesisTitle(std::string p);
    void setPhdSchool(std::string s);
    void printInformation();
    void saveSelfToDataBase(fstream& database);
    
protected:
    std::string mPhdThesisTitle;
    std::string mPhdSchool;
};

#endif /* Researcher_hpp */
