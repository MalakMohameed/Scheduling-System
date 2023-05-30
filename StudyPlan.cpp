#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
// Course class to store information about a single course
class Course {
public:
    string Code;
    string Prerequisite;
    string Name;
    int Credit_hours;
    int Lecture_contact_hours;
    int Lab_tutorial_contact_hours;

    //Constructor
    Course(string code, string prerequisite, string name, int credit_hours, int lecture_contact_hours, int lab_tutorial_contact_hours) {
        this->Code = code;
        this->Prerequisite = prerequisite;
        this->Name = name;
        this->Credit_hours = credit_hours;
        this->Lecture_contact_hours = lecture_contact_hours;
        this->Lab_tutorial_contact_hours = lab_tutorial_contact_hours;
    }
};

// StudyPlan class to store the courses for a particular study plan
class StudyPlan {
public:
    vector<Course> first_semester_courses;
    vector<Course> second_semester_courses;

    StudyPlan() {}

    void add_first_semester_course(Course course) {
        first_semester_courses.push_back(course);
    }

    void add_second_semester_course(Course course) {
        second_semester_courses.push_back(course);
    }

    int total_credit_hours_first_semester() {
        int sum = 0;
        for (const auto& course : first_semester_courses) {
            sum += course.Credit_hours;
        }
        return sum;
    }

    int total_credit_hours_second_semester() {
        int sum = 0;
        for (const auto& course : second_semester_courses) {
            sum += course.Credit_hours;
        }
        return sum;
    }

};

