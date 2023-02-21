#include <iostream>
using namespace std;

class Student
{
private:
    string studentName;
    string specialization;
    int id;
   
public:
    Student() : studentName(""), id(0), specialization("Comp") {}
    Student(string studentName, string specialization, int id)
    {
        this->studentName = studentName;
        this->specialization = specialization;
        this->id = id;
    }
    friend istream& operator>>(istream& is, Student& student)
    {
        is >> student.studentName;
        is >> student.specialization;
        is >> student.id;
        return is;
    }
    friend ostream& operator<<(ostream& os, Student& student)
    {
        os << "Student name: " << student.studentName << " Student specialization: " << student.specialization << " Student Id: " << student.id<<endl;
        return os;
    }
    bool operator==(const Student& student)
    {
        return (this->studentName == student.studentName && this->id == student.id && this->specialization == student.specialization);
    }
    string getSpec()
    {
        return specialization;
    }

};

class Course
{
private:
    string courseName;
    int numberOfCourse;
    string spec;
public:
    Course() :courseName(""), numberOfCourse(0), spec("") {}
    Course(string courseName, int numberOfCourse, int spec)
    {
        this->courseName = courseName;
        this->numberOfCourse = numberOfCourse;
        this->spec = spec;
    }
    friend istream& operator>>(istream& is, Course &course)
    {
        is >> course.courseName;
        is >> course.numberOfCourse;
        is >> course.spec;
        return is;
    }
    friend ostream& operator<<(ostream& os, Course& course)
    {
        os << "Course Name: " << course.courseName << " Number of Course: " << course.numberOfCourse << " Specialization: " << course.spec<<endl;
        return os;
    }
    bool operator==(const Course course)
    {
        return (this->courseName == course.courseName && this->numberOfCourse == course.numberOfCourse && this->spec == course.spec);
    }
    string getSpec()
    {
        return spec;
    }
};
class University
{
private:
    string universityName;
    string location;
    Student *students;
    Course *courses;
    int studentsCur;
    int coursesCur;
public:
    University() :studentsCur(0), coursesCur(0), universityName(""), location("") { students = new Student[3], courses = new Course[3]; }
    University(string uniName, string loc, Student *students, Course *courses) :studentsCur(0), coursesCur(0)
    {
        this->universityName = uniName;
        this->location = loc;
        this->students = students;
        this->courses = courses;
    }
    /*friend ostream& operator<<(ostream& os, University& Uni)
    {
        os << "University name: " << Uni.universityName << " Location: " << Uni.location << " Students: " << Uni.students;
    }*/

    friend istream& operator>>(istream& is, University& Uni)
    {
        cout << "Here"<<endl;
        is >> Uni.universityName;
        is >> Uni.location;  
        return is;
    }
    void AddStudent(Student student)
    {
        students[studentsCur] = student;
        studentsCur++;
    }
    void AddCourse(Course course)
    {
        
        courses[coursesCur] = course; 
        coursesCur++;
    }
    void RemoveStudent(Student student)
    {
        
        studentsCur--;
        for (int i = 0; students[i] == student; i++)
        {
            for (int j = 0; j < studentsCur; j++)
            {
                students[j] = students[j + 1];
            }
        }
        
    }
    void RemoveCourse(Course course)
    {
        coursesCur--;
        for (int i = 0; courses[i] == course; i++)
        {
            for (int i = 0; i < coursesCur; i++)
            {
                students[i] = students[i + 1];
            }
        }
        
    }
    void showListOfStudentsByCourse(Course course)
    {
        
        for (int i = 0; i < coursesCur; i++)
        {
            if (students[i].getSpec() == course.getSpec())
            {
                cout<< students[i];
            }
        }
        
    }
    void showListOfCoursesByStudent(Student student)
    {
        for (int i = 0; i < coursesCur; i++)
        {
            if (courses[i].getSpec()==student.getSpec())
            {
                cout << courses[i];
            }
        }
    }

