#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;

//function to check course code is valid or not

bool isValidCourseCode(string courseCode)
{
	bool counter1;
	if(!(((courseCode[0]>='a' && courseCode[0]<='z')||(courseCode[0]>='A'&& courseCode[0]<='Z')) && ((courseCode[1]>='a' && courseCode[1]<='z')||(courseCode[1]>='A'&& courseCode[1]<='Z'))&& (courseCode[2]>='0'&& courseCode[2]<='9') && (courseCode[3]>='0'&& courseCode[3]<='9') && (courseCode[4]>='0'&& courseCode[4]<='9')))
	{
		return false;
	}
	else
	{
		if(courseCode.size()==5)
		{
			counter1=true;
		}
		else
		{
			counter1=false;
		}
	}
	return counter1;
}

//function to check course name

bool isValidCourseName(string courseName)
{
	bool counter;
	for(int j=0;j<courseName.length();j++)
	{
		if((courseName[j]>='a' && courseName[j]<='z') || (courseName[j]>='A' && courseName[j]<='Z') || (courseName[j]==' '))
		{
			
			counter=true;
		}
		else
		{
			counter=false;
			break;
		}
	}
	return counter;
}


//function to check the credit hours


bool isValidCreditHours(int creditHours)
{
	bool counter3;
if(creditHours>=1&&creditHours<=3)
	{
		counter3=true;

	}
else
	{
		counter3=false;
	}
	return counter3;	
}

//function to check the semester

bool isValidSemester(int semester)
{
if(semester>=1&&semester<=8)
	{
		return true;
	}
else
	{
	return false;
	}	
}

//function to add the course

void AddCourse(string courseCode[100],string courseName[100],int semester[100],int creditHours[100],int &test,string cCode,string cName,int cHours,int Semes) 
{
	
	bool compare,compare2,compare3,compare4;
for(int j=test;j<=100;j++)
	{	
		
		courseCode[j]=cCode;
		
		compare=isValidCourseCode(courseCode[j]);
		if(!compare)
		{
			cout<<endl<<"Invalid Try Again"<<endl;
			break;
		}
		
		
		
		courseName[j]=cName;
		compare2=isValidCourseName(courseName[j]);
		if(!compare2)
		{
			cout<<endl<<"Invalid Try Again"<<endl;

			break;
	
		}

		
		creditHours[j]=cHours;
		compare3=isValidCreditHours(creditHours[j]);
		if(!compare3)
		{
			cout<<endl<<"Invalid Try Again"<<endl;
			break;
		}

		
		
		semester[j]=Semes;
		compare4=isValidSemester(semester[j]);
		if(!compare4)
		{
			cout<<endl<<"Invalid Try Again"<<endl;
			break;
		}
	cout<<endl<<"Course Has Been Added Successfully"<<endl<<endl;
	cout<<"Course Details: " <<courseCode[j]<<" "<<courseName[j]<<" "<<creditHours[j]<<" "<<semester[j];
	
	
	test++;
	string k;	
	break;
	}
}

//Function to update course

void EditCourse(string updateCourse,string courseCode[100],string courseName[100],int semester[100],int creditHours[100],int test,int best,string cCode,string cName,int cHours,int Semes)
{
	
	for(int j=best;j<=100;j++)
	{
		
				
		bool compare,compare2,compare3,compare4;	
		

		
		courseCode[j]=cCode;
		compare=isValidCourseCode(courseCode[j]);
		if(!compare)
		{
			cout<<endl<<"Invalid Try Again"<<endl;
			break;
		}
		
		
		courseName[j]=cName;
		compare2=isValidCourseName(courseName[j]);
		if(!compare2)
		{
			cout<<endl<<"Invalid Try Again"<<endl;
			break;
		}
		
		creditHours[j]=cHours;
		compare3=isValidCreditHours(creditHours[j]);
		if(!compare3)
		{
			cout<<endl<<"Invalid Try Again"<<endl;
			break;
		}
		
		
		semester[j]=Semes;
		compare4=isValidSemester(semester[j]);
		if(!compare4)
		{
			cout<<endl<<"Invalid Try Again"<<endl;
			break;
		}
		cout<<endl<<"Course Has Been Updated Successfully"<<endl<<endl;
		cout<<"Course Details: " <<courseCode[j]<<" "<<courseName[j]<<" "<<creditHours[j]<<" "<<semester[j];
		
		
		break;
	

			
			
			
			
			
			
		
	 
	}


}

