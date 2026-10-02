#include<iostream>
#include<vector>
#include<string>
using namespace std;
/* 
    Hospital Management System:
I am working on a hospital management system project to manage patient,doctor and their appointments.
the project should allow adding new patients,doctors,scheduling appointments,viewing patient and doctor details, and generating reports.
1. add Patient: name, age, gender, contact information, medical history
2. add Doctor: name, specialization, contact information, availability
3. schedule Appointment: patient name, doctor name, date and time
4. view Patient Details: print all the details->store in a file
5. view Doctor Details: print all the details->store in a file
6.view Appointments: print all the details->store in a file
7.exit


*/
int pid;
int did;
class Patient {
    public:
     string name;
     string gender;
     int age;
     int ID;
     Patient(string n, string g, int a){
            name=n;
            gender=g;
            age=a;
            ID=pid;
            pid++;
        }
};

class Doctor {
    public:
     string name;
     string specialization;
     string gender;
     int ID;
     int age;
     Doctor(string n, string s, string g, int a){
            name=n;
            specialization=s;
            gender=g;
            age=a;
            ID=did;
            did++;
        }

};
class Appointment {
    public:
      int patientID;
      int doctorID;
      string date;
     Appointment(int pID, int dID, string d){
            patientID=pID;
            doctorID=dID;
            date=d;
        }

};
vector<Patient> allpatients;
vector<Doctor> alldoctors;
vector<Appointment> allappointments;

bool isPatientExist(int id) {
    for(int i=0;i<allpatients.size();i++){
        if(allpatients[i].ID==id){
            return true;
        }
    }
    return false;
}
bool isDoctorExist(int id) {
    for(int i=0;i<alldoctors.size();i++){
        if(alldoctors[i].ID==id){
            return true;
        }
    }
    return false;
}
void addPatient() {
    string name, gender;
    int age;
    cout<<"Enter patient name: ";
    cin>>name;
    cout<<"Enter patient gender: ";
    cin>>gender;
    cout<<"Enter patient age: ";
    cin>>age;
     Patient temp(name, gender, age);
    allpatients.push_back(temp);
}
void addDoctor() {
    string name, specialization, gender;
    int age;
    cout<<"Enter doctor name: ";
    cin>>name;
    cout<<"Enter doctor specialization: ";
    cin>>specialization;
    cout<<"Enter doctor gender: ";
    cin>>gender;
    cout<<"Enter doctor age: ";
    cin>>age;
     Doctor temp(name, specialization, gender, age);
    alldoctors.push_back(temp);
}
void scheduleAppointment() {
    int patientID;
      int doctorID;
      string date;
     cout<<"Enter patient ID: ";
      cin>>patientID;
      cout<<"Enter doctor ID: ";
      cin>>doctorID;
      cout<<"Enter appointment date: ";
      cin>>date;
      if(!isPatientExist(patientID)){
          cout<<"Patient ID does not exist."<<endl;
          cout<<"Appointment Scheduling unsuccessful."<<endl;
          return;
      }
      if(!isDoctorExist(doctorID)){
          cout<<"Doctor ID does not exist."<<endl;
          cout<<"Appointment Scheduling unsuccessful."<<endl;
          return;
      }
      Appointment temp(patientID, doctorID, date);
      allappointments.push_back(temp);
}
void viewPatientDetails() {
    for(int i=0;i<allpatients.size();i++){
        cout<<"Patient Name"<<allpatients[i].name<<endl;
    }
    cout<<endl;
}
void viewDoctorDetails() {
    for(int i=0;i<alldoctors.size();i++){
        cout<<"Doctor Name"<<alldoctors[i].name<<endl;
    }
    cout<<endl;
}
void viewAppointments() {
    for(int i=0;i<allappointments.size();i++){
        cout<<"Patient ID"<<allappointments[i].patientID<<endl;
        cout<<"Doctor ID"<<allappointments[i].doctorID<<endl;
        cout<<"Date"<<allappointments[i].date<<endl;
    }
    cout<<endl;
}
int main(){
    pid=1;
    did=1;
    int choice;
    do{
        cout<<"1. Add Patient\n";
        cout<<"2. Add Doctor\n";
        cout<<"3. Schedule Appointment\n";
        cout<<"4. View Patient Details\n";
        cout<<"5. View Doctor Details\n";
        cout<<"6. View Appointments\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                addPatient();
                break;
            case 2:
                addDoctor();
                break;
            case 3:
                scheduleAppointment();
                break;
            case 4:
                viewPatientDetails();
                break;
            case 5:
                viewDoctorDetails();
                break;
            case 6:
                viewAppointments();
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
        
    } while(choice!=0);
    return 0;
}