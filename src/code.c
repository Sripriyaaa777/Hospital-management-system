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

typedef struct
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char diagnosis[100];
} Patient;

typedef struct
{
    int id;
    char name[50];
    char specialization[50];
    char availability[30];
} Doctor;

typedef struct
{
    int id;
    int patient_id;
    int doctor_id;
    char date[20];
} Appointment;

typedef struct
{
    int id;
    int patient_id;
    char diagnosis[100];
    char treatment[100];
} MedicalRecord;

typedef struct
{
    int id;
    int patient_id;
    double amount;
    char date[20];
} Bill;

typedef struct
{
    int id;
    char name[50];
    char role[30];
} Staff;

typedef struct
{
    int id;
    char name[50];
    int capacity;
} Room;

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
Appointment appointments[MAX_APPOINTMENTS];
MedicalRecord records[MAX_RECORDS];
Bill bills[MAX_BILLS];
Staff staff[MAX_STAFF];
Room rooms[MAX_ROOMS];

int patientCount = 0, doctorCount = 0, appointmentCount = 0, recordCount = 0, billCount = 0, staffCount = 0, roomCount = 0;

void add_patient_gui(GtkWidget *widget, gpointer data);
void search_patient_gui(GtkWidget *widget, gpointer data);
void update_patient_gui(GtkWidget *widget, gpointer data);
void delete_patient_gui(GtkWidget *widget, gpointer data);
void list_patients_gui(GtkWidget *widget, gpointer data);
void add_doctor_gui(GtkWidget *widget, gpointer data);
void search_doctor_gui(GtkWidget *widget, gpointer data);
void update_doctor_gui(GtkWidget *widget, gpointer data);
void delete_doctor_gui(GtkWidget *widget, gpointer data);
void list_doctors_gui(GtkWidget *widget, gpointer data);
void add_appointment_gui(GtkWidget *widget, gpointer data);
void list_appointments_gui(GtkWidget *widget, gpointer data);

void create_main_window()
{
    GtkWidget *window, *vbox, *add_patient_button, *list_patients_button, *search_patient_button, *update_patient_button, *delete_patient_button, *add_doctor_button, *list_doctors_button;
    GtkWidget *search_doctor_button, *update_doctor_button, *delete_doctor_button, *add_appointment_button, *list_appointments_button, *add_medical_record_button, *list_medical_records_button;
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

    search_patient_button = gtk_button_new_with_label("Search Patient");
    g_signal_connect(search_patient_button, "clicked", G_CALLBACK(search_patient_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), search_patient_button, TRUE, TRUE, 5);

    update_patient_button = gtk_button_new_with_label("Update Patient");
    g_signal_connect(update_patient_button, "clicked", G_CALLBACK(update_patient_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), update_patient_button, TRUE, TRUE, 5);

    delete_patient_button = gtk_button_new_with_label("Delete Patient");
    g_signal_connect(delete_patient_button, "clicked", G_CALLBACK(delete_patient_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), delete_patient_button, TRUE, TRUE, 5);

    add_doctor_button = gtk_button_new_with_label("Add Doctor");
    g_signal_connect(add_doctor_button, "clicked", G_CALLBACK(add_doctor_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), add_doctor_button, TRUE, TRUE, 5);

    list_doctors_button = gtk_button_new_with_label("List Doctors");
    g_signal_connect(list_doctors_button, "clicked", G_CALLBACK(list_doctors_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), list_doctors_button, TRUE, TRUE, 5);

    search_doctor_button = gtk_button_new_with_label("Search Doctor");
    g_signal_connect(search_doctor_button, "clicked", G_CALLBACK(search_doctor_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), search_doctor_button, TRUE, TRUE, 5);

    update_doctor_button = gtk_button_new_with_label("Update Doctor Details");
    g_signal_connect(update_doctor_button, "clicked", G_CALLBACK(update_doctor_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), update_doctor_button, TRUE, TRUE, 5);

    delete_doctor_button = gtk_button_new_with_label("Delete Doctor");
    g_signal_connect(delete_doctor_button, "clicked", G_CALLBACK(delete_doctor_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), delete_doctor_button, TRUE, TRUE, 5);

    add_appointment_button = gtk_button_new_with_label("Add Appointment");
    g_signal_connect(add_appointment_button, "clicked", G_CALLBACK(add_appointment_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), add_appointment_button, TRUE, TRUE, 5);

    list_appointments_button = gtk_button_new_with_label("List Appointments");
    g_signal_connect(list_appointments_button, "clicked", G_CALLBACK(list_appointments_gui), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), list_appointments_button, TRUE, TRUE, 5);

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
void search_patient_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *id_label, *id_entry, *result_label;

    dialog = gtk_dialog_new_with_buttons(
        "Search Patient",
        NULL,
        GTK_DIALOG_MODAL,
        ("Search"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    id_label = gtk_label_new("Enter Patient ID:");
    id_entry = gtk_entry_new();
    result_label = gtk_label_new("");

    gtk_box_pack_start(GTK_BOX(content_area), id_label, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(content_area), id_entry, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(content_area), result_label, FALSE, FALSE, 5);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        gboolean found = FALSE;

        for (int i = 0; i < patientCount; i++)
        {
            if (patients[i].id == id)
            {
                char result[500];
                sprintf(result, "Patient Found:\nID: %d\nName: %s\nAge: %d\nGender: %s\nDiagnosis: %s",
                        patients[i].id, patients[i].name, patients[i].age,
                        patients[i].gender, patients[i].diagnosis);
                gtk_label_set_text(GTK_LABEL(result_label), result);
                found = TRUE;
                break;
            }
        }

        if (!found)
        {
            gtk_label_set_text(GTK_LABEL(result_label), "Patient not found!");
        }

        gtk_widget_show_all(dialog);
        gtk_dialog_run(GTK_DIALOG(dialog));
    }

    gtk_widget_destroy(dialog);
}

