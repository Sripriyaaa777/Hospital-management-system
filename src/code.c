#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50
#define MAX_APPOINTMENTS 100
#define MAX_RECORDS 100
#define MAX_BILLS 100
#define MAX_STAFF 50
#define MAX_ROOMS 20

// Define structures
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
    int patient_id;
    int doctor_id;
    char date[20];
} Appointment;

typedef struct {
    int id;
    int patient_id;
    char diagnosis[100];
    char treatment[100];
} MedicalRecord;

typedef struct {
    int id;
    int patient_id;
    double amount;
    char date[20];
} Bill;

typedef struct {
    int id;
    char name[50];
    char role[30];
} Staff;

typedef struct {
    int id;
    char name[50];
    int capacity;
} Room;

// Global arrays
Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
Appointment appointments[MAX_APPOINTMENTS];
MedicalRecord records[MAX_RECORDS];
Bill bills[MAX_BILLS];
Staff staff[MAX_STAFF];
Room rooms[MAX_ROOMS];

// Global counters
int patientCount = 0, doctorCount = 0, appointmentCount = 0, recordCount = 0, billCount = 0, staffCount = 0, roomCount = 0;

// Function declarations
void add_patient_gui(GtkWidget *widget, gpointer data);
void list_patients_gui(GtkWidget *widget, gpointer data);
void add_doctor_gui(GtkWidget *widget, gpointer data);
void list_doctors_gui(GtkWidget *widget, gpointer data);
void add_appointment_gui(GtkWidget *widget, gpointer data);
void list_appointments_gui(GtkWidget *widget, gpointer data);
void add_medical_record_gui(GtkWidget *widget, gpointer data);
void list_medical_records_gui(GtkWidget *widget, gpointer data);
void add_bill_gui(GtkWidget *widget, gpointer data);
void list_bills_gui(GtkWidget *widget, gpointer data);
void add_room_gui(GtkWidget *widget, gpointer data);
void list_rooms_gui(GtkWidget *widget, gpointer data);
void add_staff_gui(GtkWidget *widget, gpointer data);
void list_staff_gui(GtkWidget *widget, gpointer data);

