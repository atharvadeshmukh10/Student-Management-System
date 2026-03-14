#include <iostream>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "-----------------\n";
    }
};

int main() {

    Student students[100];
    int count = 0;
    int choice;

    while(true) {

        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Remove Student\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {

            int newId;
            bool duplicate = false;

            cout << "Enter ID: ";
            cin >> newId;

            for(int i = 0; i < count; i++) {
                if(students[i].id == newId) {
                    duplicate = true;
                    break;
                }
            }

            if(duplicate) {
                cout << "Student ID already exists.\n";
            }
            else {
                students[count].id = newId;

                cout << "Enter Name: ";
                cin >> students[count].name;

                cout << "Enter Age: ";
                cin >> students[count].age;

                count++;
                cout << "Student added successfully.\n";

            }
        }   

        else if(choice == 2) {

            for(int i = 0; i < count; i++) {
                students[i].display();
            }

        }

        else if(choice == 3) {

            int searchId;
            bool found = false;

            cout << "Enter ID to search: ";
            cin >> searchId;

            for(int i = 0; i < count; i++) {
                if(students[i].id == searchId) {
                    students[i].display();
                    found = true;
                }
            }

            if(!found) {
                cout << "Student not found.\n";
            }

        }

        else if(choice == 4) {

            int removeId;
            bool found = false;

            cout << "Enter ID to remove: ";
            cin >> removeId;

            for(int i = 0; i < count; i++) {

                if(students[i].id == removeId) {

                    for(int j = i; j < count-1; j++) {
                        students[j] = students[j+1];
                    }

                    count--;
                    found = true;
                    cout << "Student removed successfully.\n";
                    break;
                }
            }

            if(!found) {
                cout << "Student not found.\n";
            }

        }

        else if(choice == 5) {
            break;
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
