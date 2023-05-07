#include "TA.h"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
TA::TA(int y, int a, string s, int i, string f): yearHired(y), age(a), status(s), studentID(i), firstName(f) {
}

void TA::printTAs() const{
    stringstream s;
    s << setw(10) << left << yearHired;
    s << setw(7) << left << age;
    s << setw(10) << left << status;
    s << setw(12) << left << studentID;
    s << setw(10) << left << firstName;
    cout << s.str() << endl;
}

void TA::addNewTA(std::vector<TA> &vec) {
    try {
        string TAinfo;
        cout<< "Enter the information of the TA you want to add separated by tabs (Year hired, Age, Status, Student ID, First Name): ";
        getline(cin, TAinfo);
        std::replace(TAinfo.begin(), TAinfo.end(), '\t', ' ');
        std::istringstream iss(TAinfo);
        string year, Age, stu_id, first_name, status;
        iss >> year >> Age >> status >> stu_id >> first_name;
        int year_H = stoi(year);
        int age = stoi(Age);
        int ID = stoi(stu_id);
        if(year.length()!=4){
            throw string("Invalid Year. Must be 4 digits");
        }
        if(stu_id.length()!=7){
            throw string("ID must have 7 digits.");
        }
        if(age <=0){
            throw string("Age must be zero or greater.");
        }
        if(iss.fail()){
            throw string("Input format is not correct. Enter the proper information (5 fields seperated by a tab)");
        }
        if(status=="Alumn"){
           throw string("TA entered is no longer at the school (they are Alumn). Enter a proper Status.");
        }
        if(status!= "Grad" && status!="Ugrad"){
            throw string("Invalid Status entered. Try again");
        }

        if(checkIfDuplicate(vec, ID)){
            vec.emplace_back(year_H,age, status,ID,first_name);
        }else{
            bool isvalid = false;
            while(!isvalid) {
                string dup_id;
                cout << "Student ID is already in use. Try entering a new ID." << endl;
                cout << "Enter student ID: ";
                getline(cin, dup_id);
                int DUP_ID = stoi(dup_id);
                if(checkIfDuplicate(vec, DUP_ID)){
                    cout<<"\nValid ID entered."<<endl;
                    vec.emplace_back(year_H,age, status,ID,first_name);
                    isvalid= true;
                }
            }
        }
    }catch (const invalid_argument &e) {
        cerr << "Error: (" << e.what() << ") Not a valid integer.\n";
    }catch(const string& msg){
        cerr<<"Error: "<<msg<<endl;
    }catch (const out_of_range &e) {
        cerr << "Error: " << e.what() << "\n";
    }
}
bool TA::checkIfDuplicate(std::vector<TA> &vec, int i) {
    for(const auto& ta : vec) {
        if (ta.getStudentID() == i) {
            return false;
        }
    }
    return true;
}
void TA::sortYearAsc(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getYearHired() < y.getYearHired();
    });
}
void TA::sortYearDes(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getYearHired() > y.getYearHired();
    });
}
void TA::sortAgeAsc(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getAge() < y.getAge();
    });
}
void TA::sortAgeDes(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getAge() > y.getAge();
    });
}
void TA::sortStatusAsc(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getStatus() < y.getStatus();
    });
}
void TA::sortStatusDes(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getStatus() > y.getStatus();
    });
}
void TA::sortIdAsc(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getStudentID() < y.getStudentID();
    });
}
void TA::sortIdDes(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getStudentID() > y.getStudentID();
    });
}
void TA::sortNameAsc(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getFirstName() < y.getFirstName();
    });
}
void TA::sortNameDes(std::vector<TA> &vec) {
    sort(vec.begin(), vec.end(), [](const TA& x, const TA& y) {
        return x.getFirstName() > y.getFirstName();
    });
}