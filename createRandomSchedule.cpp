#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iterator>
//#include <random>
#include <map>
#include <vector>

using namespace std;

// the parameter should be pass value by address
int first(map<int, map<int,int> >& classTable, vector<vector<int> >& schedule, vector<vector<int> >& schedule2, vector<int> course_inf, int row_max, int col_max,int T){
    int cost = 0;//The number of class clash
    int i = 0; //The number of current iteration
    srand((unsigned int)time(NULL));
    while(i<T){
        cout<<"****** Round "<<i+1<<" ******"<<endl<<endl;
        int crn_course = i;
        
        int index_teacher = course_inf[crn_course];// each crn_course have their own teacher numbers
        
        int row_tem = rand() % row_max;//time
        int col_tem = rand() % col_max;//location
        //debug check the random number
        cout<<"Randomly generated two numbers represent time & location for the course."<<endl;
        cout<<"Random number for time: "<<row_tem<<endl;
        cout<<"Random number for location: "<<col_tem<<endl;
        cout<<"The teacher index is: "<<course_inf[i];
        
        map<int,int> time_loc;
        time_loc.insert(pair<int, int>(row_tem, col_tem));
 
        classTable[crn_course] = time_loc;

        schedule[row_tem][col_tem]++ ; // at this time, the room gonna hold the course
        
        schedule2[row_tem][index_teacher]++; // at this time, the teacher gonna teach the course
        
        //debug check the clash number
        //time & location
        cout<<" "<<endl<<endl;
        //cout<<"Print out how many course on this time and location:"<<endl;
        cout<<"In the schedule1 of time&location: "<<"There is  "<<schedule[row_tem][col_tem]<<" course."<<endl;
        //time & teacher
        //
        //cout<<"print out how many course on this time for a teacher: "<<endl;
        cout<<"In the schedule2 of time&teacher: "<<"The teacher has "<<schedule2[row_tem][index_teacher]<<" course at this time period."<<endl;
        cout<<" "<<endl;
        
        if(schedule[row_tem][col_tem]>1) cost++;
        cout<<"the cost after check the clash of time and location: "<<cost<<endl;
        if(schedule2[row_tem][index_teacher]>1) cost++;
        cout<<"the cost after check the clash of time and teacher: "<<cost<<endl;
        cout<<" "<<endl;
        i++;
    }
    
    return cost;
}
