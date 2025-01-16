#include <iostream>
#include <string>
#include <vector>
#include <numeric> // For std::accumulate
using namespace std;

// Employee class with encapsulation and constructor initialization
class Employee {
private:
    string name;
    int age;
    double salary;

public:
    Employee(const string& n, int a, double s) : name(n), age(a), salary(s) {}

    // Getters for encapsulated data
    string getName() const { return name; }
    int getAge() const { return age; }
    double getSalary() const { return salary; }

    void printDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", Salary: " << salary << endl;
    }

    bool isEligibleForPromotion() const {
        return age > 35;
    }
};

int main() {
    vector<Employee> employees = {
        {"Alice", 30, 50000},
        {"Bob", 40, 60000},
        {"Charlie", 35, 70000}
    };

    // Print details of each employee
    for (const auto& employee : employees) {
        employee.printDetails();
        if (employee.isEligibleForPromotion()) {
            cout << employee.getName() << " is eligible for a promotion." << endl;
        }
    }

    // Calculate total salary
    double totalSalary = accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const Employee& emp) {
        return sum + emp.getSalary();
    });

    cout << "Total Salary: " << totalSalary << endl;

    return 0;
}
