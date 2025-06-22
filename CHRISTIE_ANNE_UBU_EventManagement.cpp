#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_ATTENDEES 40
#define TICKET_PRICE 50.00

// Function Prototypes
void registerAttendees(string names[], string phoneNumbers[], int totalAttendees);
string chooseSession();
string assignEmcee();
double processTotalPayment(int totalAttendees);
void generateAttendeeList(string names[], string phoneNumbers[], int totalAttendees, string eventSession, string eventSpeaker);

int main() {
    cout << setfill('*') << setw(70) << "*" << endl;
    cout << "\t~~ WELCOME TO OUR EVENT HORIZON ~~" << endl;
    cout << setfill('*') << setw(70) << "*" << endl;
    
    char choice; 

    do {
        int totalAttendees;
        string names[MAX_ATTENDEES];
        string phoneNumbers[MAX_ATTENDEES];
        
        
        do {
		cout << "\nEnter number of attendees (Max " << MAX_ATTENDEES << "): ";
        cin >> totalAttendees;

            if (totalAttendees > MAX_ATTENDEES)
		    {
              cout << "\nERROR: Maximum number of attendees is " << MAX_ATTENDEES << ". Please try again.\n";
            }
            else if (totalAttendees < 0)
		    { 
		      cout<<"\nERROR: Number of attendees cannot be negative. Please try again.\n";
		    } 
		    
        }while (totalAttendees > MAX_ATTENDEES || totalAttendees <= 0);

        registerAttendees(names, phoneNumbers, totalAttendees);
        string eventSession = chooseSession();
        string eventSpeaker = assignEmcee();
        double totalPayment = processTotalPayment(totalAttendees);
        generateAttendeeList(names, phoneNumbers, totalAttendees, eventSession, eventSpeaker);
        
        do{ 
            cout << "\nWould you like to register again? (y/n): ";
			cin >> choice;
			
			if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
			{ 
			cout<<"Invalid input! Please enter again.";
			}
			
        }while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

    } while (choice == 'y' || choice == 'Y');

    cout << "\nGoodbye!\n";
    return 0;
}

//Function to register attendees
void registerAttendees(string names[], string phoneNumbers[], int totalAttendees) {
    cout << "\nPlease Register The Attendees\n";
    
    cin.ignore();
    
    for (int i = 0; i < totalAttendees; i++) {
        cout << "\nEnter details for Attendee " << i + 1 << ":\n";
        
        cout << "Enter Full Name: ";
        getline(cin, names[i]);

        cout << "Enter Telephone Number: ";
        getline(cin, phoneNumbers[i]);
    }
    cout << "\nAll attendees registered successfully!\n";
}

//Function to choose event session
string chooseSession() {
	int choice;
	 
	do {
    cout << "\nChoose a session for the event:\n";
    cout << "1. Morning (10 AM - 12 PM)\n";
    cout << "2. Afternoon (2 PM - 4 PM)\n";
    cout << "3. Evening (6 PM - 8 PM)\n";
    cout << "Enter session choice (1/2/3): ";
    cin >> choice;
    
    if(choice < 1 || choice > 3){ 
      cout<<"\nInvalid choice. Please enter 1/2/3.\n";
    } 
	} while (choice < 1 || choice > 3);
	
	if (choice == 1)
    {
        return "Morning (10AM-12PM)";
    } 
        else if (choice == 2)
    {
        return "Afternoon (2PM-4PM)";
    }
        else
    {
        return "Evening (6PM-8PM)";
    } 
} 

//Function to assign event speaker
string assignEmcee() {
    string eventSpeaker;
    cin.ignore();
    cout << "\nEnter the name of the Event Speaker: ";
    getline(cin,eventSpeaker);
    
    return eventSpeaker;
}

//Function to process total payment
double processTotalPayment(int totalAttendees) {
    double totalPayment = totalAttendees * TICKET_PRICE;
    cout << fixed << setprecision(2);
    cout << "\nTotal payment required: RM " << totalPayment << "\n";

    int paymentMethod;
    do {
        cout << "\nChoose your payment method:\n";
        cout << "1. QR Code\n";
        cout << "2. Online Transfer\n";
        cout << "Enter your choice (1/2): ";
        cin >> paymentMethod;

        if (paymentMethod != 1 && paymentMethod != 2) {
            cout << "Invalid choice. Please select 1 or 2.\n";
        }
    } while (paymentMethod != 1 && paymentMethod != 2);

    if (paymentMethod == 1) {
        cout << "\n[QR PAYMENT SIMULATION]\n";
        cout << "Please scan the QR code displayed on your device to pay RM " << totalPayment << ".\n";
        cout << "Processing...\n";
    } 
    else if (paymentMethod == 2) {
        cout << "\n[ ONLINE TRANSFER ]\n";
        cout << "Please transfer the total amount to the following account:\n";
        cout << "-------------------------------------------\n";
        cout << "Bank Name   : Maybank\n";
        cout << "Account Name: EVENT HORIZON\n";
        cout << "Account No. : 1234 5678 9012\n";
        cout << "-------------------------------------------\n";
        cout << "Kindly ensure the correct amount is transferred: RM " << totalPayment << "\n";
    }

    double paymentAmount;
    cout << "\nEnter the amount you have paid: RM ";
    cin >> paymentAmount;

    while (paymentAmount < totalPayment) {
        cout << "Insufficient payment! Please enter at least RM " << totalPayment << ".\n";
        cout << "Enter the amount you have paid: RM ";
        cin >> paymentAmount;
    }

    double change = paymentAmount - totalPayment;
    cout << "Payment successful!\n";

    if (change > 0) {
        cout << "Change to be given: RM " << change << "\n";
    }

    return totalPayment;
}


//Function to generate attendee list
void generateAttendeeList(string names[], string phoneNumbers[], int totalAttendees, string eventSession, string eventSpeaker) {
	
    cout << "\n" << setfill('=') << setw(50) << "="  << "\n";
    cout << setfill(' ') << setw(31) << "ATTENDEE LIST" << "\n";
    cout << setfill('=') << setw(50) << "="  << "\n";
    cout << "Event Session: " << eventSession << "\n";
    cout << "Event Speaker (Emcee): " << eventSpeaker << "\n";
    cout << setfill('-') << setw(50) << " "  << "\n";
    
    cout<<setfill(' '); //Reset the fill into space
    cout << "No." << "\t" << left << setw(20) << "Name" << "\t" << "Phone Number" << "\n";
    cout << setfill('-') << setw(50) << "-" << "\n";
    
    // Rows for data 
    cout<<setfill(' '); //Reset the fill into space
	for (int i = 0; i < totalAttendees; i++) {
    cout << (i + 1) << ".\t" << setw(20) << names[i] << "\t" << phoneNumbers[i] << "\n";
	} 
        
    cout << setfill('-') << setw(50) << "-"  << "\n";

//Ask user for feedback
int feedback;
cout << "\nPlease rate our event (1 to 5 stars): ";
cin >> feedback;

switch (feedback) {
    case 5:
        cout << "\nExcellent! Thank you for the 5-star rating ^^ ! \n";
        break;
    case 4:
        cout << "\nGreat! We're glad you enjoyed it! :)\n";
        break;
    case 3:
        cout << "\nYay! We appreciate your support. \n";
        break;
    case 2:
        cout << "\nNoted! We'll work harder to improve. \n";
        break;
    case 1:
        cout << "\nSorry to hear that. We appreciate your honesty. :( \n";
        break;
    default:
        cout << "\nInvalid rating. Please rate between 1 to 5!\n";
}


    cout << "\nThank you for your feedback :) !\n";
}
