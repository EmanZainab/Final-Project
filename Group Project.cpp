 #include <iostream>
using namespace std;
//       ADMIN MODULE
struct Bus {
    string name;
    string route;
    int seats;
    float fare;
    string schedule;
};
Bus buses[50];
int totalBuses = 0;

void addBus() {
    if (totalBuses >= 50) {
        cout<<"Cannot add more buses. Maximum limit reached"<<endl;
        return;
    }
    cout<<"Enter Bus Name:"<<endl;
    cin>>buses[totalBuses].name;
    cout<<"Enter Route:"<<endl;
    cin>>buses[totalBuses].route;
    cout<<"Enter Number of Seats:"<<endl;
    cin>>buses[totalBuses].seats;
    cout<<"Enter Fare per Ticket:"<<endl;
    cin>>buses[totalBuses].fare;
    cout<<"Enter Bus Schedule (Timing):"<<endl;
    cin>>buses[totalBuses].schedule;

    totalBuses++;
    cout << "Bus added successfully!"<<endl;
}

void displayBuses() {
    if (totalBuses == 0) {
        cout << "No buses available."<<endl;
        return;
    }
    for (int i = 0; i < totalBuses; i++) {
        cout<<"Bus ID: "<<i;
        cout<<"Name: "<<buses[i].name<<endl;
        
        
        cout<<"Route: "<<buses[i].route<<endl;
        cout<<"Seats: "<<buses[i].seats<<endl;
        
        
        
        cout<<"Fare: "<<buses[i].fare<<endl;
        cout<<"Schedule: "<< buses[i].schedule <<endl;
    }
}

void updateBus() {
    int id;
    cout << "Enter Bus ID to update: ";
    cin >> id;
    if (id < 0 || id >= totalBuses) {
        cout<<"Invalid Bus ID."<<endl;
        return;
    }

    cout << "Enter new Bus Name: ";
    cin >> buses[id].name;
    cout << "Enter new Route: ";
    
    
    
    cin >> buses[id].route;
    cout << "Enter new Number of Seats: ";
    cin >> buses[id].seats;
    cout << "Enter new Fare per Ticket: ";
    cin >> buses[id].fare;
    cout << "Enter new Bus Schedule (Timing): ";
    cin >> buses[id].schedule;
    
    
    

    cout<<"Bus updated successfully!"<<endl;
}

void deleteBus() {
    int id;
    cout << "Enter Bus ID to delete: ";
    cin >> id;
    if (id < 0 || id >= totalBuses) {
        cout<<"Invalid Bus ID."<<endl;
        return;
    }

    for (int i = id; i < totalBuses - 1; i++) {
        buses[i] = buses[i + 1];  
    }
    totalBuses--;
    cout << "Bus deleted successfully!\n";
}
void adminModule() {
    int choice;
    do {
        cout << "\n--- Admin Module ---\n";
        
        
        
        
        
        cout << "1. Add Bus\n2. Display Buses\n3. Update Bus\n4. Delete Bus\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please enter a number between 1-5.\n";
            continue;
        }

        switch(choice) {
            case 1: 
			addBus(); 
			break;
            case 2: 
			
			displayBuses();
			 break;
            case 3:
			 updateBus();
			 break;
            case 4: 
			deleteBus();
			 break;
            case 5:
			 cout << "Exiting...\n";
			 break;
        }
    } while(choice != 5);
}

//  CUSTOMER MODULE
struct Customer {
    string name;
    int age;
    int seat;
    string destination;
};

// Global array
Customer c[50];
int total = 0;

// ---------------- FUNCTION: BOOK TICKET ----------------
void bookTicket() {
    if (total >= 50) {
        cout << "All seats are booked."<<endl;
        return;
    }

    cout << "--- Book Ticket ---"<<endl;
    cout << "Enter Name: ";
    cin >> c[total].name;

    cout << "Enter Age: ";
    cin >> c[total].age;

    cout << "Enter Destination: ";
    cin >> c[total].destination;

    c[total].seat = total + 1;

    cout << "Ticket Booked Successfully!"<<endl;
    cout << "Your Seat Number: " << c[total].seat << endl;

    total++;
}

// ---------------- FUNCTION: VIEW BOOKINGS ----------------
void viewBookings() {
    if (total == 0) {
        cout << "No bookings yet"<<endl;
        return;
    }

    cout << "\n--- All Bookings ---\n";
    for (int i = 0; i < total; i++) {
        cout << "Name: " << c[i].name
             << "  Age: " << c[i].age
             << "  Destination: " << c[i].destination
             << "  Seat: " << c[i].seat << endl;
    }
}

