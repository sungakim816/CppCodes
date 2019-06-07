//
//  EmployeeVectorDatabase.cpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#include "EmployeeVectorDatabase.hpp"

EmployeeVectorDatabase::EmployeeVectorDatabase() {
    mDbName = "database.txt";
    mDatabaseTxt.open(mDbName);
}

EmployeeVectorDatabase::EmployeeVectorDatabase(string dbName) {
    if (!dbName.empty()) {
        mDbName = dbName;
        mDatabaseTxt.open(mDbName);   
    } else {
        EmployeeVectorDatabase();
    }
}

void EmployeeVectorDatabase::deleteEmployee(Employee*& employee) {
    if (employee == 0) {
        cout << "Error Null Pointer" << endl;
        return;
    }
    if (mEmployeeVectorDatabase.empty()) {
        cout << "Empty Database.... " << endl;
        return;
    }
    for (size_t i = 0; i < mEmployeeVectorDatabase.size(); i++) {
            if(mEmployeeVectorDatabase[i] == employee) {
                Employee *ptr = mEmployeeVectorDatabase[i];
                mEmployeeVectorDatabase.erase(mEmployeeVectorDatabase.begin() + i);
                delete ptr;
                ptr = 0;
                return;
            }
    }
}

void EmployeeVectorDatabase::deleteManager(Manager*& manager) {
    if (manager == 0) {
        cout << "Null Pointer Error" << endl;
        return;
    }
    Employee* employee = dynamic_cast<Employee*>(manager);
    deleteEmployee(employee);
}

void EmployeeVectorDatabase::deleteEngineer(Engineer*& engineer) {
    if (engineer == 0) {
        cout << "Null Pointer Error" << endl;
        return;
    }
    Employee* employee = dynamic_cast<Employee*>(engineer);
    deleteEmployee(employee);
}

void EmployeeVectorDatabase::deleteResearcher(Researcher*& researcher){
    if (researcher == 0) {
        cout << "Null Pointer Error" << endl;
        return;
    }
    Employee* employee = dynamic_cast<Employee*>(researcher);
    deleteEmployee(employee);
}

enum ADD_OPTIONS {MANAGER = 'a', ENGINEER, RESEARCHER, EXIT = 'x'};
void EmployeeVectorDatabase::addEmployeePrompt() {
    char option;
    bool done = false;
    while (!done) {
        cout << "a) Manager, b) Engineer, c) Researcher ('x' to Cancel/Return): " << flush;
        option = pypert::GetValidCharInput();
        option = tolower(option);
        switch (option) {
        case MANAGER:
            addManagerFormPrompt();
            break;
        case ENGINEER:
            addEngineerFormPrompt();
            break;
        case RESEARCHER:
            addResearcherFormPrompt();
            break;
        case EXIT:
            done = true;
            break;
        default:
            cout << "Unknown Operation Try Again...\n:" << flush;
            break;
        }
    }
}

void EmployeeVectorDatabase::addManagerFormPrompt() {
    string firstName;
    cout << "First Name: " << flush;
    getline(cin, firstName);
    firstName = pypert::StringToTitle(firstName);
    
    string lastName;
    cout << "Last Name: " << flush;
    getline(cin, lastName);
    lastName = pypert::StringToTitle(lastName);

    float salary = 0.0f;
    cout << "Salary: " << flush;
    salary = pypert::GetValidFloatInput();
    
    int meetings = 0;
    cout << "Meetings Per Week: " << flush;
    meetings = pypert::GetValidSignedIntegerInput();
    
    int vacations = 0;
    cout << "Vacations Per Year: " << flush;
    vacations = pypert::GetValidSignedIntegerInput();
    cout << endl;
    cout << firstName << " " << lastName << " has been added (Manager).." << endl;
    Employee* manager = new Manager(firstName, lastName, "Manager", salary, meetings, vacations);
    mEmployeeVectorDatabase.push_back(manager);
}

void EmployeeVectorDatabase::addEngineerFormPrompt() {
    string firstName = "";
    cout << "First Name: " << flush;
    getline(cin, firstName);
    firstName = pypert::StringToTitle(firstName);

    string lastName = "";
    cout << "Last Name: " << flush;
    getline(cin, lastName);
    lastName = pypert::StringToTitle(lastName);
    
    float salary = 0.0f;
    cout << "Salary: " << flush;
    salary = pypert::GetValidFloatInput();

    string field = "";
    cout << "Field: " << flush;
    getline(cin, field);
    field = pypert::StringToTitle(field);

    int experience = 0;
    cout << "Years of Experience: " << flush;
    experience = pypert::GetValidFloatInput();
    
    bool kCpp = true;
    char kCPPinput;
    bool isYN = false;
    cout << "Know C++ (y/n): " << flush;
    while(!isYN) {
        kCPPinput = pypert::GetValidCharInput();
        kCPPinput = tolower(kCPPinput);
        if (kCPPinput == 'y') {
            kCpp = true;
            isYN = true;
        } else if (kCPPinput == 'n') {
            kCpp = false;
            isYN = true;
        } else {
            continue;
        }
    }

    cout << endl;
    cout << firstName << " " << lastName << " has been added (Engineer).." << endl;
    Employee* engineer = new Engineer(firstName, lastName, "Engineer", salary, field, experience, kCpp);
    mEmployeeVectorDatabase.push_back(engineer);
}