//function to view all courses

void ViewCourses(string courseCode[100],string courseName[100],int semester[100],int creditHours[100],int test)
{
	for(int j=0;j<test;j++)
	{
		if(!(courseCode[j].length()==0))
		{
		
		cout<<setw(15)<<courseCode[j]<<setw(15)<<courseName[j]<<setw(15)<<creditHours[j]<<setw(15)<<semester[j]<<endl;	
		}
	}
}


//Function to view semester courses

void ViewSemesterCourses(int semesterMatch,string courseCode[100],string courseName[100],int semester[100],int creditHours[100],int test)
{
	cout<<"Enter Semester Whose Courses You Want To See: ";
	cin>>semesterMatch;
	cout<<endl<<"\t\t************* All Courses Of Semester *************\t\t\t"<<endl<<endl<<setw(15)<<"\tCourse Code"<<setw(15)<<"Course Name"<<setw(15)<<"Credit Hourse"<<setw(15)<<"Semester"<<endl<<endl;
	for(int j=0;j<=test;j++)
	{
		if(semesterMatch==semester[j])
		{
			cout<<setw(15)<<courseCode[j]<<setw(15)<<courseName[j]<<setw(15)<<creditHours[j]<<setw(15)<<semester[j]<<endl;
		}
	}
}



//Function to delete the course

void DeleteCourse(string deleteCo,string courseCode[100],string courseName[100],int semester[100],int creditHours[100],int test)
{
	cout<<"Enter Course Code of Course You Want To Delete: ";
	cin>>deleteCo;
	for(int j=0;j<=100;j++)
	{
		if((deleteCo==courseCode[j]))
		{
			courseCode[j]="\0";
			courseName[j]="\0";
			creditHours[j]='\0';
			semester[j]='\0';
			break;
		}
	}
}


//Function to save the course

bool SaveCourses(string courseCode[100],string courseName[100],int semester[100],int creditHours[100],int test)
{	
	ofstream myfile;
	myfile.open("zahid ali.txt");
	for(int j=0;j<test;j++)
	{
		if(!(courseCode[j].length()==0))
		{
		myfile<<courseCode[j]<<","<<courseName[j]<<","<<creditHours[j]<<","<<semester[j]<<endl;
		}
	}
	myfile.close();
}

//function to load course

bool LoadCourses(string courseCode[100],string courseName[100],int semester[100],int creditHours[100],int &test,string cCode,string cName,int cHours,int Semes)
{
	ifstream myfile;
	string ours,ster;
	//bool vallid = 0;
	myfile.open("zahid ali.txt");
	if(myfile.is_open())
	{
		for(int j=0; !myfile.eof();j++)
		{
			
			
			



				bool compare,compare2,compare3,compare4;
			for(int j=test;j<=100;j++)
			{	
				
				
				getline(myfile,courseCode[j],',');
				
				compare=isValidCourseCode(courseCode[j]);
				if(!compare)
				{
//					cout<<endl<<"Invalid Try Again"<<endl;
					break;
				}
		
		
		
				
				getline(myfile,courseName[j],',');
				
				compare2=isValidCourseName(courseName[j]);
				if(!compare2)
				{
//					cout<<endl<<"Invalid Try Again"<<endl;
					break;
	
				}
				
				getline(myfile,ours,',');
				creditHours[j]=ours[0]-'0';
			
				
				
				compare3=isValidCreditHours(creditHours[j]);
				if(!compare3)
				{
//					cout<<endl<<"Invalid Try Again"<<endl;
					break;
				}

				getline(myfile,ster);
				semester[j]=ster[0]-'0';
			
				compare4=isValidSemester(semester[j]);
				if(!compare4)
				{
//					cout<<endl<<"Invalid Try Again"<<endl;
					break;
				}
//			cout<<endl<<"Course Has Been Added Successfully"<<endl<<endl;
//			cout<<"Course Details: " <<courseCode[j]<<" "<<courseName[j]<<" "<<creditHours[j]<<" "<<semester[j];
	
			
//			cout<<setw(15)<<courseCode[j]<<setw(15)<<courseName[j]<<setw(15)<<creditHours[j]<<setw(15)<<semester[j]<<endl;

			test++;
			string k;	
			break;
			}


		






		

















			
			
		}
	//	valid=1;
	}
	//else
	//	valid =0;
	myfile.close();
//	return valid;
	
}