void update_patient_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *grid;
    GtkWidget *id_label, *id_entry;
    GtkWidget *name_label, *name_entry;
    GtkWidget *age_label, *age_entry;
    GtkWidget *gender_label, *gender_entry;
    GtkWidget *diagnosis_label, *diagnosis_entry;

    dialog = gtk_dialog_new_with_buttons(
        "Update Patient Details",
        NULL,
        GTK_DIALOG_MODAL,
        ("Search"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    id_label = gtk_label_new("Enter Patient ID:");
    id_entry = gtk_entry_new();

    gtk_box_pack_start(GTK_BOX(content_area), id_label, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(content_area), id_entry, FALSE, FALSE, 5);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        gboolean found = FALSE;

        for (int i = 0; i < patientCount; i++)
        {
            if (patients[i].id == id)
            {
                found = TRUE;

                GtkWidget *update_dialog = gtk_dialog_new_with_buttons(
                    "Edit Patient Details",
                    NULL,
                    GTK_DIALOG_MODAL,
                    ("Save"),
                    GTK_RESPONSE_ACCEPT,
                    ("Cancel"),
                    GTK_RESPONSE_REJECT,
                    NULL);

                GtkWidget *update_content_area = gtk_dialog_get_content_area(GTK_DIALOG(update_dialog));
                grid = gtk_grid_new();
                gtk_container_add(GTK_CONTAINER(update_content_area), grid);

                name_label = gtk_label_new("Name:");
                name_entry = gtk_entry_new();
                gtk_entry_set_text(GTK_ENTRY(name_entry), patients[i].name);

                age_label = gtk_label_new("Age:");
                age_entry = gtk_entry_new();
                char age_str[10];
                sprintf(age_str, "%d", patients[i].age);
                gtk_entry_set_text(GTK_ENTRY(age_entry), age_str);

                gender_label = gtk_label_new("Gender:");
                gender_entry = gtk_entry_new();
                gtk_entry_set_text(GTK_ENTRY(gender_entry), patients[i].gender);

                diagnosis_label = gtk_label_new("Diagnosis:");
                diagnosis_entry = gtk_entry_new();
                gtk_entry_set_text(GTK_ENTRY(diagnosis_entry), patients[i].diagnosis);

                gtk_grid_attach(GTK_GRID(grid), name_label, 0, 0, 1, 1);
                gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 0, 1, 1);

                gtk_grid_attach(GTK_GRID(grid), age_label, 0, 1, 1, 1);
                gtk_grid_attach(GTK_GRID(grid), age_entry, 1, 1, 1, 1);

                gtk_grid_attach(GTK_GRID(grid), gender_label, 0, 2, 1, 1);
                gtk_grid_attach(GTK_GRID(grid), gender_entry, 1, 2, 1, 1);

                gtk_grid_attach(GTK_GRID(grid), diagnosis_label, 0, 3, 1, 1);
                gtk_grid_attach(GTK_GRID(grid), diagnosis_entry, 1, 3, 1, 1);

                gtk_widget_show_all(update_dialog);

                if (gtk_dialog_run(GTK_DIALOG(update_dialog)) == GTK_RESPONSE_ACCEPT)
                {
                    strcpy(patients[i].name, gtk_entry_get_text(GTK_ENTRY(name_entry)));
                    patients[i].age = atoi(gtk_entry_get_text(GTK_ENTRY(age_entry)));
                    strcpy(patients[i].gender, gtk_entry_get_text(GTK_ENTRY(gender_entry)));
                    strcpy(patients[i].diagnosis, gtk_entry_get_text(GTK_ENTRY(diagnosis_entry)));
                    printf("Patient details updated successfully!\n");
                }

                gtk_widget_destroy(update_dialog);
                break;
            }
        }

        if (!found)
        {
            GtkWidget *error_dialog = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_OK,
                "Patient with ID %d not found.",
                id);
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
        }
    }

    gtk_widget_destroy(dialog);
}