void EmployeeVectorDatabase::addResearcherFormPrompt() {
    string firstName = "";
    cout << "First Name: " << flush;
    getline(cin, firstName);
    firstName = pypert::StringToTitle(firstName);
    
    string lastName = "";
    cout << "Last Name: " << flush;
    getline(cin, lastName);
    lastName = pypert::StringToTitle(lastName);
    
    float salary = 0.0f;
    cout << "Salary: " << flush;
    salary = pypert::GetValidFloatInput();

    string phdSchool = "";
    cout << "School (PhD): " << flush;
    getline(cin, phdSchool);
    phdSchool = pypert::StringToTitle(phdSchool);

    string thesis = "";
    cout << "PhD Thesis: " << flush;
    getline(cin, thesis);
    thesis = pypert::StringToTitle(thesis);

    cout << endl;
    cout << firstName << " " << lastName << " has been added (Researcher).." << endl;
    Employee *researcher = new Researcher(firstName, lastName, "Researcher", salary, phdSchool, thesis);
    mEmployeeVectorDatabase.push_back(researcher);
}

void EmployeeVectorDatabase::deleteEmployeePrompt() {
    if (mEmployeeVectorDatabase.empty()) {
        cout << "Database is Empty..." << endl;
        return;
    }

    string lastName = "";
    cout << "Last Name: " << flush;
    getline(cin, lastName);
    lastName = pypert::StringToTitle(lastName);
    for (size_t i = 0; i < mEmployeeVectorDatabase.size(); i++) {
        if(mEmployeeVectorDatabase[i]->getLastName() == lastName) {
            mQueryResult.push_back(mEmployeeVectorDatabase[i]);
        }
    }
    if (mQueryResult.empty()) {
        cout << "Empty Result... " << endl;
        return;
    }
    int employeeIndex = 0;
    bool done = false;
    while (!done) {
        printQueryResult(mQueryResult);
        if (mQueryResult.empty()) {
            break;
        }
        stringstream converter;
        string input;
        cout << "Enter the index of the employee you want to delete: ('x' to cancel): " << flush;
        getline(cin, input);
        if (input == "x" || input == "X") {
            cout << "You Cancelled the operation.." << endl;
            break;
        }
        converter << input;
        converter >> employeeIndex;
        if (converter.fail()) {
            converter.clear();
            cout << "Invalid Try Again " << endl;
            continue;
        }
        // employeeIndex = pypert::GetValidSignedIntegerInput();
        if (employeeIndex < 0 || employeeIndex >= mQueryResult.size()) {
            cout << "Index out of bound, try again..." << endl;
            continue;
        } else {
            cout << "Are you sure to delete " 
            << mQueryResult[employeeIndex]->getFullName() 
            << " (" << mQueryResult[employeeIndex]->getType() << ") (y/n)? : " << flush;
            bool valid = false;
            while(!valid) {
                char option = pypert::GetValidCharInput();
                option = tolower(option);
                string fullName = mQueryResult[employeeIndex]->getFullName();
                switch (option){
                case 'y':
                    fullName.append(" (" + mQueryResult[employeeIndex]->getType() + ") ");
                    mQueryResult.erase(mQueryResult.begin() + employeeIndex);
                    deleteEmployee(mQueryResult[employeeIndex]);
                    cout << fullName << " has been deleted " << endl;
                    valid = true;
                    break;
                case 'n':
                    cout << "Operation has been cancelled..." << endl;
                    valid = true;
                    break;
                default:
                    cout << "Invalid Operation try again..." << endl;
                    break;
                }
            }
        }
    }
    mQueryResult.clear();
    return;
}


void EmployeeVectorDatabase::save() {
    if (mEmployeeVectorDatabase.empty()) {
        return;
    }

    if(!mDatabaseTxt.is_open()) {
        mDatabaseTxt.open(mDbName);
    }

    for (size_t i = 0; i < mEmployeeVectorDatabase.size(); i++) {
        mEmployeeVectorDatabase[i]->saveSelfToDataBase(mDatabaseTxt);
    }
    mDatabaseTxt.close();
}

void EmployeeVectorDatabase::printQueryResult(vector<Employee*> result) {
    if (result.empty()) {
        cout << "Result is empty.." << endl;
    }
    for(size_t i = 0; i < result.size(); i++) {
        cout << "[" << i << "]" 
        << result[i]->getFullName() 
        << " (" << result[i]->getType() << ")" << endl;
    }
}

void EmployeeVectorDatabase::setDatabaseName(string dbName) {
    if(dbName.empty()) {
        cout << "Empty Name..." << endl;
        return;
    }
    mDbName = dbName;
    if (mDatabaseTxt.is_open()) {
        mDatabaseTxt.close();
    }
    mDatabaseTxt.open(mDbName);
}

string EmployeeVectorDatabase::getDatabaseName() {
    if(mDbName.empty()) {
        return "Database not Set";
    }
    return mDbName;
}

void EmployeeVectorDatabase::viewData() {
    if(mEmployeeVectorDatabase.empty()) {
        cout << "Database Empty..." << endl;
        return;
    }
    cout << "Database Content: " << endl;
    for (size_t i = 0; i < mEmployeeVectorDatabase.size(); i++) {
        mEmployeeVectorDatabase[i]->printInformation();
        cout << endl;
    }
}