void create_main_window()
{
    GtkWidget *window, *vbox, *add_patient_button, *list_patients_button, *add_doctor_button, *list_doctors_button;
    GtkWidget *add_appointment_button, *list_appointments_button, *add_medical_record_button, *list_medical_records_button;
    GtkWidget *add_bill_button, *list_bills_button, *add_room_button, *list_rooms_button, *add_staff_button, *list_staff_button;

    gtk_init(NULL, NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hospital Management System");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 600);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    add_patient_button = gtk_button_new_with_label("Add Patient");
    g_signal_connect(add_patient_button, "clicked", G_CALLBACK(add_patient_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), add_patient_button, TRUE, TRUE, 5);

    list_patients_button = gtk_button_new_with_label("List Patients");
    g_signal_connect(list_patients_button, "clicked", G_CALLBACK(list_patients_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), list_patients_button, TRUE, TRUE, 5);

    add_doctor_button = gtk_button_new_with_label("Add Doctor");
    g_signal_connect(add_doctor_button, "clicked", G_CALLBACK(add_doctor_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), add_doctor_button, TRUE, TRUE, 5);

    list_doctors_button = gtk_button_new_with_label("List Doctors");
    g_signal_connect(list_doctors_button, "clicked", G_CALLBACK(list_doctors_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), list_doctors_button, TRUE, TRUE, 5);

    add_appointment_button = gtk_button_new_with_label("Add Appointment");
    g_signal_connect(add_appointment_button, "clicked", G_CALLBACK(add_appointment_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), add_appointment_button, TRUE, TRUE, 5);

    list_appointments_button = gtk_button_new_with_label("List Appointments");
    g_signal_connect(list_appointments_button, "clicked", G_CALLBACK(list_appointments_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), list_appointments_button, TRUE, TRUE, 5);

    add_medical_record_button = gtk_button_new_with_label("Add Medical Record");
    g_signal_connect(add_medical_record_button, "clicked", G_CALLBACK(add_medical_record_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), add_medical_record_button, TRUE, TRUE, 5);

    list_medical_records_button = gtk_button_new_with_label("List Medical Records");
    g_signal_connect(list_medical_records_button, "clicked", G_CALLBACK(list_medical_records_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), list_medical_records_button, TRUE, TRUE, 5);

    add_bill_button = gtk_button_new_with_label("Add Bill");
    g_signal_connect(add_bill_button, "clicked", G_CALLBACK(add_bill_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), add_bill_button, TRUE, TRUE, 5);

    list_bills_button = gtk_button_new_with_label("List Bills");
    g_signal_connect(list_bills_button, "clicked", G_CALLBACK(list_bills_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), list_bills_button, TRUE, TRUE, 5);

    add_room_button = gtk_button_new_with_label("Add Room");
    g_signal_connect(add_room_button, "clicked", G_CALLBACK(add_room_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), add_room_button, TRUE, TRUE, 5);

    list_rooms_button = gtk_button_new_with_label("List Rooms");
    g_signal_connect(list_rooms_button, "clicked", G_CALLBACK(list_rooms_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), list_rooms_button, TRUE, TRUE, 5);

    add_staff_button = gtk_button_new_with_label("Add Staff");
    g_signal_connect(add_staff_button, "clicked", G_CALLBACK(add_staff_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), add_staff_button, TRUE, TRUE, 5);

    list_staff_button = gtk_button_new_with_label("List Staff");
    g_signal_connect(list_staff_button, "clicked", G_CALLBACK(list_staff_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), list_staff_button, TRUE, TRUE, 5);

    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
}

void add_patient_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *grid;
    GtkWidget *id_label, *id_entry;
    GtkWidget *name_label, *name_entry;
    GtkWidget *age_label, *age_entry;
    GtkWidget *gender_label, *gender_entry;
    GtkWidget *diagnosis_label, *diagnosis_entry;

    dialog = gtk_dialog_new_with_buttons(
        "Add Patient",
        NULL,
        GTK_DIALOG_MODAL,
        ("Add"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    id_label = gtk_label_new("Patient ID:");
    id_entry = gtk_entry_new();

    name_label = gtk_label_new("Name:");
    name_entry = gtk_entry_new();

    age_label = gtk_label_new("Age:");
    age_entry = gtk_entry_new();

    gender_label = gtk_label_new("Gender:");
    gender_entry = gtk_entry_new();

    diagnosis_label = gtk_label_new("Diagnosis:");
    diagnosis_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), name_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), age_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), age_entry, 1, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gender_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gender_entry, 1, 3, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), diagnosis_label, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), diagnosis_entry, 1, 4, 1, 1);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        const char *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
        int age = atoi(gtk_entry_get_text(GTK_ENTRY(age_entry)));
        const char *gender = gtk_entry_get_text(GTK_ENTRY(gender_entry));
        const char *diagnosis = gtk_entry_get_text(GTK_ENTRY(diagnosis_entry));

        if (patientCount < MAX_PATIENTS)
        {
            patients[patientCount].id = id;
            strcpy(patients[patientCount].name, name);
            patients[patientCount].age = age;
            strcpy(patients[patientCount].gender, gender);
            strcpy(patients[patientCount].diagnosis, diagnosis);
            patientCount++;
            printf("Patient added successfully!\n");
        }
        else
        {
            printf("Patient list is full!\n");
        }
    }

    gtk_widget_destroy(dialog);
}

void list_patients_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *scrolled_window, *text_view;
    GtkTextBuffer *buffer;

    dialog = gtk_dialog_new_with_buttons(
        "List of Patients",
        NULL,
        GTK_DIALOG_MODAL,
        ("Close"),
        GTK_RESPONSE_CLOSE,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 400, 300);
    gtk_container_add(GTK_CONTAINER(content_area), scrolled_window);

    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    char patient_list[5000] = "Patients:\n";
    for (int i = 0; i < patientCount; i++)
    {
        char line[200];
        sprintf(line, "ID: %d, Name: %s, Age: %d, Gender: %s, Diagnosis: %s\n",
                patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].diagnosis);
        strcat(patient_list, line);
    }

    gtk_text_buffer_set_text(buffer, patient_list, -1);

    gtk_widget_show_all(dialog);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void add_doctor_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *grid;
    GtkWidget *id_label, *id_entry;
    GtkWidget *name_label, *name_entry;
    GtkWidget *specialization_label, *specialization_entry;
    GtkWidget *availability_label, *availability_entry;

    dialog = gtk_dialog_new_with_buttons(
        "Add Doctor",
        NULL,
        GTK_DIALOG_MODAL,
        ("Add"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    id_label = gtk_label_new("Doctor ID:");
    id_entry = gtk_entry_new();

    name_label = gtk_label_new("Name:");
    name_entry = gtk_entry_new();

    specialization_label = gtk_label_new("Specialization:");
    specialization_entry = gtk_entry_new();

    availability_label = gtk_label_new("Availability:");
    availability_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), name_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), specialization_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), specialization_entry, 1, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), availability_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), availability_entry, 1, 3, 1, 1);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        const char *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
        const char *specialization = gtk_entry_get_text(GTK_ENTRY(specialization_entry));
        const char *availability = gtk_entry_get_text(GTK_ENTRY(availability_entry));

        if (doctorCount < MAX_DOCTORS)
        {
            doctors[doctorCount].id = id;
            strcpy(doctors[doctorCount].name, name);
            strcpy(doctors[doctorCount].specialization, specialization);
            strcpy(doctors[doctorCount].availability, availability);
            doctorCount++;
            printf("Doctor added successfully!\n");
        }
        else
        {
            printf("Doctor list is full!\n");
        }
    }

    gtk_widget_destroy(dialog);
}

