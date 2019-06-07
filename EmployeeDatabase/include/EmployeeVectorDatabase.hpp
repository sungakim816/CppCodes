//
//  EmployeeVectorDatabase.hpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#ifndef EmployeeVectorDatabase_hpp
#define EmployeeVectorDatabase_hpp

#include "Employee.hpp"
#include "Manager.hpp"
#include "Engineer.hpp"
#include "Researcher.hpp"
#include "HelperFunctions.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::flush;
using std::endl;
using std::vector;
using std::fstream;
using std::getline;
using std::stringstream;

class EmployeeVectorDatabase {
public:
    EmployeeVectorDatabase();
    EmployeeVectorDatabase(string dbName);
    void addEmployee(Employee*& employee);
    void addManager(Manager*& manager);
    void addEngineer(Engineer*& engineer);
    void addResearcher(Researcher*& researcher);
    
    void addEmployeePrompt();
    void addManagerFormPrompt();
    void addEngineerFormPrompt();
    void addResearcherFormPrompt();
    
    void deleteEmployeePrompt();
    void deleteEmployee(Employee*& employee);
    void deleteManager(Manager*& manager);
    void deleteEngineer(Engineer*& engineer);
    void deleteResearcher(Researcher*& researcher);
    void printQueryResult(vector<Employee*>  result);
    void setDatabaseName(string dbName);
    string getDatabaseName();
    void viewData();
    void save();
    
private:
    string mDbName;
    fstream mDatabaseTxt;
    vector<Employee*> mEmployeeVectorDatabase;
    vector<Employee*> mQueryResult;
    
protected:
    void addManager();
    void addEngineer();
    void addResearcher();
};

#endif /* EmployeeVectorDatabase_hpp */
