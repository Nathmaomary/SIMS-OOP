#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // For std::find_if
using namespace std;

// Class for representing a student
class Student {
private:
    string name;
    int rollNumber;
    float marks;


public:
    // Constructor
    Student(string n, int r, float m) : name(n), rollNumber(r), marks(m) {}

    // Getter methods
    string getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    float getMarks() const {
        return marks;
    }

    // Setter methods
    void setName(const string& n) {
        name = n;
    }

    void setRollNumber(int r) {
        rollNumber = r;
    }

    void setMarks(float m) {
        marks = m;
    }

    // Display student details
    void displayStudent() const {
        cout << "Name: " << name << ", Roll No: " << rollNumber << ", Marks: " << marks << endl;
    }

};

// Class for managing student operations (CRUD)
class StudentManagementSystem {
private:
    vector<Student> students;

public:
    // Create - Add a new student
    void addStudent(string name, int rollNumber, float marks) {
        Student newStudent(name, rollNumber, marks);
        students.push_back(newStudent);
        cout << "Student added successfully!" << endl;
    }

    // Read - Display all students
    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students in the system." << endl;
            return;
        }

        for (const auto& student : students) {
            student.displayStudent();
        }
    }

    // Update - Update student marks by roll number
    void updateMarks(int rollNumber, float newMarks) {
        for (auto& student : students) {
            if (student.getRollNumber() == rollNumber) {
                student.setMarks(newMarks);
                cout << "Marks updated successfully!" << endl;
                return;
            }
        }
        cout << "Student with roll number " << rollNumber << " not found!" << endl;
    }

    // Delete - Delete student by roll number
    void deleteStudent(int rollNumber) {
        auto it = find_if(students.begin(), students.end(), 
                          [rollNumber](const Student& student) {
                              return student.getRollNumber() == rollNumber;
                          });
        
        if (it != students.end()) {
            students.erase(it);
            cout << "Student deleted successfully!" << endl;
        } else {
            cout << "Student with roll number " << rollNumber << " not found!" << endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;
    string name;
    int rollNumber;
    float marks;

    while (true) {
        // Display menu
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Marks\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Add student
                cout << "Enter student name: ";
                cin.ignore();  // Ignore newline left in buffer by previous input
                getline(cin, name);
                cout << "Enter roll number: ";
                cin >> rollNumber;
                cout << "Enter marks: ";
                cin >> marks;
                sms.addStudent(name, rollNumber, marks);
                break;

            case 2:
                // Display all students
                sms.displayAllStudents();
                break;

            case 3:
                // Update marks
                cout << "Enter roll number: ";
                cin >> rollNumber;
                cout << "Enter new marks: ";
                cin >> marks;
                sms.updateMarks(rollNumber, marks);
                break;

            case 4:
                // Delete student
                cout << "Enter roll number to delete: ";
                cin >> rollNumber;
                sms.deleteStudent(rollNumber);
                break;

            case 5:
                // Exit the program
                cout << "Exiting... Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
