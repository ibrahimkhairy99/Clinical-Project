#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold appointment details
struct Appointment {
    string appointmentID;
    string patientName;
    string doctorName;
    string date;
    string timeSlot;
    string status;
    double fee;
};

// Function to display the main menu
void showMainMenu() {
    cout << "\n=========================================\n";
    cout << "   ONLINE CLINIC APPOINTMENT SYSTEM      \n";
    cout << "   Developer: Ibrahim Mohamed (1202540507) \n";
    cout << "=========================================\n";
    cout << "1. Patient Portal (Book Appointment)\n";
    cout << "2. Doctor Portal (View Schedule)\n";
    cout << "3. Admin / Receptionist Portal (View All & Billing)\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<Appointment> appointments = {
        {"APT101", "Mohamed Ali", "Dr. Ahmed Mamdouh", "20/10/2026", "5:00 PM", "Confirmed", 300.0},
        {"APT102", "Sara Ahmed", "Dr. Ziad Mohamed", "21/10/2026", "6:00 PM", "Confirmed", 250.0},
        {"APT103", "Omar Hassan", "Dr. Mahmoud Hassan", "22/10/2026", "7:00 PM", "Completed", 350.0}
    };

    int choice;
    do {
        showMainMenu();
        cin >> choice;

        if (choice == 1) {
            // Patient Portal
            cout << "\n--- Patient Portal ---\n";
            Appointment newApp;
            newApp.appointmentID = "APT10" + to_string(appointments.size() + 1);

            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, newApp.patientName);

            cout << "Select Specialty / Doctor:\n";
            cout << "1. Internal Medicine (Dr. Ahmed Mamdouh - 300 EGP)\n";
            cout << "2. Pediatrics (Dr. Ziad Mohamed - 250 EGP)\n";
            cout << "3. Orthopedics (Dr. Mahmoud Hassan - 350 EGP)\n";
            int docChoice;
            cin >> docChoice;

            if (docChoice == 1) { newApp.doctorName = "Dr. Ahmed Mamdouh"; newApp.fee = 300.0; }
            else if (docChoice == 2) { newApp.doctorName = "Dr. Ziad Mohamed"; newApp.fee = 250.0; }
            else { newApp.doctorName = "Dr. Mahmoud Hassan"; newApp.fee = 350.0; }

            cout << "Enter Date (DD/MM/YYYY): ";
            cin >> newApp.date;
            cout << "Enter Time Slot (e.g., 4:00 PM): ";
            cin.ignore();
            getline(cin, newApp.timeSlot);

            newApp.status = "Confirmed";
            appointments.push_back(newApp);

            cout << "\n[Success] Appointment booked successfully! Your ID is: " << newApp.appointmentID << "\n";

        } else if (choice == 2) {
            // Doctor Portal
            cout << "\n--- Doctor Portal (Today's Schedule) ---\n";
            for (const auto& app : appointments) {
                cout << "ID: " << app.appointmentID << " | Patient: " << app.patientName
                     << " | Doctor: " << app.doctorName << " | Time: " << app.timeSlot << " | Status: " << app.status << "\n";
            }

        } else if (choice == 3) {
            // Admin Portal
            cout << "\n--- Admin / Receptionist Portal ---\n";
            double totalRevenue = 0;
            int confirmedCount = 0;

            for (const auto& app : appointments) {
                cout << "[" << app.appointmentID << "] " << app.patientName << " -> " << app.doctorName
                     << " (" << app.date << " at " << app.timeSlot << ") [" << app.status << "] - Fee: " << app.fee << " EGP\n";
                if (app.status == "Confirmed" || app.status == "Completed") {
                    totalRevenue += app.fee;
                }
                if (app.status == "Confirmed") {
                    confirmedCount++;
                }
            }
            cout << "\n-----------------------------------------\n";
            cout << "Total Appointments: " << appointments.size() << "\n";
            cout << "Confirmed Appointments: " << confirmedCount << "\n";
            cout << "Total Revenue Projections: " << totalRevenue << " EGP\n";
            cout << "-----------------------------------------\n";

        } else if (choice == 4) {
            cout << "\nExiting system. Thank you!\n";
        } else {
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

