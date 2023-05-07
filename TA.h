#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#ifndef ASSIGNMENT3_TA_H
#define ASSIGNMENT3_TA_H


class TA {
public:
    TA(int, int, std::string, int, std::string);
    void printTAs() const;
    std::string getStatus()const{return status;}
    std::string getFirstName()const{return firstName;}
    int getYearHired()const {return yearHired;}
    int getAge()const {return age;}
    int getStudentID()const {return studentID;}
    static bool checkIfDuplicate(std::vector<TA>&vec, int i);
    static void addNewTA(std::vector<TA>&vec);

    static void sortYearAsc(std::vector<TA>&vec);
    static void sortYearDes(std::vector<TA>&vec);
    static void sortAgeAsc(std::vector<TA>&vec);
    static void sortAgeDes(std::vector<TA>&vec);
    static void sortStatusAsc(std::vector<TA>&vec);
    static void sortStatusDes(std::vector<TA>&vec);
    static void sortIdAsc(std::vector<TA>&vec);
    static void sortIdDes(std::vector<TA>&vec);
    static void sortNameAsc(std::vector<TA>&vec);
    static void sortNameDes(std::vector<TA>&vec);

private:
    int yearHired, age, studentID;
    std::string status, firstName;
};


#endif //ASSIGNMENT3_TA_H
