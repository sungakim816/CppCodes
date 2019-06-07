//
//  Employee.hpp
//  EmployeeDatabase
//
//  Created by Kim Sunga on 04/06/2019.
//  Copyright © 2019 Kim Sunga. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp


#include <string>
#include <fstream>

using std::fstream;

class Employee {
public:
    Employee();
    virtual ~Employee();
    Employee(std::string firstName, std::string lastName, std::string type, float salary);
    virtual void setFullName(std::string firstName, std::string lastName);
    virtual void setLastName(std::string lastName);
    virtual void setFirstName(std::string firstName);
    virtual void setSalary(float s);
    virtual void setType(std::string t);
    
    virtual float getSalary() const { return mSalary; };
    virtual std::string getFullName() const { return mLastName + " " + mFirstName; };
    virtual std::string getLastName() const { return mLastName; };
    virtual std::string getFirstName()const { return mFirstName; };
    virtual std::string getType()const { return mType; };
    
    virtual void printInformation() = 0;
    virtual void saveSelfToDataBase(fstream& database) = 0;
    
protected:
    std::string mFirstName;
    std::string mLastName;
    std::string mType;
    float mSalary;
};

#endif /* Employee_hpp */
