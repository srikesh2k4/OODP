#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_TRAINS 3
#define MAX_SEATS_PER_TRAIN 50
#define MAX_NAME_LENGTH 50

// Train structure to store train information
struct Train {
    char name[50];
    int availableSeats;
};

// Passenger structure to store passenger information
struct Passenger {
    char name[MAX_NAME_LENGTH];
    int age;
};

// Function to display available trains
void displayTrains(struct Train trains[]) {
    printf("Available Trains:\n");
    for (int i = 0; i < MAX_TRAINS; ++i) {
        printf("%d. %s (Available Seats: %d)\n", i + 1, trains[i].name, trains[i].availableSeats);
    }
}

// Function to select a train
int selectTrain() {
    int choice;
    printf("Enter the number corresponding to the train you want to book: ");
    scanf("%d", &choice);
    return choice - 1; // Adjust for array index
}

// Function to enter passenger details
struct Passenger enterPassengerDetails() {
    struct Passenger passenger;
    printf("Enter passenger name: ");
    scanf("%s", passenger.name);
    printf("Enter passenger age: ");
    scanf("%d", &passenger.age);
    return passenger;
}

// Function to book tickets
void bookTicket(struct Train trains[], int trainChoice, struct Passenger passenger) {
    if (trainChoice >= 0 && trainChoice < MAX_TRAINS && trains[trainChoice].availableSeats > 0) {
        printf("\nBooking successful! Enjoy your journey.\n");
        printf("Passenger Details:\n");
        printf("Name: %s\n", passenger.name);
        printf("Age: %d\n", passenger.age);
        printf("Train: %s\n", trains[trainChoice].name);
        printf("Seat Number: %d\n", MAX_SEATS_PER_TRAIN - trains[trainChoice].availableSeats + 1);

        // Decrease the number of available seats
        trains[trainChoice].availableSeats--;
    } else {
        printf("\nSorry, the selected train is not available or has no more seats.\n");
    }
}

int main() {
    int trainChoice;
    struct Passenger passenger;

    struct Train trains[MAX_TRAINS] = {
        {"Express 123", MAX_SEATS_PER_TRAIN},
        {"Rapid 456", MAX_SEATS_PER_TRAIN},
        {"Local 789", MAX_SEATS_PER_TRAIN}
    };

    printf("Welcome to the Train Ticket Booking System!\n");

    // Display available trains
    displayTrains(trains);

    // Select a train
    trainChoice = selectTrain();

    // Enter passenger details
    passenger = enterPassengerDetails();

    // Book ticket
    bookTicket(trains, trainChoice, passenger);

    return 0;
}