void list_doctors_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *scrolled_window, *text_view;
    GtkTextBuffer *buffer;

    dialog = gtk_dialog_new_with_buttons(
        "List of Doctors",
        NULL,
        GTK_DIALOG_MODAL,
        ("Close"),
        GTK_RESPONSE_CLOSE,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 400, 300);
    gtk_container_add(GTK_CONTAINER(content_area), scrolled_window);

    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    char doctor_list[5000] = "Doctors:\n";
    for (int i = 0; i < doctorCount; i++)
    {
        char line[200];
        sprintf(line, "ID: %d, Name: %s, Specialization: %s, Availability: %s\n",
                doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].availability);
        strcat(doctor_list, line);
    }

    gtk_text_buffer_set_text(buffer, doctor_list, -1);

    gtk_widget_show_all(dialog);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}


// --- Add appointment feature ---
void add_appointment_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *grid;
    GtkWidget *id_label, *id_entry;
    GtkWidget *patient_id_label, *patient_id_entry;
    GtkWidget *doctor_id_label, *doctor_id_entry;
    GtkWidget *date_label, *date_entry;

    dialog = gtk_dialog_new_with_buttons(
        "Add Appointment",
        NULL,
        GTK_DIALOG_MODAL,
        ("Add"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    id_label = gtk_label_new("Appointment ID:");
    id_entry = gtk_entry_new();

    patient_id_label = gtk_label_new("Patient ID:");
    patient_id_entry = gtk_entry_new();

    doctor_id_label = gtk_label_new("Doctor ID:");
    doctor_id_entry = gtk_entry_new();

    date_label = gtk_label_new("Appointment Date:");
    date_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), patient_id_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), patient_id_entry, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), doctor_id_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), doctor_id_entry, 1, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), date_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date_entry, 1, 3, 1, 1);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        int patient_id = atoi(gtk_entry_get_text(GTK_ENTRY(patient_id_entry)));
        int doctor_id = atoi(gtk_entry_get_text(GTK_ENTRY(doctor_id_entry)));
        const char *date = gtk_entry_get_text(GTK_ENTRY(date_entry));

        if (appointmentCount < MAX_APPOINTMENTS)
        {
            appointments[appointmentCount].id = id;
            appointments[appointmentCount].patient_id = patient_id;
            appointments[appointmentCount].doctor_id = doctor_id;
            strcpy(appointments[appointmentCount].date, date);
            appointmentCount++;
            printf("Appointment added successfully!\n");
        }
        else
        {
            printf("Appointment list is full!\n");
        }
    }

    gtk_widget_destroy(dialog);
}

// --- List appointments feature ---
void list_appointments_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *scrolled_window, *text_view;
    GtkTextBuffer *buffer;

    dialog = gtk_dialog_new_with_buttons(
        "List of Appointments",
        NULL,
        GTK_DIALOG_MODAL,
        ("Close"),
        GTK_RESPONSE_CLOSE,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 400, 300);
    gtk_container_add(GTK_CONTAINER(content_area), scrolled_window);

    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    char appointment_list[5000] = "Appointments:\n";
    for (int i = 0; i < appointmentCount; i++)
    {
        char line[200];
        sprintf(line, "ID: %d, Patient ID: %d, Doctor ID: %d, Date: %s\n",
                appointments[i].id, appointments[i].patient_id, appointments[i].doctor_id, appointments[i].date);
        strcat(appointment_list, line);
    }

    gtk_text_buffer_set_text(buffer, appointment_list, -1);

    gtk_widget_show_all(dialog);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// --- Add medical record feature ---
