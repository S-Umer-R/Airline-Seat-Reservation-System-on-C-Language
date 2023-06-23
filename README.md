# Airline Seat Reservation System

This is a simple console-based Airline Seat Reservation System written in C. It allows users to book seats, cancel bookings, view passenger details, and search for specific passenger records. The system is designed to handle both business class and economy class bookings.

## How to Use

1. Compile the source code using a C compiler.
2. Run the compiled executable to start the program.
3. The program will display a menu with options to book a seat, cancel a seat, view passenger details, search passenger records, or exit the program.
4. Select the desired option by entering the corresponding letter (A-E).
   - Option A: Book Seat - Follow the prompts to enter passenger details, such as name, payment method, and flight type. The program will assign a booking ID and display the total cost of the flight.
   - Option B: Cancel Seat - Enter the name of the passenger whose booking you want to cancel. The program will remove the passenger's record from the system.
   - Option C: Details of the passenger - Displays the details of all passengers, including their names, payment methods, flight types, and costs.
   - Option D: Search Passenger Record - Enter the name of the passenger you want to search for. The program will display the passenger's details if found.
   - Option E: Exit - Terminate the program.
5. After completing an operation, you can choose another option or exit the program.

## File Organization

The program uses a file, `detail.dat`, to store passenger records. The file is created if it doesn't exist. When booking a seat, passenger details are written to this file. When canceling a seat, the corresponding record is removed from the file.
