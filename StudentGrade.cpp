#include <iostream>
#include <vector>
struct Student {
    std::string name;
    int id;
    double assignmentScore;
    double quizScore;
    double examScore;
    double overallGrade;
    char letterGrade;
    std::string feedback;
};
double getValidInput(const std::string& prompt, double minValue, double maxValue) {
    double input;
    do {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail() || input < minValue || input > maxValue) {
            std::cin.clear();
            
            std::cout << "Invalid input. Please enter a value between " << minValue << " and " << maxValue << "." << std::endl;
        } else {
            break;
        }
    } while (true);
    return input;
}

void calculateGrade(Student& student, double assignmentWeight, double quizWeight, double examWeight) {
    student.overallGrade = (student.assignmentScore * assignmentWeight + student.quizScore * quizWeight + student.examScore * examWeight) / (assignmentWeight + quizWeight + examWeight);

    if (student.overallGrade >= 90.0) {
        student.letterGrade = 'A';
        student.feedback = "Congratulations! Excellent performance.";
    } else if (student.overallGrade >= 80.0) {
        student.letterGrade = 'B';
        student.feedback = "Well done!";
    } else if (student.overallGrade >= 70.0) {
        student.letterGrade = 'C';
        student.feedback = "Good effort. Keep it up!";
    } else if (student.overallGrade >= 60.0) {
        student.letterGrade = 'D';
        student.feedback = "You may want to consider additional study efforts.";
    } else {
        student.letterGrade = 'F';
        student.feedback = "Unfortunately, you did not pass. Please review the material.";
    }
}
void displayResults(const Student& student) {
    std::cout << "Final Grade for " << student.name << " (ID: " << student.id << "): "
              << "Overall Grade: " << student.overallGrade << " (Letter Grade: " << student.letterGrade << ")" << std::endl;
    std::cout << "Feedback: " << student.feedback << std::endl << std::endl;
}

int main() {
    std::vector<Student> students;

    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        Student currentStudent;

        std::cout << "\nEnter details for Student " << i + 1 << ":" << std::endl;
        std::cout << "Name: ";
        std::cin.ignore(); 
        std::getline(std::cin, currentStudent.name);
        std::cout << "ID: ";
        std::cin >> currentStudent.id;
        currentStudent.assignmentScore = getValidInput("Enter assignment score (0-100): ", 0.0, 100.0);
        currentStudent.quizScore = getValidInput("Enter quiz score (0-100): ", 0.0, 100.0);
        currentStudent.examScore = getValidInput("Enter exam score (0-100): ", 0.0, 100.0);
        double assignmentWeight = getValidInput("Enter weightage for assignments (0-1): ", 0.0, 1.0);
        double quizWeight = getValidInput("Enter weightage for quizzes (0-1): ", 0.0, 1.0);
        double examWeight = getValidInput("Enter weightage for exams (0-1): ", 0.0, 1.0);
        calculateGrade(currentStudent, assignmentWeight, quizWeight, examWeight);
        displayResults(currentStudent);
        students.push_back(currentStudent);
    }

    return 0;
}
