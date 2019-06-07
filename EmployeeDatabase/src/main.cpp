//
//  main.cpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#include <iostream>
#include <limits>
#include "Employee.hpp"
#include "Manager.hpp"
#include "Engineer.hpp"
#include "Researcher.hpp"
#include "HelperFunctions.hpp"
#include "EmployeeVectorDatabase.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::flush;

int main(int argc, const char * argv[]) {
    // insert code here...
    EmployeeVectorDatabase* database = new EmployeeVectorDatabase();
    
    // Employee* manager = new Manager("Kim", "Sunga", "Manager", 1200, 5, 5);
    // Employee* engineer = new Engineer("Kinowe", "Sunga", "Engineer", 1500, "Computer", 3, true);
    // Employee* researcher = new Researcher("Pypert", "Sunga", "Researcher", 2000, "UP Diliman", "Nakakataba ang Lechon");
    
    enum MenuOptions {AddEmployee = 1, DeleteEmployee, ViewData, Save, Exit};
    bool done = false;
    while(!done) {
        cout << "1) Add an Employee, 2) Delete an Employee 3) View Content, 4) Save To Database, 5) Exit: " << flush;
        int option = pypert::GetValidSignedIntegerInput();
        switch (option) {
            case AddEmployee:
                database->addEmployeePrompt();
                break;
            case DeleteEmployee:
                database->deleteEmployeePrompt();
                break;
            case ViewData:
                database->viewData();
                break;
            case Save:
                cout << "Saving to Database....." << endl;
                database->save();
                break;
            case Exit:
                cout << "Exiting..." << endl;
                done = true;
                break;
            default:
                cout << "Unknow Operation try again..." << endl;
                break;
        }
    }

    database->save();
    
    return 0;
}
