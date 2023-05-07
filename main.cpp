/*
 * Justin Sciortino 40247931
 * Stuart Thiel COEN 244*/
#include <iostream>
#include "TA.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
using namespace std;

/*
 * PLEASE READ
 * When writing back to the file after editing the TAs.txt or sorting, I will be writing to testTAs.txt
 * I did this so that who ever is correcting the assignment is able to see the modifications
 * If I wanted to modify TAs.txt I would simply put that as the parameter in the outputFile function call
 * TAs.txt contains the unmodified TA records, testTAs.txt contains the modified records*/

void getFile(string fname, vector<TA>&vec, int &n){
    ifstream file(fname);
    string line;
    //int n;
    getline(file, line);
    n = stoi(line);
    if(file.is_open()){
        int year, age, id;
        string stat, fn;
        while (file >> year >> age >> stat >> id >> fn) {
            vec.emplace_back(year, age, stat, id, fn);
        }
        //return n;
    } else {
        cout << "Error: could not open file " << fname << endl;
    }
    file.close();
}

void outputFile(string fname, vector<TA>&vec, int n){
    ofstream outfile(fname);  //DON'T FORGET TO REPLACE BACK WITH TAs.txt
    if(outfile.is_open()) {
        outfile << vec.size() << endl;
        for(const TA& ta : vec) {
            outfile << setw(10)<<left<<ta.getYearHired() <<setw(7)<<left << ta.getAge() << setw(10)<<left
            << ta.getStatus()<< setw(12)<<left << ta.getStudentID() << setw(10)<<left<< ta.getFirstName() << endl;
        }
    } else {
        cout << "Error: could not open file " << fname << " for writing" << endl;
    }
    outfile.close();
}

int main() {
    vector<TA>TAvec;
    int numberStudents;
    string filename ="TAs.txt";
    getFile(filename, TAvec, numberStudents);

    cout<<"Initial Student File: "<<'\n'<<endl;
    for (const auto& ta:TAvec){
        ta.printTAs();
    }
    cout<<"\n"<<"After Correction:"<<"\n"<<endl;

    for(auto i = TAvec.begin(); i!=TAvec.end();){
        if(i->getStatus()=="Alumn"){
            i = TAvec.erase(i);
        }else{
            ++i;
        }
    }
    for (const auto& ta:TAvec){
        ta.printTAs();
    }
    outputFile("testTAs.txt", TAvec, numberStudents);
    int j=0;
    while(j!=3) {
        try {
            string option;
            cout << "\nMenu" << "\n" << "1 - Enter a new TA" << "\n" << "2 - Sort one of the columns" << "\n"
                 << "3 - Exit\n" <<endl;
            cout<<"Option: ";
            getline(cin, option);
            int input = stoi(option);
            if (input<1 ||input>3) {
                throw out_of_range("Input is out of range. Enter 1, 2 or 3 only.");
            }
            if (input == 1) {
                TA::addNewTA(TAvec);
                outputFile("testTAs.txt", TAvec, numberStudents+1);
            }
            if (input == 2) {
                try{
                    string sort_option;
                    cout<<"Sort by:\n1 - Year Hired\n2 - Age\n3 - Status\n4 - Student ID\n5 - Name"<<endl;
                    cout<<"Option: ";
                    getline(cin,sort_option);
                    int opt=stoi(sort_option);
                    if(opt<1 || opt>5){
                        throw out_of_range("Input is out of range. Enter 1 to 5 only.");
                    }
                    try{
                        string asc_des;
                        cout<<"\tSort by:\n\t1 - Ascending order\n\t2 - Descending order"<<endl;
                        cout<<"\tOption: ";
                        getline(cin, asc_des);
                        int AD = stoi(asc_des);
                        if(AD<1 || AD>2){
                            throw out_of_range("Input is out of range. Enter 1 or 2 only.");
                        }
                        switch (opt) {
                            case 1:
                                if(AD==1){
                                    TA::sortYearAsc(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }else{
                                    TA::sortYearDes(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }
                                break;
                            case 2:
                                if(AD==1){
                                    TA::sortAgeAsc(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }else{
                                    TA::sortAgeDes(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }
                                break;
                            case 3:
                                if(AD==1){
                                    TA::sortStatusAsc(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }else{
                                    TA::sortStatusDes(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }
                                break;
                            case 4:
                                if(AD==1){
                                    TA::sortIdAsc(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }else{
                                    TA::sortIdDes(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }
                                break;
                            case 5:
                                if(AD==1){
                                    TA::sortNameAsc(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }else{
                                    TA::sortNameDes(TAvec);
                                    outputFile("testTAs.txt", TAvec, numberStudents);
                                    for (const auto& ta:TAvec){
                                        ta.printTAs();
                                    }
                                }
                                break;
                        }
                    }catch(const invalid_argument &e){
                        throw;
                    }catch(const out_of_range &e){
                        throw;
                    }
                }catch(const invalid_argument &e){
                    throw;
                }catch(const out_of_range &e){
                    throw;
                }
            }
            if(input==3){
                cout<<"Exiting..."<<endl;
                j=3;
            }
        } catch (const invalid_argument &e) {
            cerr << "Error: (" << e.what() << ") Not a valid integer.\n";
        } catch (const out_of_range &e) {
            cerr << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}
