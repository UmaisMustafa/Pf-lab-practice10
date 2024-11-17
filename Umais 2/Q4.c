#include <stdio.h>
#include <string.h>


struct Flight {
    char flightNumber[20];
    char departureCity[50];
    char arrivalCity[50];
    char departureTime[20];
    char arrivalTime[20];
    int availableSeats;
};


void bookSeat(struct Flight* flight) {
    if (flight->availableSeats > 0) {
        flight->availableSeats--;
        printf("Seat booked on flight %s\n", flight->flightNumber);
    } else {
        printf("No available seats on flight %s\n", flight->flightNumber);
    }
}


void displayAvailableFlights(struct Flight* flights, int flightCount, const char* departure, const char* arrival) {
    int found = 0;
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].departureCity, departure) == 0 && strcmp(flights[i].arrivalCity, arrival) == 0) {
            printf("Flight %s from %s to %s\n", flights[i].flightNumber, flights[i].departureCity, flights[i].arrivalCity);
            printf("Departure: %s, Arrival: %s, Available Seats: %d\n", flights[i].departureTime, flights[i].arrivalTime, flights[i].availableSeats);
            found = 1;
        }
    }
    if (!found) {
        printf("No flights available from %s to %s.\n", departure, arrival);
    }
}

void updateFlightDetails(struct Flight* flight, const char* departureTime, const char* arrivalTime, int availableSeats) {
    
    strcpy(flight->departureTime, departureTime);
    strcpy(flight->arrivalTime, arrivalTime);
    flight->availableSeats = availableSeats;

   
    printf("Updated flight %s details:\n", flight->flightNumber);
    printf("Departure Time: %s, Arrival Time: %s, Available Seats: %d\n", flight->departureTime, flight->arrivalTime, flight->availableSeats);
}

int main() {
    struct Flight flights[100];
    int flightCount = 0;

    
    strcpy(flights[flightCount].flightNumber, "AA101");
    strcpy(flights[flightCount].departureCity, "New York");
    strcpy(flights[flightCount].arrivalCity, "Los Angeles");
    strcpy(flights[flightCount].departureTime, "2024-12-01 08:00");
    strcpy(flights[flightCount].arrivalTime, "2024-12-01 11:00");
    flights[flightCount].availableSeats = 50;
    flightCount++;

    strcpy(flights[flightCount].flightNumber, "BB202");
    strcpy(flights[flightCount].departureCity, "New York");
    strcpy(flights[flightCount].arrivalCity, "Chicago");
    strcpy(flights[flightCount].departureTime, "2024-12-01 09:00");
    strcpy(flights[flightCount].arrivalTime, "2024-12-01 12:00");
    flights[flightCount].availableSeats = 30;
    flightCount++;

    
    printf("Available flights from New York to Los Angeles:\n");
    displayAvailableFlights(flights, flightCount, "New York", "Los Angeles");

    bookSeat(&flights[0]);

    
    updateFlightDetails(&flights[1], "2024-12-01 10:00", "2024-12-01 13:00", 25);

   
    printf("\nUpdated available flights from New York to Chicago:\n");
    displayAvailableFlights(flights, flightCount, "New York", "Chicago");

    return 0;
}