void delete_patient_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area;
    GtkWidget *id_label, *id_entry;

    // Create a dialog to input patient ID
    dialog = gtk_dialog_new_with_buttons(
        "Delete Patient",
        NULL,
        GTK_DIALOG_MODAL,
        ("Delete"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    id_label = gtk_label_new("Enter Patient ID:");
    id_entry = gtk_entry_new();

    gtk_box_pack_start(GTK_BOX(content_area), id_label, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(content_area), id_entry, FALSE, FALSE, 5);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));
        gboolean found = FALSE;

        // Search for the patient in the array
        for (int i = 0; i < patientCount; i++)
        {
            if (patients[i].id == id)
            {
                found = TRUE;

                // Shift all patients after the found one up by one position
                for (int j = i; j < patientCount - 1; j++)
                {
                    patients[j] = patients[j + 1];
                }

                patientCount--; // Reduce the patient count
                printf("Patient with ID %d deleted successfully!\n", id);

                // Show success message
                GtkWidget *success_dialog = gtk_message_dialog_new(
                    NULL,
                    GTK_DIALOG_MODAL,
                    GTK_MESSAGE_INFO,
                    GTK_BUTTONS_OK,
                    "Patient with ID %d deleted successfully.",
                    id);
                gtk_dialog_run(GTK_DIALOG(success_dialog));
                gtk_widget_destroy(success_dialog);

                break;
            }
        }

        if (!found)
        {
            // Show error message if patient is not found
            GtkWidget *error_dialog = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_OK,
                "Patient with ID %d not found.",
                id);
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
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

void search_doctor_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *entry, *label;

    dialog = gtk_dialog_new_with_buttons(
        "Search Doctor",
        NULL,
        GTK_DIALOG_MODAL,
        ("Search"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    label = gtk_label_new("Enter Doctor ID to search:");
    entry = gtk_entry_new();

    gtk_box_pack_start(GTK_BOX(content_area), label, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(content_area), entry, FALSE, FALSE, 5);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(entry)));
        int found = 0;

        for (int i = 0; i < doctorCount; i++)
        {
            if (doctors[i].id == id)
            {
                found = 1;

                GtkWidget *result_dialog = gtk_message_dialog_new(
                    GTK_WINDOW(dialog),
                    GTK_DIALOG_MODAL,
                    GTK_MESSAGE_INFO,
                    GTK_BUTTONS_OK,
                    "Doctor Details:\n\n"
                    "ID: %d\n"
                    "Name: %s\n"
                    "Specialization: %s\n"
                    "Availability: %s",
                    doctors[i].id,
                    doctors[i].name,
                    doctors[i].specialization,
                    doctors[i].availability);

                gtk_dialog_run(GTK_DIALOG(result_dialog));
                gtk_widget_destroy(result_dialog);
                break;
            }
        }

        if (!found)
        {
            GtkWidget *error_dialog = gtk_message_dialog_new(
                GTK_WINDOW(dialog),
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_OK,
                "Doctor not found!");
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
        }
    }

    gtk_widget_destroy(dialog);
}