// ---------------- FUNCTION: SEARCH BOOKING ----------------
void searchBooking() {
    int s;
    cout << "Enter Seat Number to Search: ";
    cin >> s;

    bool found = false;

    for (int i = 0; i < total; i++) {
        if (c[i].seat == s) {
            cout << "\n--- Booking Found ---\n";
            cout << "Name: " << c[i].name << endl;
            cout << "Age: " << c[i].age << endl;
            cout << "Destination: " << c[i].destination << endl;
            cout << "Seat: " << c[i].seat << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        
		
		cout << "No booking found for this seat.\n";
    }
}

void customerModule() {
    int choice;
   
    do {
        cout << "\n====== Customer Module ======\n";
        cout << "1. Book Ticket\n";
        cout << "2. View All Bookings\n";
        cout << "3. Search Booking\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookTicket();
                break;

            case 2:
                viewBookings();
                break;

            case 3:
                searchBooking();
                break;

            case 4:
                cout << "Exiting Customer Module...\n";
                break;

            default:
                cout << "Invalid Choice. Try Again!\n";
        }

    } while (choice != 4);
}

//     BOOKING MODULE
struct Booking {
    int bookingID;
    string customerName;
    string destination;
    int seatNumber;
};


// -------- GLOBAL ARRAY --------
Booking b[50];
int totalBookings = 0;

// -------- FUNCTION: ADD BOOKING --------
void addBooking() {
    if (totalBookings >= 50) {
        cout << "No more bookings available.\n";
        return;
    }

    cout << "\n--- Add Booking ---\n";
    cout << "Enter Booking ID: ";
    cin >> b[totalBookings].bookingID;

    cout << "Enter Customer Name: ";
    cin >> b[totalBookings].customerName;

    cout << "Enter Destination: ";
    cin >> b[totalBookings].destination;

   
   
   
   
    b[totalBookings].seatNumber = totalBookings + 1;

    cout << "Booking Done Successfully!\n";
    cout << "Seat Number: " << b[totalBookings].seatNumber << endl;

    totalBookings++;
}

// -------- FUNCTION: VIEW BOOKINGS --------
void ViewBookings() {
    if (totalBookings == 0) {
        cout << "No bookings available.\n";
        return;
    }

    cout << "\n--- All Bookings ---\n";
    for (int i = 0; i < totalBookings; i++) {
        cout << "Booking ID: " << b[i].bookingID
             << " | Name: " << b[i].customerName
             << " | Destination: " << b[i].destination
             << " | Seat: " << b[i].seatNumber << endl;
    }
}

// -------- FUNCTION: SEARCH BOOKING --------
void SearchBooking() {
    int id;
    cout << "Enter Booking ID to Search: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < totalBookings; i++) {
        if (b[i].bookingID == id) {
            cout << "\n--- Booking Found ---\n";
            cout << "Booking ID: " << b[i].bookingID << endl;
            cout << "Customer Name: " << b[i].customerName << endl;
            cout << "Destination: " << b[i].destination << endl;
            cout << "Seat Number: " << b[i].seatNumber << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Booking not found.\n";
    }
}

void bookingModule() {
    int choice;
      do {
        cout << "\n====== Booking System Module ======\n";
        cout << "1. Add Booking\n";
        cout << "2. View Bookings\n";
        cout << "3. Search Booking\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBooking();
                break;

            case 2:
                viewBookings();
                break;

            case 3:
                searchBooking();
                break;

            case 4:
                cout << "Exiting Booking System...\n";
                break;

            default:
                cout << "Invalid Choice! Try again.\n";
        }

    } while (choice != 4);
}

//    MAIN
int main() {
    int choice;
        cout << "________ WELCOME TO MY PROJECT_________"<<endl;
        cout<<" ________BUS TICKET BOOKING SYSTEM__________"<<endl;
        cout << "1. ADMIN MODULE"<<endl;
        cout << "2. CUSTOMER MODULE"<<endl;
        cout << "3. BOOKING MODULE"<<endl;
        cout << "4. EXIT"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice){
  case 1:
   adminModule();
  break;
  case 2:
   customerModule();
  break;
  case 3: bookingModule();
  break;
  case 4: cout<<"EXIT"<<endl;
  break;
  default: cout << "Invalid choice!"<<endl;
        }

    return 0;
}