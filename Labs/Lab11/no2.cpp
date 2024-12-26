#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Movie {
    string title;
    string date;
    vector<vector<bool>> availableSeats; // 2D vector representing seat availability
};

struct Reservation {
    string customerName;
    string movieTitle;
    string date;
    int round;
    int seatNumber;
};

void displaySchedule(const vector<Movie>& movies) {
    cout << "Movie Schedule:" << endl;
    for (const Movie& movie : movies) {
        cout << "Movie: " << movie.title << endl;
        cout << "Date: " << movie.date << endl;
        for (int i = 0; i < movie.availableSeats.size(); ++i) {
            cout << "Round " << (i + 1) << " - ";
            int availableSeats = 0;
            for (bool seat : movie.availableSeats[i]) {
                if (seat) availableSeats++;
            }
            cout << availableSeats << " seats available" << endl;
        }
        cout << endl;
    }
}

void makeReservation(vector<Movie>& movies) {
    displaySchedule(movies);

    int movieChoice, dateChoice, roundChoice, numSeats;
    cout << "Select a movie:" << endl;
    for (int i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ") " << movies[i].title << endl;
    }
    cout << "Enter movie number: ";
    cin >> movieChoice;

    cout << "Select a date:" << endl;
    for (int i = 0; i < movies[movieChoice - 1].availableSeats.size(); ++i) {
        cout << i + 1 << ") " << movies[movieChoice - 1].date << endl;
    }
    cout << "Enter date number: ";
    cin >> dateChoice;

    cout << "Select a round:" << endl;
    for (int i = 0; i < movies[movieChoice - 1].availableSeats.size(); ++i) {
        cout << i + 1 << ") Round " << i + 1 << " - ";
        int availableSeats = 0;
        for (bool seat : movies[movieChoice - 1].availableSeats[i]) {
            if (seat) availableSeats++;
        }
        cout << availableSeats << " seats left" << endl;
    }
    cout << "Enter round number: ";
    cin >> roundChoice;

    cout << "Enter the number of seats to reserve: ";
    cin >> numSeats;

    // Validation
    if (movieChoice < 1 || movieChoice > movies.size() ||
        dateChoice < 1 || dateChoice > movies[movieChoice - 1].availableSeats.size() ||
        roundChoice < 1 || roundChoice > movies[movieChoice - 1].availableSeats.size() ||
        numSeats < 1) {
        cout << "Invalid input. Reservation failed." << endl;
        return;
    }

    // Make reservation
    int selectedRound = roundChoice - 1;
    int availableSeats = 0;
    for (bool seat : movies[movieChoice - 1].availableSeats[selectedRound]) {
        if (seat) availableSeats++;
    }

    if (numSeats > availableSeats) {
        cout << "Not enough seats available. Reservation failed." << endl;
        return;
    }

    Reservation reservation;
    reservation.customerName = "John Doe"; // Placeholder, you can add input for customer name
    reservation.movieTitle = movies[movieChoice - 1].title;
    reservation.date = movies[movieChoice - 1].date;
    reservation.round = roundChoice;
    reservation.seatNumber = numSeats;

    // Update available seats
    for (int i = 0; i < numSeats; ++i) {
        for (int j = 0; j < movies[movieChoice - 1].availableSeats[selectedRound].size(); ++j) {
            if (movies[movieChoice - 1].availableSeats[selectedRound][j]) {
                movies[movieChoice - 1].availableSeats[selectedRound][j] = false;
                break;
            }
        }
    }

    cout << "Successfully reserved " << numSeats << " seats for " << reservation.movieTitle << " on "
         << reservation.date << " for round " << reservation.round << "." << endl;
}

int main() {
    // Sample data
    Movie movie1 = {"Poor Things", "2024-03-01", {{true, true, true, true, true}, {true, true, true, true, true}, 
                                         {true, true, true, true, true}, {true, true, true, true, true}}};

    Movie movie2 = {"เหมรย", "2024-03-02", {{true, true, true, true, true}, {true, true, true, true, true}, 
                                   {true, true, true, true, true}, {true, true, true, true, true}}};

    Movie movie3 = {"4KingsII", "2024-03-03", {{true, true, true, true, true}, {true, true, true, true, true}, 
                                     {true, true, true, true, true}, {true, true, true, true, true}}};
    
    vector <Movie> movies;
    movies.push_back(movie1);
    movies.push_back(movie2);
    movies.push_back(movie3);
    // vector<Movie> movies = {
    //     {"Poor Things", "2024-03-01", {{true, true, true, true, true}, {true, true, true, true, true}, 
    //                                      {true, true, true, true, true}, {true, true, true, true, true}}},
    //     {"เหมรย", "2024-03-02", {{true, true, true, true, true}, {true, true, true, true, true}, 
    //                                {true, true, true, true, true}, {true, true, true, true, true}}},
    //     {"4KingsII", "2024-03-03", {{true, true, true, true, true}, {true, true, true, true, true}, 
    //                                  {true, true, true, true, true}, {true, true, true, true, true}}}
    // };

    int choice;
    do {
        cout << "\n1. View Schedule\n2. Make Reservation\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displaySchedule(movies);
                break;
            case 2:
                makeReservation(movies);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
