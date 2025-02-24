#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int rollNumber;
    double score;

public:
    Student(std::string n, int r, double s) : name(n), rollNumber(r), score(s) {}

    void displayInfo() const {
        std::cout << "Name: " << name << ", Roll Number: " << rollNumber << ", Score: " << score << "\n";
    }

    double getScore() const {
        return score;
    }
};

class StudentReportSystem {
private:
    std::vector<Student> students;

public:
    void addStudent(const std::string& name, int rollNumber, double score) {
        students.emplace_back(name, rollNumber, score);
        std::cout << "Student added successfully.\n";
    }

    void displayStudents() const {
        if (students.empty()) {
            std::cout << "No students found.\n";
            return;
        }

        std::cout << "\nStudent Records:\n";
        for (const auto& student : students) {
            student.displayInfo();
        }
    }

    void calculateAverageScore() const {
        if (students.empty()) {
            std::cout << "No students to calculate average score.\n";
            return;
        }

        double totalScore = 0;
        for (const auto& student : students) {
            totalScore += student.getScore();
        }
        double averageScore = totalScore / students.size();
        std::cout << "Average Score: " << averageScore << "\n";
    }
};

int main() {
    StudentReportSystem reportSystem;
    int choice;

    do {
        std::cout << "\nStudent Report System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Students\n";
        std::cout << "3. Calculate Average Score\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int rollNumber;
                double score;

                std::cout << "Enter student name: ";
                std::cin >> name;
                std::cout << "Enter roll number: ";
                std::cin >> rollNumber;
                std::cout << "Enter score: ";
                std::cin >> score;

                reportSystem.addStudent(name, rollNumber, score);
                break;
            }
            case 2:
                reportSystem.displayStudents();
                break;
            case 3:
                reportSystem.calculateAverageScore();
                break;
            case 4:
                std::cout << "Exiting the system. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}