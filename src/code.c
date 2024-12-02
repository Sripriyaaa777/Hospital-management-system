#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char diagnosis[100];
} Patient;

typedef struct {
    int id;
    char name[50];
    char specialization[50];
    char availability[30];
} Doctor;

typedef struct {
    int id;
    int patientID;
    int doctorID;
    char date[20];
} Appointment;
typedef struct {
    int recordID;
    int patientID;
    char diagnosis[100];
    char prescription[100];
    char labReport[100];
} MedicalRecord;

typedef struct {
    int billID;
    int patientID;
    float amount;
    char paymentMethod[20];
} Bill;

typedef struct {
    int staffID;
    char name[50];
    char role[50];
    char shift[20];
} Staff;
typedef struct {
    int roomNumber;
    int isOccupied;  // 1 if occupied, 0 if free
    int patientID;
} Room;


void addPatient();
void listPatients();
void addDoctor();
void listDoctors();
void scheduleAppointment();
void listAppointments();
void addMedicalRecord();
void listMedicalRecords();
void generateBill();
void listBills();
void addStaff();
void listStaff();
void addRoom();
void listRooms();
void assignRoom();


#define MAX_PATIENTS 100
#define MAX_DOCTORS 50
#define MAX_APPOINTMENTS 100
#define MAX_RECORDS 100
#define MAX_BILLS 100
#define MAX_STAFF 50
#define MAX_ROOMS 20

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
Appointment appointments[MAX_APPOINTMENTS];
MedicalRecord records[MAX_RECORDS];
Bill bills[MAX_BILLS];
Staff staff[MAX_STAFF];
Room rooms[MAX_ROOMS];