    void showAllCourses()
    {
        for (int i = 0; i < coursesCur; i++)
        {
            cout << courses[i];
        }
    }
    void showAllStudents()
    {
        for (int i = 0; i < studentsCur; i++)
        {
            cout<< students[i];
            
        }
    }

};

int main()
{
    University Uni;
    cin >> Uni;
    Student* studentsToAdd;
    Student* studentsToRemove;
    Course* coursesToAdd;
    Course* coursesToRemove;
    cout << "Enter operation: " << endl;
    cout << "1. Add Student  2. Remove student" << endl;
    int switcher;
    cin >> switcher;
    switch (switcher)
    {
    case 1:
        cout << "Enter amount of students to add: ";
        int x;
        cin >> x;
         studentsToAdd = new Student[x];
        for (int i = 0; i < x; i++)
        {
            cin >> studentsToAdd[i];
            Uni.AddStudent(studentsToAdd[i]);
        }
        break;
    case 2:
        cout << "Enter amout students to remove: " << endl;
        int y;
        cin >> y;
         studentsToRemove = new Student[y];
        for (int i = 0; i < y; i++)
        {
            cin >> studentsToRemove[i];
            Uni.RemoveStudent(studentsToRemove[i]);
        }
    }

    cout << "Enter operation" << endl;
    cout << "1. Add Courses  2. Remove courses" << endl;
    int switcher1;
    cin >> switcher1;
    switch (switcher1)
    {
    case 1:
        cout << "Enter amount of courses to add: ";
        int x;
        cin >> x;
        coursesToAdd = new Course[x];
        for (int i = 0; i < x; i++)
        {
            cin >> coursesToAdd[i];
            Uni.AddCourse(coursesToAdd[i]);
        }
        break;
    case 2:
        cout << "Enter amout of courses to remove: " << endl;
        int y;
        cin >> y;
        coursesToRemove = new Course[y];
        for (int i = 0; i < y; i++)
        {
            cin >> coursesToRemove[i];
            Uni.RemoveCourse(coursesToRemove[i]);
        }
    }


    cout << "Enter operation: " << endl;
    cout << "1. Add Student  2. Remove student" << endl;
    int switcher2;
    cin >> switcher2;
    switch (switcher2)
    {
    case 1:
        cout << "Enter amount of students to add: ";
        int x;
        cin >> x;
        studentsToAdd = new Student[x];
        for (int i = 0; i < x; i++)
        {
            cin >> studentsToAdd[i];
            Uni.AddStudent(studentsToAdd[i]);
        }
        break;
    case 2:
        cout << "Enter amout students to remove: " << endl;
        int y;
        cin >> y;
        studentsToRemove = new Student[y];
        for (int i = 0; i < y; i++)
        {
            cin >> studentsToRemove[i];
            Uni.RemoveStudent(studentsToRemove[i]);
        }
    }

    cout << "Enter operation" << endl;
    cout << "1. Add Courses  2. Remove courses" << endl;
    int switcher3;
    cin >> switcher3;
    switch (switcher3)
    {
    case 1:
        cout << "Enter amount of courses to add: ";
        int x;
        cin >> x;
        coursesToAdd = new Course[x];
        for (int i = 0; i < x; i++)
        {
            cin >> coursesToAdd[i];
            Uni.AddCourse(coursesToAdd[i]);
        }
        break;
    case 2:
        cout << "Enter amout of courses to remove: " << endl;
        int y;
        cin >> y;
        coursesToRemove = new Course[y];
        for (int i = 0; i < y; i++)
        {
            cin >> coursesToRemove[i];
            Uni.RemoveCourse(coursesToRemove[i]);
        }
    }

    cout << "Enter course to find student: ";
    Course courseToFind;
    cin >> courseToFind;
    Uni.showListOfStudentsByCourse(courseToFind);


    cout << "Enter student to find his courses: ";
    Student std;
    cin >> std;
    Uni.showListOfCoursesByStudent(std);

    Uni.showAllCourses();
    Uni.showAllStudents();
}


