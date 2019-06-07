//
//  Engineer.hpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#ifndef Engineer_hpp
#define Engineer_hpp

#include "Employee.hpp"
#include <iostream>
#include <string>
#include <fstream>

using std::fstream;

class Engineer : public Employee {
public:
    Engineer();
    Engineer(
             std::string firstName, std::string lastName, std::string type,
             float salary, std::string engineerType, int yearsOfExperience, bool cpp
             );
    void setKnowCpp(bool c);
    bool knowcpp();
    void setYearsOfExperience(int y);
    int getYearsOfExperience();
    void printInformation();
    void saveSelfToDataBase(fstream& database);
    
protected:
    bool mKnowCpp;
    std::string mTypeOfEngineer;
    int mYearsOfExperience = 0;
};

#endif /* Engineer_hpp */
