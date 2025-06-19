#include <iostream> // Required for input/output operations (e.g., cin, cout)
#include <vector>   // Required for using std::vector to store course data
#include <string>   // Required for using std::string

// Function to convert letter grade to grade points
// This function takes a character representing a letter grade (e.g., 'A', 'B', 'C')
// and returns the corresponding numerical grade points (e.g., 4.0 for A, 3.0 for B).
// It handles both uppercase and lowercase inputs and returns 0.0 for invalid grades.
double getGradePoints(char grade) {
    switch (toupper(grade)) { // toupper converts the character to uppercase for consistent checking
    case 'A': return 4.0;
    case 'B': return 3.0;
    case 'C': return 2.0;
    case 'D': return 1.0;
    case 'F': return 0.0;
    default:  return 0.0; // Return 0.0 for any invalid grade input
    }
}

int main() {
    // Set output precision for floating-point numbers to two decimal places
    std::cout.precision(2);
    std::cout << std::fixed; // Use fixed-point notation for consistent output formatting

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "     Welcome to the CGPA Calculator!      " << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    int numCourses; // Variable to store the total number of courses

    // Prompt the user to enter the number of courses
    std::cout << "Enter the number of courses taken: ";
    std::cin >> numCourses; // Read the number of courses from user input

    // Input validation: Ensure the number of courses is positive
    while (numCourses <= 0) {
        std::cout << "Number of courses must be positive. Please re-enter: ";
        std::cin >> numCourses;
    }

    // Vectors to store course details
    std::vector<std::string> courseNames(numCourses); // To store names of courses (optional, but good for display)
    std::vector<char> grades(numCourses);           // To store letter grades for each course
    std::vector<int> creditHours(numCourses);       // To store credit hours for each course

    double totalGradePoints = 0.0; // Accumulator for total grade points
    int totalCreditHours = 0;      // Accumulator for total credit hours

    // Loop through each course to get input for grade and credit hours
    for (int i = 0; i < numCourses; ++i) {
        std::cout << "\n--- Course " << (i + 1) << " ---" << std::endl;

        // Prompt and read course name (optional)
        std::cout << "Enter name for Course " << (i + 1) << " (e.g., 'Calculus'): ";
        std::cin.ignore(); // Clear the buffer before reading string input after a number
        std::getline(std::cin, courseNames[i]); // Read the entire line for course name

        // Prompt and read letter grade for the current course
        std::cout << "Enter grade (A, B, C, D, F) for " << courseNames[i] << ": ";
        std::cin >> grades[i];

        // Input validation for grade
        char upperGrade = toupper(grades[i]); // Convert to uppercase for validation
        while (upperGrade != 'A' && upperGrade != 'B' && upperGrade != 'C' && upperGrade != 'D' && upperGrade != 'F') {
            std::cout << "Invalid grade. Please enter A, B, C, D, or F: ";
            std::cin >> grades[i];
            upperGrade = toupper(grades[i]);
        }

        // Prompt and read credit hours for the current course
        std::cout << "Enter credit hours for " << courseNames[i] << ": ";
        std::cin >> creditHours[i];

        // Input validation: Ensure credit hours are positive
        while (creditHours[i] <= 0) {
            std::cout << "Credit hours must be positive. Please re-enter: ";
            std::cin >> creditHours[i];
        }

        // Calculate grade points for the current course and add to total
        double currentCourseGradePoints = getGradePoints(grades[i]);
        totalGradePoints += (currentCourseGradePoints * creditHours[i]);

        // Add current course's credit hours to total
        totalCreditHours += creditHours[i];
    }

    // Display individual course grades
    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "        Individual Course Summary         " << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < numCourses; ++i) {
        std::cout << "Course: " << courseNames[i]
            << ", Grade: " << (char)toupper(grades[i]) // Display grade in uppercase
            << ", Credit Hours: " << creditHours[i] << std::endl;
    }

    // Calculate CGPA
    double cgpa = 0.0;
    if (totalCreditHours > 0) { // Avoid division by zero
        cgpa = totalGradePoints / totalCreditHours;
    }

    // Display the final CGPA
    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "        CGPA Calculation Result           " << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Total Grade Points: " << totalGradePoints << std::endl;
    std::cout << "Total Credit Hours: " << totalCreditHours << std::endl;
    std::cout << "Your calculated CGPA is: " << cgpa << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    return 0; // Indicate successful program execution
}