void add_medical_record_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *grid;
    GtkWidget *id_label, *id_entry;
    GtkWidget *patient_id_label, *patient_id_entry;
    GtkWidget *diagnosis_label, *diagnosis_entry;
    GtkWidget *treatment_label, *treatment_entry;

    dialog = gtk_dialog_new_with_buttons(
        "Add Medical Record",
        NULL,
        GTK_DIALOG_MODAL,
        ("Add"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    id_label = gtk_label_new("Record ID:");
    id_entry = gtk_entry_new();

    patient_id_label = gtk_label_new("Patient ID:");
    patient_id_entry = gtk_entry_new();

    diagnosis_label = gtk_label_new("Diagnosis:");
    diagnosis_entry = gtk_entry_new();

    treatment_label = gtk_label_new("Treatment:");
    treatment_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), patient_id_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), patient_id_entry, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), diagnosis_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), diagnosis_entry, 1, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), treatment_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), treatment_entry, 1, 3, 1, 1);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        int patient_id = atoi(gtk_entry_get_text(GTK_ENTRY(patient_id_entry)));
        const char *diagnosis = gtk_entry_get_text(GTK_ENTRY(diagnosis_entry));
        const char *treatment = gtk_entry_get_text(GTK_ENTRY(treatment_entry));

        if (recordCount < MAX_RECORDS)
        {
            records[recordCount].id = id;
            records[recordCount].patient_id = patient_id;
            strcpy(records[recordCount].diagnosis, diagnosis);
            strcpy(records[recordCount].treatment, treatment);
            recordCount++;
            printf("Medical record added successfully!\n");
        }
        else
        {
            printf("Medical record list is full!\n");
        }
    }

    gtk_widget_destroy(dialog);
}

// --- List medical records feature ---
void list_medical_records_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *scrolled_window, *text_view;
    GtkTextBuffer *buffer;

    dialog = gtk_dialog_new_with_buttons(
        "List of Medical Records",
        NULL,
        GTK_DIALOG_MODAL,
        ("Close"),
        GTK_RESPONSE_CLOSE,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 400, 300);
    gtk_container_add(GTK_CONTAINER(content_area), scrolled_window);

    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    char medical_record_list[5000] = "Medical Records:\n";
    for (int i = 0; i < recordCount; i++)
    {
        char line[200];
        sprintf(line, "ID: %d, Patient ID: %d, Diagnosis: %s, Treatment: %s\n",
                records[i].id, records[i].patient_id, records[i].diagnosis, records[i].treatment);
        strcat(medical_record_list, line);
    }

    gtk_text_buffer_set_text(buffer, medical_record_list, -1);

    gtk_widget_show_all(dialog);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// --- Add bill feature ---
void add_bill_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *grid;
    GtkWidget *id_label, *id_entry;
    GtkWidget *patient_id_label, *patient_id_entry;
    GtkWidget *amount_label, *amount_entry;
    GtkWidget *date_label, *date_entry;

    dialog = gtk_dialog_new_with_buttons(
        "Add Bill",
        NULL,
        GTK_DIALOG_MODAL,
        ("Add"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    id_label = gtk_label_new("Bill ID:");
    id_entry = gtk_entry_new();

    patient_id_label = gtk_label_new("Patient ID:");
    patient_id_entry = gtk_entry_new();

    amount_label = gtk_label_new("Amount:");
    amount_entry = gtk_entry_new();

    date_label = gtk_label_new("Date:");
    date_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), patient_id_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), patient_id_entry, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), amount_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), amount_entry, 1, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), date_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date_entry, 1, 3, 1, 1);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        int patient_id = atoi(gtk_entry_get_text(GTK_ENTRY(patient_id_entry)));
        double amount = atof(gtk_entry_get_text(GTK_ENTRY(amount_entry)));
        const char *date = gtk_entry_get_text(GTK_ENTRY(date_entry));

        if (billCount < MAX_BILLS)
        {
            bills[billCount].id = id;
            bills[billCount].patient_id = patient_id;
            bills[billCount].amount = amount;
            strcpy(bills[billCount].date, date);
            billCount++;
            printf("Bill added successfully!\n");
        }
        else
        {
            printf("Bill list is full!\n");
        }
    }

    gtk_widget_destroy(dialog);
}

