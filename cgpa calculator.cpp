#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of subjects: ";
    cin >> n;

    double gradePoint, creditHours;
    double totalPoints = 0.0, totalCredits = 0.0;

    for (int i = 1; i <= n; i++) {
        cout << "Enter grade point for subject " << i << ": ";
        cin >> gradePoint;

        cout << "Enter credit hours for subject " << i << ": ";
        cin >> creditHours;

        totalPoints += gradePoint * creditHours;
        totalCredits += creditHours;
    }

    if (totalCredits == 0) {
        cout << "Total credits cannot be zero." << endl;
        return 0;
    }

    double cgpa = totalPoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}