int main()
{
	cout<<endl<<"\t  ************** Assalam o Alaikum : Welcome To University Learning Management System **************"<<endl<<endl<<endl;
	cout<<" ******** Choose The Following Option ********"<<endl;
	cout<<"\n 1 \tAdd Course\n 2\tUpdate Course\n 3\tDelete Course\n 4\tView All Added Courses\n 5\tView All Courses Of Semester\n 6\tExit Program"<<endl;
	string courseCode[100],courseName[100],updateCourse,deleteCo,cCode,cName;
	int semester[100],creditHours[100],test=0,semesterMatch,cHours,Semes;

	LoadCourses(courseCode,courseName,semester,creditHours,test,cCode,cName,cHours,Semes);

	string option;
z5:	cout<<endl<<endl<<"Your Option Is ( Only Integers )?  = ";
	cin>>option;
	cin.ignore();
	if (option>="1" && option <="6")
	{
	
	if(option=="1")
	{
	
	
		cout<<endl<<"Enter The Details Of The Course"<<endl<<endl;
		cout<<"Enter Course Code (Example cs101): ";
		getline(cin,cCode);
		cout<< "Enter Course Name(Alphabets): ";
		getline(cin,cName);
		cout<<"Enter Credit Hours ( Only Integers Allowed 1 to 3 ): ";
		cin>>cHours;
		cout<<"Enter Semester ( Only Integers Allowed 1 to 8 ): ";
		cin>>Semes;	
		AddCourse(courseCode,courseName,semester,creditHours,test,cCode,cName,cHours,Semes);
		goto z5;
	
	
	}
	if(option=="2")
	{
			cout<<"Enter Course Code Of Course You Want To Edit: ";
			cin>>updateCourse;
			cin.ignore();

		for(int j=0,best=0;j<=100;j++)
		{

			if((updateCourse==courseCode[j]))
			{
			cout<<endl<<endl<<"Enter The Details Of The Course"<<endl<<endl;
			cout<<"Enter Course Code (Example cs101): ";
			getline(cin,cCode);
			cout<< "Enter Course Name(Alphabets): ";
			getline(cin,cName);
			cout<<"Enter Credit Hours ( Only Integers Allowed 1 to 3 ): ";
			cin>>cHours;
			cout<<"Enter Semester ( Only Integers Allowed 1 to 8 ): ";
			cin>>Semes;
			EditCourse(updateCourse,courseCode,courseName,semester,creditHours,test,best,cCode,cName,cHours,Semes);

			break;
			}
			best++;
		}
		goto z5;


	}
	
	if(option=="3")
	{
	DeleteCourse(deleteCo,courseCode,courseName,semester,creditHours,test);
	cout<<endl<<endl<<"****** Course Has Been Deleted Successfull *****"<<endl<<endl;
	
	
	
	
	goto z5;
	}
	
	
	
	
	
	
	if(option=="4")
	{
	cout<<endl<<"\t\t*************All Courses Details *************\t\t\t"<<endl<<endl<<setw(15)<<"\tCourse Code"<<setw(15)<<"Course Name"<<setw(15)<<"Credit Hourse"<<setw(15)<<"Semester"<<endl<<endl;
	ViewCourses(courseCode,courseName,semester,creditHours,test);
	
	goto z5;
	}
	if(option=="5")
	{
	ViewSemesterCourses(semesterMatch,courseCode,courseName,semester,creditHours,test);
	goto z5;
	}
	if(option=="6")
	{
		
	SaveCourses(courseCode,courseName,semester,creditHours,test);
	
	cout<<endl<<endl<<endl<<"\t\t************** Thankyou Allah Hafiz **************\t\t"<<endl<<endl;
	}
	
	else
	{
	goto z5;
	}

	}
	
	if (!(option>="1" && option <="6"))
	{
	goto z5;
	}
	
	return 0;
}