// --- List bills feature ---
void list_bills_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *scrolled_window, *text_view;
    GtkTextBuffer *buffer;

    dialog = gtk_dialog_new_with_buttons(
        "List of Bills",
        NULL,
        GTK_DIALOG_MODAL,
        ("Close"),
        GTK_RESPONSE_CLOSE,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 400, 300);
    gtk_container_add(GTK_CONTAINER(content_area), scrolled_window);

    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    char bill_list[5000] = "Bills:\n";
    for (int i = 0; i < billCount; i++)
    {
        char line[200];
        sprintf(line, "ID: %d, Patient ID: %d, Amount: %.2f, Date: %s\n",
                bills[i].id, bills[i].patient_id, bills[i].amount, bills[i].date);
        strcat(bill_list, line);
    }

    gtk_text_buffer_set_text(buffer, bill_list, -1);

    gtk_widget_show_all(dialog);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// --- Add room feature ---
void add_room_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *grid;
    GtkWidget *id_label, *id_entry;
    GtkWidget *name_label, *name_entry;
    GtkWidget *capacity_label, *capacity_entry;

    dialog = gtk_dialog_new_with_buttons(
        "Add Room",
        NULL,
        GTK_DIALOG_MODAL,
        ("Add"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    id_label = gtk_label_new("Room ID:");
    id_entry = gtk_entry_new();

    name_label = gtk_label_new("Room Name:");
    name_entry = gtk_entry_new();

    capacity_label = gtk_label_new("Capacity:");
    capacity_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), name_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), capacity_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), capacity_entry, 1, 2, 1, 1);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        const char *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
        int capacity = atoi(gtk_entry_get_text(GTK_ENTRY(capacity_entry)));

        if (roomCount < MAX_ROOMS)
        {
            rooms[roomCount].id = id;
            strcpy(rooms[roomCount].name, name);
            rooms[roomCount].capacity = capacity;
            roomCount++;
            printf("Room added successfully!\n");
        }
        else
        {
            printf("Room list is full!\n");
        }
    }

    gtk_widget_destroy(dialog);
}

// --- List rooms feature ---
void list_rooms_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *scrolled_window, *text_view;
    GtkTextBuffer *buffer;

    dialog = gtk_dialog_new_with_buttons(
        "List of Rooms",
        NULL,
        GTK_DIALOG_MODAL,
        ("Close"),
        GTK_RESPONSE_CLOSE,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 400, 300);
    gtk_container_add(GTK_CONTAINER(content_area), scrolled_window);

    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    char room_list[5000] = "Rooms:\n";
    for (int i = 0; i < roomCount; i++)
    {
        char line[200];
        sprintf(line, "ID: %d, Name: %s, Capacity: %d\n",
                rooms[i].id, rooms[i].name, rooms[i].capacity);
        strcat(room_list, line);
    }

    gtk_text_buffer_set_text(buffer, room_list, -1);

    gtk_widget_show_all(dialog);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// --- Add staff feature ---
void add_staff_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *grid;
    GtkWidget *id_label, *id_entry;
    GtkWidget *name_label, *name_entry;
    GtkWidget *role_label, *role_entry;

    dialog = gtk_dialog_new_with_buttons(
        "Add Staff",
        NULL,
        GTK_DIALOG_MODAL,
        ("Add"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    id_label = gtk_label_new("Staff ID:");
    id_entry = gtk_entry_new();

    name_label = gtk_label_new("Staff Name:");
    name_entry = gtk_entry_new();

    role_label = gtk_label_new("Role:");
    role_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), name_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), role_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), role_entry, 1, 2, 1, 1);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        const char *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
        const char *role = gtk_entry_get_text(GTK_ENTRY(role_entry));

        if (staffCount < MAX_STAFF)
        {
            staff[staffCount].id = id;
            strcpy(staff[staffCount].name, name);
            strcpy(staff[staffCount].role, role);
            staffCount++;
            printf("Staff added successfully!\n");
        }
        else
        {
            printf("Staff list is full!\n");
        }
    }

    gtk_widget_destroy(dialog);
}

// --- List staff feature ---
void list_staff_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *scrolled_window, *text_view;
    GtkTextBuffer *buffer;

    dialog = gtk_dialog_new_with_buttons(
        "List of Staff",
        NULL,
        GTK_DIALOG_MODAL,
        ("Close"),
        GTK_RESPONSE_CLOSE,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 400, 300);
    gtk_container_add(GTK_CONTAINER(content_area), scrolled_window);

    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    char staff_list[5000] = "Staff Members:\n";
    for (int i = 0; i < staffCount; i++)
    {
        char line[200];
        sprintf(line, "ID: %d, Name: %s, Role: %s\n",
                staff[i].id, staff[i].name, staff[i].role);
        strcat(staff_list, line);
    }

    gtk_text_buffer_set_text(buffer, staff_list, -1);

    gtk_widget_show_all(dialog);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[])
{
    create_main_window();
    return 0;
}
