#include <bits/stdc++.h>
#include<fstream>
using namespace std;

// Exception class for handling errors
class HMSException : public runtime_error {
public:
    HMSException(const string& message) : runtime_error(message) {}
};

// Base class for Person
class Person {
protected:
    string name;
    int age;
public:
    Person(const string& n, int a) : name(n), age(a) {}
    virtual void display() const = 0; // Pure virtual function
};

// Derived class for Patient
class Patient : public Person {
private:
    string healthIssue, previousSurgery, gender, treatmentType;
public:
    Patient(const string& n, int a, const string& h, const string& p, const string& g, const string& t)
        : Person(n, a), healthIssue(h), previousSurgery(p), gender(g), treatmentType(t) {}

    void display() const override {
        cout << "Patient Name: " << name << "\nAge: " << age << "\nGender: " << gender
             << "\nHealth Issue: " << healthIssue << "\nPrevious Surgery: " << previousSurgery
             << "\nTreatment Type: " << treatmentType << "\n" << endl;
    }
};

// Derived class for Doctor
class Doctor : public Person {
private:
    string specialization;
    int experience;
public:
    Doctor(const string& n, int a, const string& s, int e)
        : Person(n, a), specialization(s), experience(e) {}

    void display() const override {
        cout << "Doctor Name: " << name << "\nAge: " << age 
             << "\nSpecialization: " << specialization 
             << "\nExperience: " << experience << " years\n" << endl;
    }
};

// Class for Billing
class Billing {
private:
    double consultationFee, treatmentCost, medicationCost;
public:
    Billing(double cFee, double tCost = 0.0, double mCost = 0.0)
        : consultationFee(cFee), treatmentCost(tCost), medicationCost(mCost) {}

    double calculateTotal(double taxRate) const {
        return (consultationFee + treatmentCost + medicationCost) * (1 + taxRate);
    }

    void displayBill() const {
        cout << "Consultation Fee: Rs" << fixed << setprecision(2) 
             << consultationFee << "\nTreatment Cost: Rs" 
             << treatmentCost << "\nMedication Cost: Rs" 
             << medicationCost << endl;
    }
};

// Class for Appointment
class Appointment {
private:
    Patient patient;
    Doctor doctor;
    Billing billing;
    string date, time;
public:
    Appointment(const Patient& p, const Doctor& d, const Billing& b, const string& dt, const string& tm)
        : patient(p), doctor(d), billing(b), date(dt), time(tm) {}

    void display() const {
        cout<<"--------------------------------------------------------"<<endl;
        cout << "Appointment Details:\n";
        patient.display();
        doctor.display();
        cout << "Date: " << date << "\nTime: " << time << "\n" << endl;
        
        cout << "--- Billing Information ---" << endl;
        billing.displayBill();
        cout << endl;
    }
};

// Main function for user input
int main() {
    try {
        // Open the file in append mode
    ofstream file("hospital_data.csv", ios::app);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return -1;
    }

    // Add a header to the CSV file if it is empty
    ifstream infile("hospital_data.csv");
    bool isEmpty = infile.peek() == EOF;
    infile.close();

    if (isEmpty) {
        file << "Patient Name,Patient Age,Gender,Health Issue,Previous Surgery,Treatment Type,"
            << "Doctor Name,Doctor Age,Specialization,Experience,Appointment Date,Appointment Time,"
            << "Consultation Fee,Treatment Cost,Medication Cost,Tax Rate,Total Amount\n";
    }

        while (true) { // Loop to allow multiple entries
            string patientName, healthIssue, previousSurgery, gender, treatmentType;
            int patientAge;

            cout << "\n--- Enter Patient Details ---\n";
            cout << "Enter Patient Name (or type 'exit' to quit): ";
            getline(cin, patientName);
            if (patientName == "exit") exit(0); // Exit condition

            cout << "Enter Patient Age: ";
            cin >> patientAge;
            cin.ignore();
            cout << "Enter Patient Gender[Male/Female]: ";
            getline(cin, gender);
            cout << "Enter Health Issue: ";
            getline(cin, healthIssue);
            cout << "Enter Previous Surgery (or 'None'): ";
            getline(cin, previousSurgery);
            cout << "Enter Treatment Type (Checkup/Operation): ";
            getline(cin, treatmentType);

            Patient patient(patientName, patientAge, healthIssue, previousSurgery, gender, treatmentType);

            // Input doctor details
            string doctorName, specialization;
            int doctorAge, experience;
            cout << "\n--- Enter Doctor Details ---\n";
            cout << "Enter Doctor Name: ";
            getline(cin, doctorName);
            cout << "Enter Doctor Age: ";
            cin >> doctorAge;
            cin.ignore();
            cout << "Enter Doctor Specialization: ";
            getline(cin, specialization);
            cout << "Enter Doctor Experience (in years): ";
            cin >> experience;

            Doctor doctor(doctorName, doctorAge, specialization, experience);

            // Input appointment details
            string date, time;
            cout << "\n--- Enter Appointment Details ---\n";
            cout << "Enter Appointment Date (DD-MM-YYYY): ";
            cin >> date;
            cout << "Enter Appointment Time (e.g., 11:00 AM): ";
            cin.ignore();
            getline(cin, time);

            // Input billing details
            double consultationFee = 0.0, treatmentCost = 0.0, medicationCost = 0.0, taxRate = 0.0;
            cout << "\n--- Enter Billing Details ---\n";
            cout << "Enter Consultation Fee: Rs ";
            cin >> consultationFee;
            cout << "Enter Treatment Cost (default is 0 if not applicable): Rs ";
            cin >> treatmentCost;
            cout << "Enter Medication Cost (default is 0 if not applicable): Rs ";
            cin >> medicationCost;
            cout << "Enter Tax Rate (e.g., 0.05 for 5%): ";
            cin >> taxRate;

            Billing bill(consultationFee, treatmentCost, medicationCost);

            Appointment appointment(patient, doctor, bill, date, time);
            appointment.display();

            double totalAmount = bill.calculateTotal(taxRate);
            cout << "Total Amount (including tax): Rs" 
                 << fixed 
                 << setprecision(2) 
                 << totalAmount 
                 << endl;

            // --- Write data to the file ---
            file << patientName << "," << patientAge << "," << gender << ","
                 << healthIssue << "," << previousSurgery << "," << treatmentType << ","
                 << doctorName << "," << doctorAge << "," << specialization << "," << experience << ","
                 << date << "," << time << ","
                 << consultationFee << "," << treatmentCost << "," << medicationCost << ","
                 << taxRate << "," << totalAmount << "\n";

            file.close();
        }

    } catch (const HMSException& e) {
        cerr << e.what() << "\n"; // Catching any HMS exceptions that may occur.
    } catch (const exception& e) {
        cerr << e.what() << "\n"; // Catching standard exceptions.
    }

    return 0;
}
