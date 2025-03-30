#include<iostream>
#include<vector>
using namespace std;
class subject
{
    public:
    string subjectname;
    int credit ;
    float gradepoint;
    // constructor
    subject(string name, int cr, float gp)
    {
        subjectname = name;
        credit = cr;
        gradepoint = gp;

    }

};

class student 
{
    public:
    string name ;
    vector<subject>subjects;
    // constructor 
    student( string studentName )
    {
        name = studentName;

    }
    void addsubject(string subjectName, int credit, float gradepoint)
    {
        subject newSubject(subjectName, credit, gradepoint);
        subjects.push_back(newSubject);
    }

    float calculatecgpa()
    {
        int totalcredit = 0;
        float weightgradepoint = 0;
        for( const subject &sub:subjects){
            totalcredit += sub.credit;
            weightgradepoint += sub.credit*sub.gradepoint;
        }
        return(totalcredit>0)?(weightgradepoint/totalcredit):0 ;

    }
    void displaycgpa(){
        cout<<"Student name:"<<name<<endl;
        float cgpa = calculatecgpa();
        cout<<"CGPA:"<<cgpa<<endl;

    }
    
};


int main()
{
    string studentname;
    int numsub ;
    cout<<"Enter student's name: ";
    getline(cin, studentname);
    cout<<"Enter the number of subjects:";
    cin>>numsub;
    cin.ignore();
    student stud(studentname);
    for(int i=0; i<numsub; i++)
    {
        string subjectname;
        int credit;
        float gradepoint;
        cout<<"Enter the subject's name:";
        //cin.ignore();
        getline(cin , subjectname);
        cout<<"Enter the credit:";
        cin>>credit;
        cout<<"Enter the gradepoint:";
        cin>>gradepoint;
        cin.ignore();
        stud.addsubject(subjectname, credit, gradepoint);
    }
    stud.displaycgpa();
    return 0;
}