#include <iostream>
#include <string>
using namespace std;

//VALIDATION of time slot FUNCTION //
void T_Valid() {
    bool t_valid = true;
    do
    {
//INITIALIZATION OF THE TIME SLOT ARRAY AND INPUT VARIABLE//
        string const TRAVEL_TIMES[5][10] = {{"1.\t07:00",   "\t09:30"},
                                            {"\n2.\t09:00", "\t11:30"},
                                            {"\n3.\t11:00", "\t13:30"},
                                            {"\n4.\t13:00", "\t15:30"},
                                            {"\n5.\t15:00", "\t17:30"}};
        int time_Slot;
//Displays the array that stored the departure times//
        cout << "Available Departure times:\n";
        cout << "\tArive\tDepart\n\n";
//COUNTER THAT DISPLAYS THE ARRAY STORING THE DEPARTURE TIMES//
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 10; y++) {
                cout << TRAVEL_TIMES[x][y];
            }
        }
//PROMTS THE USER TO SELECT A TIME SLOT//
        cout << "\nPlease select on of the available times(e.g. 3):";
        cin >> time_Slot;
//VALIDATES THE SELECTED TIME SLOT INPUT//
        if (time_Slot > 0 && time_Slot < 6) {
            cout << "Thank you for your selection!\n";
            t_valid = true;
        } else {
            cout << "Invalid selection!\n";
            t_valid = false;
        }
    } while (t_valid != true);
}

//FUNCTION TO DISPLAY SEATS//
void SeatMaker()
{
/*ARRAY FOR SEATING STRUCTURE; THERE ARE 15 POSITIONS PER K'TH ELEMENT & 4 POSITIONS PER J'TH ELEMENT*/
    string first_class[4][15] = {{"|","A1","|","A2","|","A3","|","---","|","A4","|","A5","|","A6|","\n"},{"|","B1","|","B2","|","B3","|","---","|","B4","|","B5","|","B6|","\n"},{"|","C1","|","C2","|","C3","|","---","|","C4","|","C5","|","C6|","\n"},{"|","D1","|","D2","|","D3","|","---","|","D4","|","D5","|","D6|","\n"}};
    string economy_class[4][15] = {{"|","E1","|","E2","|","E3","|","---","|","E4","|","E5","|","E6|","\n"},{"|","F1","|","F2","|","F3","|","---","|","F4","|","F5","|","F6|","\n"},{"|","G1","|","G2","|","G3","|","---","|","G4","|","G5","|","G6|","\n"},{"|","H1","|","H2","|","H3","|","---","|","H4","|","H5","|","H6|","\n"}};
    string last_row[5] = {"|","I1","|","I2","|\n"};

//CALCULATION OF SEAT PRICE//
    float const PRICE_ECONOMY = 1600.00;
    float const PRICE_FIRST_CLASS = PRICE_ECONOMY*0.2 + 1600.00;

//Outputs to the console, the array containing the seat structure for first class//
    cout << "First Class" << "(R" << PRICE_FIRST_CLASS << ")\n";
    for(int j = 0; j<4 ; j++)
    {
        for (int k = 0; k < 15; k++)
        {
            cout << first_class[j][k];
        }
    }
//OUTPUTS THE  ARRAY CONTAINING THE SEAT STRUCTURE FOR THE ECONOMY CLASS//
    cout <<"\nEconomy Class" << "(R" << PRICE_ECONOMY << ")\n";
    for(int b = 0; b<4; b++)
    {
        for(int c = 0; c<15; c++)
        {
            cout << economy_class[b][c];
        }
    }
//OUTPUTS THE ARRAY CONTAINING THE SEAT STRUCTURE OF THE LAST ROW OF ECONOMY CLASS//
    for(int a = 0; a <5; a++)
    {
        cout << last_row[a];
    }

//CUSTOMER SEAT SELECTION AND ALTERATION OF THE SEATING ARRAY//
    char seat_row = 'Z';
    int seat_column = 0;
    int seat_row_converted = 0;
    cout << "\nPlease make a row selection ~ e.g. A: ";
    cin >> seat_row;
    seat_row = toupper(seat_row);

    cout << "\nNow Please select a column ~ e.g 2: ";
    cin >> seat_column;

    switch (seat_row)
    {
        case 'A': {
            seat_row_converted = 0;
            break;
        }

        case 'B': {
            seat_row_converted = 1;
            break;
        }

        case 'C':{
            seat_row_converted = 2;
            break;
        }

        case 'D': {
            seat_row_converted = 3;
            break;
        }

        case 'E':{
            seat_row_converted = 0;
            break;
        }

        case 'F':{
            seat_row_converted = 1;
            break;
        }

        case'G':{
            seat_row_converted = 2;
            break;
        }

        case 'H':{
            seat_row_converted = 3;
            break;
        }

        default:
            cout << "\nInvalid input";
            break;
    }

    first_class[seat_row_converted][seat_column] = "**";
    cout << "First Class" << "(R" << PRICE_FIRST_CLASS << ")\n";
    for(int j = 0; j<4 ; j++)
    {
        for (int k = 0; k < 15; k++)
        {
            cout << first_class[j][k];
        }
    }


}




int main()
{
    char booking_choice = 'O';
    do
    {
        string fullname;    //initialising the string `fullname`//
//Welcome message and stores the users fullname as a string//

        cout << "Welcome to COS1511 Flight Booking Systems\n";
        cout << "Please enter your fullname:\n";
        getline(cin, fullname);
        cout << endl;

//VALIDATION OF TIME SLOT//
        T_Valid();
        cout << endl;
//DISPLAYS THE SEAT SELECTION//
        SeatMaker();


        cout << "\nWould you like to make another booking?(Y/N): ";
        cin >> booking_choice;
        booking_choice = toupper(booking_choice);
    }
    while(booking_choice != 'N');


    return 0;
}