int main()
{
    // Create a study plan for the first level
    StudyPlan first_level_study_plan;

    // Add first semester courses to the study plan          code, prerequisite, name, credit hours, lec hours, lab hours
    first_level_study_plan.add_first_semester_course(Course("BAS121", "", "Physics", 4, 3, 2));
    first_level_study_plan.add_first_semester_course(Course("BAS111", "", "Mathematics", 3, 3, 2));
    first_level_study_plan.add_first_semester_course(Course("SWE110", "", "Introduction to Computer Science & Programming", 4, 3, 2));
    first_level_study_plan.add_first_semester_course(Course("", "", "University Req. (1)", 3, 3, 0));
    first_level_study_plan.add_first_semester_course(Course("", "", "University Req. (2)", 3, 3, 0));

    // Add second semester courses to the study plan
    first_level_study_plan.add_second_semester_course(Course("BAS131", "", "Probability & Statistics", 3, 3, 2));
    first_level_study_plan.add_second_semester_course(Course("BAS112", "BAS111", "Discrete Mathematics & linear algebra", 3, 3, 2));
    first_level_study_plan.add_second_semester_course(Course("CSC120", "BAS121", "Digital Logic Design", 3, 2, 2));
    first_level_study_plan.add_second_semester_course(Course("SWE111", "SWE110", "Computer Programming & Problem Solving", 4, 3, 2));
    first_level_study_plan.add_second_semester_course(Course("", "", "University Req (3)", 3, 3, 0));

    //// Print the courses in the first level study plan
    //cout << "First Level Study Plan:" << endl;
    //cout << "First Semester Courses:" << endl;
    //for (const auto& course : first_level_study_plan.first_semester_courses) {
    //    //auto is auto detection
    //    //this const is about the object the reference refers to.This means the iterator cannot modify the data, can only 'read'
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the first semester
    //cout << "Total credit hours for this semester: " << first_level_study_plan.total_credit_hours_first_semester() << endl;


    //cout << "Second Semester Courses:" << endl;
    //for (const auto& course : first_level_study_plan.second_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the second semester
    //cout << "Total credit hours for this semester: " << first_level_study_plan.total_credit_hours_second_semester() << endl;





    // Open the output file
    ofstream output_file("study_plan.txt");

    // Write the courses in the first level study plan to the file
    output_file << "First Level Study Plan:" << endl;
    output_file << "First Semester Courses:" << endl;
    for (const auto& course : first_level_study_plan.first_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the first semester
    output_file << "Total credit hours for this semester: " << first_level_study_plan.total_credit_hours_first_semester() << endl << endl;


    output_file << "Second Semester Courses:" << endl;
    for (const auto& course : first_level_study_plan.second_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the second semester
    output_file << "Total credit hours for this semester: " << first_level_study_plan.total_credit_hours_second_semester() << endl << endl << endl;

    // Close the output file
    output_file.close();

    // Print a message to the console indicating that the file has been written
    cout << "Output has been written to study_plan.txt" << endl;











    // Create a study plan for the second level
    StudyPlan second_level_study_plan;

    // Add first semester courses to the study plan         code, prerequisite, name, credit hours, lec hours, lab hours
    second_level_study_plan.add_first_semester_course(Course("SWE210", "SWE111", "Data Structures & Algorithms", 4, 3, 2));
    second_level_study_plan.add_first_semester_course(Course("INF230", "SWE110", "Database Management Systems", 4, 3, 2));
    second_level_study_plan.add_first_semester_course(Course("SWE211", "SWE111", "Object Oriented Programming", 4, 3, 2));
    second_level_study_plan.add_first_semester_course(Course("CSC220", "CSC120", "Computer Organization", 3, 2, 2));
    second_level_study_plan.add_first_semester_course(Course("", "", "University Req. (4)", 3, 3, 0));

    // Add second semester courses to the study plan
    second_level_study_plan.add_second_semester_course(Course("SWE212", "SWE210", "Algorithms Analysis & Design", 4, 3, 2));
    second_level_study_plan.add_second_semester_course(Course("CSC210", "", "Operating Systems", 3, 2, 2));
    second_level_study_plan.add_second_semester_course(Course("CSC230", "", "Computer Networks", 4, 3, 2));
    second_level_study_plan.add_second_semester_course(Course("SWE230", "INF230,SWE211", "Web Development", 4, 3, 2));
    second_level_study_plan.add_second_semester_course(Course("", "", "University Req. (5)", 3, 3, 0));

    //// Print the courses in the second level study plan
    //cout << endl << "Second Level Study Plan:" << endl;
    //cout << "First Semester Courses:" << endl;
    //for (const auto& course : second_level_study_plan.first_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the first semester
    //cout << "Total credit hours for this semester: " << second_level_study_plan.total_credit_hours_first_semester() << endl;


    //cout << "Second Semester Courses:" << endl;
    //for (const auto& course : second_level_study_plan.second_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the second semester
    //cout << "Total credit hours for this semester: " << second_level_study_plan.total_credit_hours_second_semester() << endl;






    // Open the output file
    output_file.open("study_plan.txt", ios::app);

    // Write the courses in the first level study plan to the file
    output_file << "Second Level Study Plan:" << endl;
    output_file << "First Semester Courses:" << endl;
    for (const auto& course : second_level_study_plan.first_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the first semester
    output_file << "Total credit hours for this semester: " << second_level_study_plan.total_credit_hours_first_semester() << endl << endl;


    output_file << "Second Semester Courses:" << endl;
    for (const auto& course : second_level_study_plan.second_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the second semester
    output_file << "Total credit hours for this semester: " << second_level_study_plan.total_credit_hours_second_semester() << endl << endl << endl;

    // Close the output file
    output_file.close();

    // Print a message to the console indicating that the file has been written
    cout << "Output has been written to study_plan.txt" << endl;








    // Create a study plan for the third level, department of computer science
    StudyPlan third_level_CS_study_plan;

    // Add first semester courses to the study plan         code, prerequisite, name, credit hours, lec hours, lab hours
    third_level_CS_study_plan.add_first_semester_course(Course("CSC340", "SWE111", "Artificial Intelligence", 3, 2, 2));
    third_level_CS_study_plan.add_first_semester_course(Course("BAS331", "BAS131", "Statistical Analysis", 3, 2, 2));
    third_level_CS_study_plan.add_first_semester_course(Course("CSC360", "SWE111, BAS112", "Image Processing", 4, 3, 2));
    third_level_CS_study_plan.add_first_semester_course(Course("SWE320", "SWE211", "Software Engineering", 4, 3, 2));
    third_level_CS_study_plan.add_first_semester_course(Course("", "", "University Req. (6)", 3, 3, 0));


    // Add second semester courses to the study plan 
    third_level_CS_study_plan.add_second_semester_course(Course("SWE321", "", "Software Project Management", 3, 2, 2));
    third_level_CS_study_plan.add_second_semester_course(Course("CSC341", "CSC340", "Machine Learning", 3, 2, 2));
    third_level_CS_study_plan.add_second_semester_course(Course("CSC311", "BAS112,SWE210", "Theory of Computation & Compiler Design", 4, 3, 2));
    third_level_CS_study_plan.add_second_semester_course(Course("", "", "Minor Elective 1", 3, 2, 2));
    third_level_CS_study_plan.add_second_semester_course(Course("", "", "Minor Elective 2", 3, 2, 2));


    //// Print the courses in the third level CS study plan
    //cout << endl << "Third Level CS Study Plan:" << endl;
    //cout << "First Semester Courses:" << endl;
    //for (const auto& course : third_level_CS_study_plan.first_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the first semester
    //cout << "Total credit hours for this semester: " << third_level_CS_study_plan.total_credit_hours_first_semester() << endl;


    //cout << "Second Semester Courses:" << endl;
    //for (const auto& course : third_level_CS_study_plan.second_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the second semester
    //cout << "Total credit hours for this semester: " << third_level_CS_study_plan.total_credit_hours_second_semester() << endl;




    // Open the output file
    output_file.open("study_plan.txt", ios::app);

    // Write the courses in the first level study plan to the file
    output_file << "Third Level CS Study Plan:" << endl;
    output_file << "First Semester Courses:" << endl;
    for (const auto& course : third_level_CS_study_plan.first_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the first semester
    output_file << "Total credit hours for this semester: " << third_level_CS_study_plan.total_credit_hours_first_semester() << endl << endl;


    output_file << "Second Semester Courses:" << endl;
    for (const auto& course : third_level_CS_study_plan.second_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the second semester
    output_file << "Total credit hours for this semester: " << third_level_CS_study_plan.total_credit_hours_second_semester() << endl << endl << endl;

    // Close the output file
    output_file.close();

    // Print a message to the console indicating that the file has been written
    cout << "Output has been written to study_plan.txt" << endl;








    // Create a study plan for the fourth level, department of computer science
    StudyPlan fourth_level_CS_study_plan;

    // Add first semester courses to the study plan         code, prerequisite, name, credit hours, lec hours, lab hours
    fourth_level_CS_study_plan.add_first_semester_course(Course("CSC430", "CSC230", "Network Security", 3, 2, 2));
    fourth_level_CS_study_plan.add_first_semester_course(Course("CSC410", "CSC210", "Distributed Systems", 4, 3, 2));
    fourth_level_CS_study_plan.add_first_semester_course(Course("", "", "Minor elective 3", 3, 2, 2));
    fourth_level_CS_study_plan.add_first_semester_course(Course("", "", "Minor elective 4", 3, 2, 2));
    fourth_level_CS_study_plan.add_first_semester_course(Course("CSC491A", "SWE320", "Senior Project in Computer Science", 0, 2, 0));


    // Add second semester courses to the study plan 
    fourth_level_CS_study_plan.add_second_semester_course(Course("SWE410", "SWE211", "Mobile device Programming", 3, 2, 2));
    fourth_level_CS_study_plan.add_second_semester_course(Course("", "", "Minor elective 5", 3, 2, 2));
    fourth_level_CS_study_plan.add_second_semester_course(Course("", "", "Minor elective 6", 3, 2, 2));
    fourth_level_CS_study_plan.add_second_semester_course(Course("", "", "Minor elective 7", 3, 2, 2));
    fourth_level_CS_study_plan.add_second_semester_course(Course("CSC491", "CSC491A", "Senior Project in Computer Science", 5, 4, 2));


    //// Print the courses in the fourth level CS study plan
    //cout << endl << "Fourth Level CS Study Plan:" << endl;
    //cout << "First Semester Courses:" << endl;
    //for (const auto& course : fourth_level_CS_study_plan.first_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the first semester
    //cout << "Total credit hours for this semester: " << fourth_level_CS_study_plan.total_credit_hours_first_semester() << endl;


    //cout << "Second Semester Courses:" << endl;
    //for (const auto& course : fourth_level_CS_study_plan.second_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the second semester
    //cout << "Total credit hours for this semester: " << fourth_level_CS_study_plan.total_credit_hours_second_semester() << endl;




    // Open the output file
    output_file.open("study_plan.txt", ios::app);

    // Write the courses in the first level study plan to the file
    output_file << "Fourth Level CS Study Plan:" << endl;
    output_file << "First Semester Courses:" << endl;
    for (const auto& course : fourth_level_CS_study_plan.first_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the first semester
    output_file << "Total credit hours for this semester: " << fourth_level_CS_study_plan.total_credit_hours_first_semester() << endl << endl;


    output_file << "Second Semester Courses:" << endl;
    for (const auto& course : fourth_level_CS_study_plan.second_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the second semester
    output_file << "Total credit hours for this semester: " << fourth_level_CS_study_plan.total_credit_hours_second_semester() << endl << endl << endl;

    // Close the output file
    output_file.close();

    // Print a message to the console indicating that the file has been written
    cout << "Output has been written to study_plan.txt" << endl;





    // Create a study plan for the fourth level, department of Information Science
    StudyPlan thrird_level_IS_study_plan;

    // Add first semester courses to the study plan         code, prerequisite, name, credit hours, lec hours, lab hours
    thrird_level_IS_study_plan.add_first_semester_course(Course("INF311", "INF230", "Management Information Systems", 4, 3, 2));
    thrird_level_IS_study_plan.add_first_semester_course(Course("INF312", "", "Foundation of Management", 3, 2, 2));
    thrird_level_IS_study_plan.add_first_semester_course(Course("INF313", "", "Fundamentals of Economics", 3, 2, 2));
    thrird_level_IS_study_plan.add_first_semester_course(Course("SWE320", "SWE211", "Software Engineering", 4, 3, 2));
    thrird_level_IS_study_plan.add_first_semester_course(Course("", "", "University Req (6)", 3, 3, 0));


    // Add second semester courses to the study plan 
    thrird_level_IS_study_plan.add_second_semester_course(Course("INF330", "INF311", "IT Infrastructure and Enterprise Needs", 4, 3, 2));
    thrird_level_IS_study_plan.add_second_semester_course(Course("INF319", "INF230", "Systems Analysis & Design", 4, 3, 2));
    thrird_level_IS_study_plan.add_second_semester_course(Course("SWE321", "", "Software Project Management", 3, 2, 2));
    thrird_level_IS_study_plan.add_second_semester_course(Course("", "", "Minor elective 1", 3, 2, 2));
    thrird_level_IS_study_plan.add_second_semester_course(Course("", "", "Minor elective 2", 3, 2, 2));


    //// Print the courses in the third level IS study plan
    //cout << endl << "Third Level IS Study Plan:" << endl;
    //cout << "First Semester Courses:" << endl;
    //for (const auto& course : thrird_level_IS_study_plan.first_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the first semester
    //cout << "Total credit hours for this semester: " << thrird_level_IS_study_plan.total_credit_hours_first_semester() << endl;

    //cout << "Second Semester Courses:" << endl;
    //for (const auto& course : thrird_level_IS_study_plan.second_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the second semester
    //cout << "Total credit hours for this semester: " << thrird_level_IS_study_plan.total_credit_hours_second_semester() << endl;


    // Open the output file
    output_file.open("study_plan.txt", ios::app);

    // Write the courses in the first level study plan to the file
    output_file << "Third Level IS Study Plan:" << endl;
    output_file << "First Semester Courses:" << endl;
    for (const auto& course : thrird_level_IS_study_plan.first_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the first semester
    output_file << "Total credit hours for this semester: " << thrird_level_IS_study_plan.total_credit_hours_first_semester() << endl << endl;


    output_file << "Second Semester Courses:" << endl;
    for (const auto& course : thrird_level_IS_study_plan.second_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the second semester
    output_file << "Total credit hours for this semester: " << thrird_level_IS_study_plan.total_credit_hours_second_semester() << endl << endl << endl;

    // Close the output file
    output_file.close();

    // Print a message to the console indicating that the file has been written
    cout << "Output has been written to study_plan.txt" << endl;







    // Create a study plan for the fourth level, department of Information Science
    StudyPlan fourth_level_IS_study_plan;

    // Add first semester courses to the study plan         code, prerequisite, name, credit hours, lec hours, lab hours
    fourth_level_IS_study_plan.add_first_semester_course(Course("INF410", "INF313", "Electronic Commerce", 3, 2, 2));
    fourth_level_IS_study_plan.add_first_semester_course(Course("INF420", "CSC230", "IT Security", 3, 2, 2));
    fourth_level_IS_study_plan.add_first_semester_course(Course("", "", "Minor elective 3", 3, 2, 2));
    fourth_level_IS_study_plan.add_first_semester_course(Course("", "", "Minor elective 4", 3, 2, 2));
    fourth_level_IS_study_plan.add_first_semester_course(Course("INF491A", "SWE320", "Senior Project in data & Information Sciences", 0, 2, 0));


    // Add second semester courses to the study plan 
    fourth_level_IS_study_plan.add_second_semester_course(Course("INF430", "INF311", "Information Storage and Retrieval", 3, 2, 2));
    fourth_level_IS_study_plan.add_second_semester_course(Course("", "", "Minor elective 5", 3, 2, 2));
    fourth_level_IS_study_plan.add_second_semester_course(Course("", "", "Minor elective 6", 3, 2, 2));
    fourth_level_IS_study_plan.add_second_semester_course(Course("", "", "Minor elective 7", 3, 2, 2));
    fourth_level_IS_study_plan.add_second_semester_course(Course("INF491", "INF491A", "Senior Project in data & Information Sciences", 5, 4, 2));


    //// Print the courses in the fourth level IS study plan
    //cout << endl << "Fourth Level IS Study Plan:" << endl;
    //cout << "First Semester Courses:" << endl;
    //for (const auto& course : fourth_level_IS_study_plan.first_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the first semester
    //cout << "Total credit hours for this semester: " << fourth_level_IS_study_plan.total_credit_hours_first_semester() << endl;


    //cout << "Second Semester Courses:" << endl;
    //for (const auto& course : fourth_level_IS_study_plan.second_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the second semester
    //cout << "Total credit hours for this semester: " << fourth_level_IS_study_plan.total_credit_hours_second_semester() << endl;


    // Open the output file
    output_file.open("study_plan.txt", ios::app);

    // Write the courses in the first level study plan to the file
    output_file << "Fourth Level IS Study Plan:" << endl;
    output_file << "First Semester Courses:" << endl;
    for (const auto& course : fourth_level_IS_study_plan.first_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the first semester
    output_file << "Total credit hours for this semester: " << fourth_level_IS_study_plan.total_credit_hours_first_semester() << endl << endl;


    output_file << "Second Semester Courses:" << endl;
    for (const auto& course : fourth_level_IS_study_plan.second_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the second semester
    output_file << "Total credit hours for this semester: " << fourth_level_IS_study_plan.total_credit_hours_second_semester() << endl << endl << endl;

    // Close the output file
    output_file.close();








    // Create a study plan for the third level, department of Software Engineering
    StudyPlan third_level_SWE_study_plan;

    // Add first semester courses to the study plan         code, prerequisite, name, credit hours, lec hours, lab hours
    third_level_SWE_study_plan.add_first_semester_course(Course("CSC340", "SWE111", "Artificial Intelligence", 3, 2, 2));
    third_level_SWE_study_plan.add_first_semester_course(Course("BAS331", "BAS131", "Statistical Analysis", 3, 2, 2));
    third_level_SWE_study_plan.add_first_semester_course(Course("SWE330", "SWE211", "Human Computer Interaction", 3, 2, 2));
    third_level_SWE_study_plan.add_first_semester_course(Course("SWE320", "SWE211", "Software Engineering", 4, 3, 2));
    third_level_SWE_study_plan.add_first_semester_course(Course("", "", "University Req (6)", 3, 3, 0));


    // Add second semester courses to the study plan 
    third_level_SWE_study_plan.add_second_semester_course(Course("INF319", "INF230", "Information Storage and Retrieval", 4, 3, 2));
    third_level_SWE_study_plan.add_second_semester_course(Course("SWE311", "SWE210", "Minor elective 5", 3, 2, 2));
    third_level_SWE_study_plan.add_second_semester_course(Course("SWE321", "", "Minor elective 6", 3, 2, 2));
    third_level_SWE_study_plan.add_second_semester_course(Course("", "", "Minor elective 7", 3, 2, 2));
    third_level_SWE_study_plan.add_second_semester_course(Course("", "", "Senior Project in data & Information Sciences", 3, 2, 2));


    //// Print the courses in the fourth level SWE study plan
    //cout << endl << "Third Level SWE Study Plan:" << endl;
    //cout << "First Semester Courses:" << endl;
    //for (const auto& course : third_level_SWE_study_plan.first_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the first semester
    //cout << "Total credit hours for this semester: " << third_level_SWE_study_plan.total_credit_hours_first_semester() << endl;

    //cout << "Second Semester Courses:" << endl;
    //for (const auto& course : third_level_SWE_study_plan.second_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the second semester
    //cout << "Total credit hours for this semester: " << third_level_SWE_study_plan.total_credit_hours_second_semester() << endl;




    // Open the output file
    output_file.open("study_plan.txt", ios::app);

    // Write the courses in the first level study plan to the file
    output_file << "Third Level SWE Study Plan:" << endl;
    output_file << "First Semester Courses:" << endl;
    for (const auto& course : third_level_SWE_study_plan.first_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the first semester
    output_file << "Total credit hours for this semester: " << third_level_SWE_study_plan.total_credit_hours_first_semester() << endl << endl;


    output_file << "Second Semester Courses:" << endl;
    for (const auto& course : third_level_SWE_study_plan.second_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the second semester
    output_file << "Total credit hours for this semester: " << third_level_SWE_study_plan.total_credit_hours_second_semester() << endl << endl << endl;

    // Close the output file
    output_file.close();








    // Create a study plan for the fourth level, department of Software Engineering
    StudyPlan fourth_level_SWE_study_plan;

    // Add first semester courses to the study plan         code, prerequisite, name, credit hours, lec hours, lab hours
    fourth_level_SWE_study_plan.add_first_semester_course(Course("SWE411", "SWE311", "Principles of Software Architecture", 4, 3, 2));
    fourth_level_SWE_study_plan.add_first_semester_course(Course("SWE413", "SWE 320", "Software Validation and Testing", 3, 2, 2));
    fourth_level_SWE_study_plan.add_first_semester_course(Course("", "", "Minor elective 3", 3, 2, 2));
    fourth_level_SWE_study_plan.add_first_semester_course(Course("", "", "Minor elective 4", 3, 2, 2));
    fourth_level_SWE_study_plan.add_first_semester_course(Course("SWE491A", "SWE320", "Senior Project in Software Engineering", 0, 2, 0));


    // Add second semester courses to the study plan 
    fourth_level_SWE_study_plan.add_second_semester_course(Course("SWE421", "SWE320", "Information Storage and Retrieval", 4, 3, 2));
    fourth_level_SWE_study_plan.add_second_semester_course(Course("", "", "Minor elective 5", 3, 2, 2));
    fourth_level_SWE_study_plan.add_second_semester_course(Course("", "", "Minor elective 6", 3, 2, 2));
    fourth_level_SWE_study_plan.add_second_semester_course(Course("", "", "Minor elective 7", 3, 2, 2));
    fourth_level_SWE_study_plan.add_second_semester_course(Course("SWE491", "SWE491A", "Senior Project in data & Information Sciences", 5, 4, 2));


    //// Print the courses in the fourth level SWE study plan
    //cout << endl << "Fourth Level SWE Study Plan:" << endl;
    //cout << "First Semester Courses:" << endl;
    //for (const auto& course : fourth_level_SWE_study_plan.first_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the first semester
    //cout << "Total credit hours for this semester: " << fourth_level_SWE_study_plan.total_credit_hours_first_semester() << endl;

    //cout << "Second Semester Courses:" << endl;
    //for (const auto& course : fourth_level_SWE_study_plan.second_semester_courses) {
    //    cout << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
    //        << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    //}
    ////total credit hours for the second semester
    //cout << "Total credit hours for this semester: " << fourth_level_SWE_study_plan.total_credit_hours_second_semester() << endl;



    // Open the output file
    output_file.open("study_plan.txt", ios::app);

    // Write the courses in the first level study plan to the file
    output_file << "Fourth Level SWE Study Plan:" << endl;
    output_file << "First Semester Courses:" << endl;
    for (const auto& course : fourth_level_SWE_study_plan.first_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the first semester
    output_file << "Total credit hours for this semester: " << fourth_level_SWE_study_plan.total_credit_hours_first_semester() << endl << endl;


    output_file << "Second Semester Courses:" << endl;
    for (const auto& course : fourth_level_SWE_study_plan.second_semester_courses) {
        output_file << course.Code << "\t" << course.Prerequisite << "\t" << course.Name << "\t" << course.Credit_hours
            << "\t" << course.Lecture_contact_hours << "\t" << course.Lab_tutorial_contact_hours << endl;
    }
    //total credit hours for the second semester
    output_file << "Total credit hours for this semester: " << fourth_level_SWE_study_plan.total_credit_hours_second_semester() << endl << endl << endl;

    // Close the output file
    output_file.close();
}