#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

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

void subjectTopper(vector<Student> students)
{
    string subject;
    cout << "Enter subect : ";
    cin >> subject;
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
     bool flag = false;
    for(const auto &topper: toppers)
    {
       if(topper.first == subject)
       {
        
        cout << "Topper : " << topper.second.first << endl;
        cout << "Marks : " << topper.second.second << endl;
        flag = true;
       }
    }
    if(!flag)
    {
        cout << "Subject not found : " << subject << endl; 
    }
}

int main(void)
{
    ifstream file("students.txt");

    if (!file)
    {
        cout << "Error: Could not open students.txt" << endl;
        return 1;
    }

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

    cout << "\n========== STUDENT RESULTS ==========\n";

    for (const auto &student : students)
    {
        int total = 0;

        for (const auto &subject : student.marks)
        {
            total += subject.second;
        }

        double average = (double)total / student.marks.size();
        cout << "\nStudent : " << student.name << endl;
        for (const auto &subject : student.marks)
        {
            cout << subject.first << " : "
                 << subject.second << endl;
        }

        cout << "Average : "
             << fixed << setprecision(2)
             << average << endl;
    }

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
        cout << "\nSubject : " << topper.first << endl;
        cout << "\nTopper : " << topper.second.first << endl;
        cout << "\nMarks : " << topper.second.second << endl;
    }

    cout << "\n\n========== Search Student ==========\n";
    searchStudent(students);

    cout << "\n\n========== Specific Subject Topper ==========\n";
    subjectTopper(students);

    

    return 0;
}