//
//  Manager.hpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#ifndef Manager_hpp
#define Manager_hpp

#include "Employee.hpp"
#include <fstream>
#include <iostream>
#include <string>

using std::fstream;

class Manager : public Employee {

public:
    Manager();
    Manager(std::string firstName, std::string lastName, std::string type, float salary, int meetingsPerWeek, int vacationsPerYear);
    void setMeetingsPerWeek(int m);
    void setVacationsPerYear(int v);
    int getMeetingsPerWeek();
    int getVacationsPerYear();
    void printInformation();
    void saveSelfToDataBase(fstream& database);
    
protected:
    int mMeetingsPerWeek = 0;
    int mVacationsPerYear = 0;
};

#endif /* Manager_hpp */