int patientCount = 0, doctorCount = 0, appointmentCount = 0;
int recordCount = 0, billCount = 0, staffCount = 0, roomCount = 0;
int main() {
    int choice;
    while (1) {
        printf("\n=====================================\n");
        printf("       Hospital Management System     \n");
        printf("=====================================\n");
        printf("1.  Add Patient                9.  Generate Bill\n");
        printf("2.  List Patients             10.  List Bills\n");
        printf("3.  Add Doctor                11.  Add Staff\n");
        printf("4.  List Doctors              12.  List Staff\n");
        printf("5.  Schedule Appointment      13.  Add Room\n");
        printf("6.  List Appointments         14.  List Rooms\n");
        printf("7.  Add Medical Record        15.  Assign Room\n");
        printf("8.  List Medical Records      16.  Exit\n");
        printf("=====================================\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);

 switch (choice) {
            case 1: addPatient(); break;
            case 2: listPatients(); break;
            case 3: addDoctor(); break;
            case 4: listDoctors(); break;
            case 5: scheduleAppointment(); break;
            case 6: listAppointments(); break;
            case 7: addMedicalRecord(); break;
            case 8: listMedicalRecords(); break;
            case 9: generateBill(); break;
            case 10: listBills(); break;
            case 11: addStaff(); break;
            case 12: listStaff(); break;
            case 13: addRoom(); break;
            case 14: listRooms(); break;
            case 15: assignRoom(); break;
            case 16: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
void addPatient() {
    if (patientCount < MAX_PATIENTS) {
        printf("Enter Patient ID: ");
        scanf("%d", &patients[patientCount].id);
        printf("Enter Name: ");
        scanf("%s", patients[patientCount].name);
        printf("Enter Age: ");
        scanf("%d", &patients[patientCount].age);
        printf("Enter Gender: ");
        scanf("%s", patients[patientCount].gender);
        printf("Enter Diagnosis: ");
        scanf("%s", patients[patientCount].diagnosis);

        patientCount++;
        printf("Patient added successfully!\n");
    } else {
        printf("Patient list is full!\n");
    }
}

void listPatients() {
    printf("\n=========== List of Patients ===========\n");
    for (int i = 0; i < patientCount; i++) {
        printf("Patient ID   : %d\n", patients[i].id);
        printf("Name         : %s\n", patients[i].name);
        printf("Age          : %d\n", patients[i].age);
        printf("Gender       : %s\n", patients[i].gender);
        printf("Diagnosis    : %s\n", patients[i].diagnosis);
        printf("----------------------------------------\n");  
    }
}

oid addDoctor() {
    if (doctorCount < MAX_DOCTORS) {
        printf("Enter Doctor ID: ");
        scanf("%d", &doctors[doctorCount].id);
        printf("Enter Name: ");
        scanf("%s", doctors[doctorCount].name);
        printf("Enter Specialization: ");
        scanf("%s", doctors[doctorCount].specialization);



        doctorCount++;
        printf("Doctor added successfully!\n");
    } else {
        printf("Doctor list is full!\n");
    }
}
void listDoctors() {
    printf("\n=========== List of Doctors ===========\n");
    for (int i = 0; i < doctorCount; i++) {
        printf("Doctor ID       : %d\n", doctors[i].id);
        printf("Name            : %s\n", doctors[i].name);
        printf("Specialization  : %s\n", doctors[i].specialization);
        printf("----------------------------------------\n");  
    }
}
void scheduleAppointment() {
    if (appointmentCount < MAX_APPOINTMENTS) {
        printf("Enter Appointment ID: ");
        scanf("%d", &appointments[appointmentCount].id);
        printf("Enter Patient ID: ");
        scanf("%d", &appointments[appointmentCount].patientID);
        printf("Enter Doctor ID: ");
        scanf("%d", &appointments[appointmentCount].doctorID);
        printf("Enter Date (DD-MM-YYYY): ");
        scanf("%s", appointments[appointmentCount].date);

        appointmentCount++;
        printf("Appointment scheduled successfully!\n");
    } else {
        printf("Appointment list is full!\n");
    }
}
void listAppointments() {
    printf("\n=========== List of Appointments ===========\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment ID  : %d\n", appointments[i].id);
        printf("Patient ID      : %d\n", appointments[i].patientID);
        printf("Doctor ID       : %d\n", appointments[i].doctorID);
        printf("Date            : %s\n", appointments[i].date);
        printf("---------------------------------------------\n");  
    }
}
void addMedicalRecord() {
    if (recordCount < MAX_RECORDS) {
        printf("Enter Record ID: ");
        scanf("%d", &records[recordCount].recordID);
        printf("Enter Patient ID: ");
        scanf("%d", &records[recordCount].patientID);
        printf("Enter Diagnosis: ");
        scanf("%s", records[recordCount].diagnosis);
        printf("Enter Prescription: ");
        scanf("%s", records[recordCount].prescription);
        printf("Enter Lab Report: ");
        scanf("%s", records[recordCount].labReport);

        recordCount++;
        printf("Medical record added successfully!\n");
    } else {
        printf("Medical record list is full!\n");
    }
}
void listMedicalRecords() {
    printf("\n=========== List of Medical Records ===========\n");
    for (int i = 0; i < recordCount; i++) {
        printf("Record ID     : %d\n", records[i].recordID);
        printf("Patient ID    : %d\n", records[i].patientID);
        printf("Diagnosis     : %s\n", records[i].diagnosis);
        printf("Prescription  : %s\n", records[i].prescription);
        printf("Lab Report    : %s\n", records[i].labReport);
        printf("-----------------------------------------------\n");  
    }
}
void generateBill() {
    if (billCount < MAX_BILLS) {
        printf("Enter Bill ID: ");
        scanf("%d", &bills[billCount].billID);
        printf("Enter Patient ID: ");
        scanf("%d", &bills[billCount].patientID);
        printf("Enter Amount: ");
        scanf("%f", &bills[billCount].amount);
        printf("Enter Payment Method (Cash/Insurance): ");
        scanf("%s", bills[billCount].paymentMethod);

        billCount++;
        printf("Bill generated successfully!\n");
    } else {
        printf("Bill list is full!\n");
    }
}
void listBills() {
    printf("\n=========== List of Bills ===========\n");
    for (int i = 0; i < billCount; i++) {
        printf("Bill ID         : %d\n", bills[i].billID);
        printf("Patient ID      : %d\n", bills[i].patientID);
        printf("Amount          : $%.2f\n", bills[i].amount);
        printf("Payment Method  : %s\n", bills[i].paymentMethod);
        printf("--------------------------------------\n");  
    }
}
void addStaff() {
    if (staffCount < MAX_STAFF) {
        printf("Enter Staff ID: ");
        scanf("%d", &staff[staffCount].staffID);
        printf("Enter Name: ");
        scanf("%s", staff[staffCount].name);
        printf("Enter Role: ");
        scanf("%s", staff[staffCount].role);
        printf("Enter Shift (Morning/Evening/Night): ");
        scanf("%s", staff[staffCount].shift);

        staffCount++;
        printf("Staff added successfully!\n");
    } else {
        printf("Staff list is full!\n");
    }
}
void listStaff() {
    printf("\n=========== List of Staff ===========\n");
    for (int i = 0; i < staffCount; i++) {
        printf("Staff ID   : %d\n", staff[i].staffID);
        printf("Name       : %s\n", staff[i].name);
        printf("Role       : %s\n", staff[i].role);
        printf("Shift      : %s\n", staff[i].shift);
        printf("--------------------------------------\n");  
    }
}
void addRoom() {
    if (roomCount < MAX_ROOMS) {
        printf("Enter Room Number: ");
        scanf("%d", &rooms[roomCount].roomNumber);
        rooms[roomCount].isOccupied = 0;  // Initially, room is free
        roomCount++;
        printf("Room added successfully!\n");
    } else {
        printf("Room list is full!\n");
    }
}
void listRooms() {
    printf("\n=========== List of Rooms ===========\n");
    for (int i = 0; i < roomCount; i++) {
        printf("Room Number  : %d\n", rooms[i].roomNumber);
        printf("Status       : %s\n", rooms[i].isOccupied ? "Occupied" : "Free">
        printf("--------------------------------------\n");  
    }
}

void assignRoom() {
    int roomNumber, patientID, found = 0;
    printf("Enter Room Number to assign: ");
    scanf("%d", &roomNumber);
    printf("Enter Patient ID to assign: ");
    scanf("%d", &patientID);

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNumber == roomNumber && !rooms[i].isOccupied) {
            rooms[i].isOccupied = 1;
            rooms[i].patientID = patientID;
            printf("Room assigned successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Room is either occupied or doesn't exist.\n");
    }
}

