#include<bits/stdc++.h>
using namespace std;
const int number_of_rows = 7;
const int number_of_seats = 10;
struct Seat* head_seats[number_of_rows+10];
struct Seat{
    int seat_row, seat_number;
    bool is_booked;
    string booked_to;
    struct Seat *prev;
    struct Seat *next;
};

void list_available(struct Seat *Head){
    cout << endl << "Available Seats" << endl;
    struct Seat *is_available = (struct Seat*)malloc(sizeof(struct Seat));
    is_available = Head;
    while(is_available->next!=Head){
        if(is_available->is_booked== false){
            cout << "Seat Row: " << is_available->seat_row << " Seat Number: " << is_available->seat_number << endl;
            is_available = is_available->next;
        }
        else if(is_available->is_booked== true){
            is_available = is_available->next;
        }

    }
    if(!is_available->is_booked){
        cout << "Seat Row: " << is_available->seat_row << " Seat Number: " << is_available->seat_number << endl << endl;
    }
}
bool book_seat(int row_number, int seat_number, string booking_name){

    struct Seat *traverser;
    traverser = head_seats[row_number];
    while (traverser->seat_row==row_number){
        if(seat_number == traverser->seat_number) {
            if (!traverser->is_booked) {
                traverser->is_booked = true;
                traverser->booked_to = booking_name;
                cout << endl << "Seat booked successfully. \nBooking Details:"<<endl<<"\tSeat Row: "<<traverser->seat_row<<" Seat Number: "<<traverser->seat_number<<endl<<"\tBooking Name: " << traverser->booked_to<<endl<<"Thank You for purchasing ticket!"<<endl << endl;
                return true;
            } else {
                cout << "Seat already booked." << endl;
                return false;
            }
        }
        else{
            traverser = traverser->next;
        }
    }
    cout << "Seat not found." << endl;
    return false;
}
int main(){
    struct Seat *Head;
    Head=NULL;
    for(int row_number = 1; row_number <= number_of_rows; row_number++){
        for(int seat_number = 1; seat_number <= number_of_seats; seat_number++){
            struct Seat *temp = (struct Seat*)malloc(sizeof(struct Seat));
            temp->seat_number = seat_number;
            temp->seat_row = row_number;
            temp->is_booked = false;
            if(seat_number==1){
                head_seats[row_number] = temp;
            }

            if(Head==NULL){
                Head=temp;
                temp->next=Head;
                temp->prev=Head;
            }

            else{
                struct Seat *previous_seat = (struct Seat*)malloc(sizeof(struct Seat));
                previous_seat = Head;
                while(previous_seat->next!=Head){
                    previous_seat=previous_seat->next;
                }
                previous_seat->next=temp;
                temp->prev=previous_seat;
                Head->prev=temp;
                temp->next=Head;
            }
        }
    } //DCLL Created for all seats
    while(true){
        int choice;
        cout << "Welcome to Cinemax Ticket Booking Software" << endl << "Please Enter 1 to List out available seats." << endl << "Please Enter 2 to Book a seat." << endl << "Please Enter 3 to Cancel a seat." << endl << "Please Enter 4 to Exit." << endl << " >";
        cin >> choice;
        if(choice==4){
            exit(0);
        }
        else if(choice==1){
            list_available(Head);
        }
        else if(choice==2){
            int row_number, seat_number;
            string booked_to;
            cout << endl << "Please Enter Row Number of Interested Seat >";
            cin >> row_number;
            cout << endl << "Please Enter Seat Number of Interested Seat >";
            cin >> seat_number;
            cout << endl << "Please Enter Your Name > ";
            cin >> booked_to;
            if(row_number > number_of_rows || seat_number > number_of_seats){
                cout << "Error - Request of Unavailable Seat" << endl << "Please Re-check Seat credentials" << endl;
                continue;
            }
            else{
                book_seat(row_number, seat_number, booked_to);
            }
        }

    }

}
