# Hospital Management System (HMS)

## Overview
The Hospital Management System is a C++ console application designed to manage patient records, doctor information, appointments, and billing in a healthcare facility. The system stores all data in a CSV file for persistent record-keeping.

## Features
- Patient Management
  - Record patient personal details
  - Track health issues and medical history
  - Store previous surgery information
  - Manage treatment types

- Doctor Management
  - Store doctor profiles
  - Track specializations
  - Record years of experience

- Appointment System
  - Schedule appointments
  - Link patients with doctors
  - Record appointment date and time

- Billing System
  - Calculate consultation fees
  - Track treatment costs
  - Manage medication expenses
  - Automatic tax calculation

## Technical Implementation
- **Object-Oriented Design**: Uses inheritance with a base `Person` class and derived `Patient` and `Doctor` classes
- **Exception Handling**: Custom `HMSException` class for error management
- **File Handling**: CSV file storage for data persistence
- **Input Validation**: Basic validation for user inputs
- **Modular Structure**: Separate classes for different functionalities

## Dependencies
- C++ Standard Library
- `<bits/stdc++.h>`
- `<fstream>` for file operations

## File Structure
- `hospital_data.csv`: Stores all the system data in CSV format with the following columns:
  ```
  Patient Name, Patient Age, Gender, Health Issue, Previous Surgery, Treatment Type,
  Doctor Name, Doctor Age, Specialization, Experience, Appointment Date, 
  Appointment Time, Consultation Fee, Treatment Cost, Medication Cost, Tax Rate,
  Total Amount
  ```

## How to Use

### Compilation
```bash
g++ hospital_management.cpp -o hospital_management
```

### Running the Program
```bash
./hospital_management
```

### Data Entry Process
1. **Patient Information**
   - Enter patient name (or 'exit' to quit)
   - Enter age
   - Enter gender (Male/Female)
   - Enter health issue
   - Enter previous surgery details
   - Enter treatment type

2. **Doctor Information**
   - Enter doctor name
   - Enter age
   - Enter specialization
   - Enter years of experience

3. **Appointment Details**
   - Enter date (DD-MM-YYYY format)
   - Enter time (e.g., 11:00 AM)

4. **Billing Information**
   - Enter consultation fee
   - Enter treatment cost (if applicable)
   - Enter medication cost (if applicable)
   - Enter tax rate (e.g., 0.05 for 5%)

## Error Handling
- The system includes exception handling for:
  - File operations
  - Invalid input data
  - Runtime errors
- Errors are logged to standard error (cerr)

## Data Storage
- All data is automatically saved to `hospital_data.csv`
- The CSV file is created if it doesn't exist
- Headers are automatically added to empty files
- Data is appended to existing files

## Best Practices
- Always enter dates in DD-MM-YYYY format
- Use 12-hour format for time entries
- Enter tax rates as decimals (e.g., 0.05 for 5%)
- Keep the CSV file in the same directory as the executable


## Future Improvements
1. Add data modification capabilities
2. Implement user authentication
3. Enhanced input validation
4. Database integration
5. Graphical user interface
6. Appointment scheduling system
7. Report generation
8. Data backup functionality

## Contributing
Feel free to fork this project and submit pull requests for any improvements you'd like to add.
