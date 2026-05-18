#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:

    // Add Student
    void addStudent()
    {
        ofstream file("students.txt", ios::app);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        file << rollNo << endl;
        file << name << endl;
        file << marks << endl;

        file.close();

        cout << "\nStudent Record Added Successfully!\n";
    }

    // Display Students
    void displayStudents()
    {
        ifstream file("students.txt");

        cout << "\n----- Student Records -----\n";

        while (file >> rollNo)
        {
            file.ignore();
            getline(file, name);

            file >> marks;
            file.ignore();

            cout << "Roll No : " << rollNo << endl;
            cout << "Name    : " << name << endl;
            cout << "Marks   : " << marks << endl;
            cout << "---------------------------\n";
        }

        file.close();
    }

    // Delete Student
    void deleteStudent()
    {
        int deleteRoll;
        bool found = false;

        cout << "Enter Roll Number to Delete: ";
        cin >> deleteRoll;

        ifstream file("students.txt");
        ofstream temp("temp.txt");

        while (file >> rollNo)
        {
            file.ignore();
            getline(file, name);

            file >> marks;
            file.ignore();

            if (rollNo != deleteRoll)
            {
                temp << rollNo << endl;
                temp << name << endl;
                temp << marks << endl;
            }
            else
            {
                found = true;
            }
        }

        file.close();
        temp.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (found)
            cout << "\nStudent Record Deleted Successfully!\n";
        else
            cout << "\nRecord Not Found!\n";
    }

    // Update Student
    void updateStudent()
    {
        int updateRoll;
        bool found = false;

        cout << "Enter Roll Number to Update: ";
        cin >> updateRoll;

        ifstream file("students.txt");
        ofstream temp("temp.txt");

        while (file >> rollNo)
        {
            file.ignore();
            getline(file, name);

            file >> marks;
            file.ignore();

            if (rollNo == updateRoll)
            {
                found = true;

                cout << "Enter New Name: ";
                getline(cin >> ws, name);

                cout << "Enter New Marks: ";
                cin >> marks;

                temp << rollNo << endl;
                temp << name << endl;
                temp << marks << endl;

                cout << "\nRecord Updated Successfully!\n";
            }
            else
            {
                temp << rollNo << endl;
                temp << name << endl;
                temp << marks << endl;
            }
        }

        file.close();
        temp.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (!found)
            cout << "\nRecord Not Found!\n";
    }
};

int main()
{
    Student s;
    int choice;

    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                s.addStudent();
                break;

            case 2:
                s.displayStudents();
                break;

            case 3:
                s.deleteStudent();
                break;

            case 4:
                s.updateStudent();
                break;

            case 5:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