void update_doctor_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *id_entry, *name_entry, *specialization_entry, *availability_entry, *grid;
    int id, found = 0;

    dialog = gtk_dialog_new_with_buttons(
        "Update Doctor",
        NULL,
        GTK_DIALOG_MODAL,
        ("Update"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    GtkWidget *id_label = gtk_label_new("Doctor ID:");
    id_entry = gtk_entry_new();

    GtkWidget *name_label = gtk_label_new("Name:");
    name_entry = gtk_entry_new();

    GtkWidget *specialization_label = gtk_label_new("Specialization:");
    specialization_entry = gtk_entry_new();

    GtkWidget *availability_label = gtk_label_new("Availability:");
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
        id = atoi(gtk_entry_get_text(GTK_ENTRY(id_entry)));

        for (int i = 0; i < doctorCount; i++)
        {
            if (doctors[i].id == id)
            {
                found = 1;

                const char *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
                const char *specialization = gtk_entry_get_text(GTK_ENTRY(specialization_entry));
                const char *availability = gtk_entry_get_text(GTK_ENTRY(availability_entry));

                strcpy(doctors[i].name, name);
                strcpy(doctors[i].specialization, specialization);
                strcpy(doctors[i].availability, availability);

                GtkWidget *success_dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                                                   GTK_DIALOG_MODAL,
                                                                   GTK_MESSAGE_INFO,
                                                                   GTK_BUTTONS_OK,
                                                                   "Doctor updated successfully!");
                gtk_dialog_run(GTK_DIALOG(success_dialog));
                gtk_widget_destroy(success_dialog);
                break;
            }
        }

        if (!found)
        {
            GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                                             GTK_DIALOG_MODAL,
                                                             GTK_MESSAGE_ERROR,
                                                             GTK_BUTTONS_OK,
                                                             "Doctor not found!");
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
        }
    }

    gtk_widget_destroy(dialog);
}

void delete_doctor_gui(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog, *content_area, *entry, *label;

    dialog = gtk_dialog_new_with_buttons(
        "Delete Doctor",
        NULL,
        GTK_DIALOG_MODAL,
        ("Delete"),
        GTK_RESPONSE_ACCEPT,
        ("Cancel"),
        GTK_RESPONSE_REJECT,
        NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    label = gtk_label_new("Enter Doctor ID to delete:");
    entry = gtk_entry_new();

    gtk_box_pack_start(GTK_BOX(content_area), label, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(content_area), entry, FALSE, FALSE, 5);

    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        int id = atoi(gtk_entry_get_text(GTK_ENTRY(entry)));
        int found = 0;

        for (int i = 0; i < doctorCount; i++)
        {
            if (doctors[i].id == id)
            {
                found = 1;

                // Shift remaining doctors up in the array
                for (int j = i; j < doctorCount - 1; j++)
                {
                    doctors[j] = doctors[j + 1];
                }
                doctorCount--;

                GtkWidget *success_dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                                                   GTK_DIALOG_MODAL,
                                                                   GTK_MESSAGE_INFO,
                                                                   GTK_BUTTONS_OK,
                                                                   "Doctor deleted successfully!");
                gtk_dialog_run(GTK_DIALOG(success_dialog));
                gtk_widget_destroy(success_dialog);
                break;
            }
        }

        if (!found)
        {
            GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                                             GTK_DIALOG_MODAL,
                                                             GTK_MESSAGE_ERROR,
                                                             GTK_BUTTONS_OK,
                                                             "Doctor not found!");
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
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

int main(int argc, char *argv[])
{
    create_main_window();
    return 0;
}
