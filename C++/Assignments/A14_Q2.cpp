#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

// Menu driven

struct Student
{
    string name;
    map<string, int> marks;
};

void searchStudent(const vector<Student> &students)
{
    string searchName;

    cout << "Enter student name : ";
    cin >> searchName;

    bool found = false;

    for (const auto &student : students)
    {
        if (student.name == searchName)
        {
            cout << "\nStudent Found\n";
            cout << "Name: " << student.name << endl;

            for (const auto &subject : student.marks)
            {
                cout << subject.first
                     << " : "
                     << subject.second
                     << endl;
            }

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }
}

void specificSubjectTopper(const vector<Student> &students)
{
    string subject;

    cout << "Enter subject : ";
    cin >> subject;

    map<string, pair<string, int>> toppers;

    for (const auto &student : students)
    {
        for (const auto &subjectMark : student.marks)
        {
            string subjectName = subjectMark.first;
            int marks = subjectMark.second;

            if (toppers.find(subjectName) == toppers.end())
            {
                toppers[subjectName] =
                    {student.name, marks};
            }
            else if (marks > toppers[subjectName].second)
            {
                toppers[subjectName] =
                    {student.name, marks};
            }
        }
    }

    bool flag = false;

    for (const auto &topper : toppers)
    {
        if (topper.first == subject)
        {
            cout << "Topper : "
                 << topper.second.first << endl;

            cout << "Marks : "
                 << topper.second.second << endl;

            flag = true;
        }
    }

    if (!flag)
    {
        cout << "Subject not found : "
             << subject << endl;
    }
}

void studentAverage(const vector<Student> &students)
{
    for (const auto &student : students)
    {
        int total = 0;

        for (const auto &subject : student.marks)
        {
            total += subject.second;
        }

        double average =
            (double)total / student.marks.size();

        cout << "\nStudent : "
             << student.name << endl;

        for (const auto &subject : student.marks)
        {
            cout << subject.first
                 << " : "
                 << subject.second
                 << endl;
        }

        cout << "Average : "
             << fixed << setprecision(2)
             << average << endl;
    }
}

void displayAllStudent(const vector<Student> &students)
{
    for (const auto &student : students)
    {
        cout << "\nName : "
             << student.name << endl;

        for (const auto &subject : student.marks)
        {
            cout << "Subject : "
                 << subject.first << endl;

            cout << "Marks : "
                 << subject.second << endl;
        }
    }
}

void subjectTopper(const vector<Student> &students)
{
    map<string, pair<string, int>> toppers;

    for (const auto &student : students)
    {
        for (const auto &subject : student.marks)
        {
            string subjectName = subject.first;
            int marks = subject.second;

            if (toppers.find(subjectName) == toppers.end())
            {
                toppers[subjectName] =
                    {student.name, marks};
            }
            else if (marks > toppers[subjectName].second)
            {
                toppers[subjectName] =
                    {student.name, marks};
            }
        }
    }

    cout << "\n\n========== Subject Topper ==========\n";

    for (const auto &topper : toppers)
    {
        cout << "\nSubject : "
             << topper.first << endl;

        cout << "Topper : "
             << topper.second.first << endl;

        cout << "Marks : "
             << topper.second.second << endl;
    }
}

vector<Student> fileRead(ifstream &file)
{
    vector<Student> students;
    string line;

    while (getline(file, line))
    {
        string name;
        string subject;
        int mark;

        stringstream ss(line);

        getline(ss, name, '\t');
        getline(ss, subject, '\t');
        ss >> mark;

        bool found = false;

        for (auto &student : students)
        {
            if (student.name == name)
            {
                student.marks[subject] = mark;
                found = true;
                break;
            }
        }

        if (!found)
        {
            Student student;

            student.name = name;
            student.marks[subject] = mark;

            students.push_back(student);
        }
    }

    file.close();

    return students;
}

int menu()
{
    cout << "========== STUDENT RESULT SYSTEM =========="
         << endl;

    cout << "0. Exit" << endl
         << "1. Display All Students" << endl
         << "2. Search Student" << endl
         << "3. Display Student Average" << endl
         << "4. Find Subject Topper" << endl
         << "5. Subject Topper" << endl;

    int choice;

    cout << "Enter Choice : ";
    cin >> choice;

    return choice;
}

int main(void)
{
    ifstream file("students.txt");

    if (!file)
    {
        cout << "Error: Could not open students.txt"
             << endl;

        return 0;
    }

    vector<Student> students = fileRead(file);

    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            displayAllStudent(students);
            break;

        case 2:
            searchStudent(students);
            break;

        case 3:
            studentAverage(students);
            break;

        case 4:
            specificSubjectTopper(students);
            break;

        case 5:
            subjectTopper(students);
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}