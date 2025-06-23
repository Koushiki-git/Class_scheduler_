#include <bits/stdc++.h>
#include "samplegen.cpp"
#include "montecarlo.cpp"
#include "ansimul.cpp"

using namespace std;

int main() {
    int total_course =4 ;
    int total_time =3; // as the row_max
    int total_classroom =3;// as the col_max
    int total_teacher =3;

    //cout<<"Enter total number of Courses :";cin>>total_course;
    //cout<<"Enter total number of Classrooms :";cin>>total_classroom;
    //cout<<"Enter total time available :";cin>>total_time;
    //cout<<"Enter total teachers available :";cin>>total_teacher;
    
    
    int cost = 0; //Cost of clashes in the classes

    
    map<int, map<int, int> > classTable;  
    vector<vector<int> > schedule;           
    vector<vector<int> > schedule2;      
    
    vector<int> course_teacher;           
    vector<int> temp(total_teacher,0);
    for(int i = 0; i<total_time;++i){
        schedule.push_back(temp);
        schedule2.push_back(temp);
    }
    
   
    for(int i = 0; i<total_teacher; ++i){
    course_teacher.push_back(i);
    }
    course_teacher.push_back(0);
    
    cout<<"Start: randomly generated "<<endl;
    cost = first(classTable, schedule, schedule2, course_teacher, total_time, total_classroom,total_course);
    cout<<"total cost is: "<<cost<<endl;
    cout<<"The location and time of given courses are: "<<endl;
    for(int i = 0; i<total_course; ++i){
        cout<<"Course : "<<i<<" "<<"Location : "<<" "<<classTable[i].begin()->first<<"  Time Alloted : "<<classTable[i].begin()->second<<endl;
        
    }


    //part 2
    cout<<endl<<endl;
    cout<<"Testing part 2(Monte carlo): "<<endl;
    cost = MonteCarlo(classTable, schedule, schedule2, course_teacher, cost,total_time, total_classroom);
    cout<<"Cost after montecarlo is: "<<cost<<endl<<endl;
    cout<<"The location and time of given courses are after MonteCarlo: "<<endl;
    for(int i = 0; i<total_course; ++i){
        cout<<"Course : "<<i<<" "<<"Location : "<<" "<<classTable[i].begin()->first<<"  Time Alloted : "<<classTable[i].begin()->second<<endl;
        
    }
    //part 3
    cout<<endl<<endl;
    cout<<"Testing part 3(annealing simulated): "<<endl;
    cost = third(classTable, schedule, schedule2, course_teacher, cost);
    cout<<"cost after annealing simulated is: "<<cost<<endl;
    return 0;
}
