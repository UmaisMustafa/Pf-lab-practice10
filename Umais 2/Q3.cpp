#include <stdio.h>
#include <string.h>


struct Book {
    char title[100];
    char author[100];
    char ISBN[20];
    int publicationYear;
    int isAvailable; 
};


void addBook(struct Book* library, int* bookCount, const char* title, const char* author, const char* ISBN, int year) {
    struct Book newBook;
    strcpy(newBook.title, title);
    strcpy(newBook.author, author);
    strcpy(newBook.ISBN, ISBN);
    newBook.publicationYear = year;
    newBook.isAvailable = 1; 

    library[*bookCount] = newBook;
    (*bookCount)++;
}

void searchBook(struct Book* library, int bookCount, const char* query) {
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].author, query)) {
            printf("Found book: %s by %s (ISBN: %s, Year: %d)\n", library[i].title, library[i].author, library[i].ISBN, library[i].publicationYear);
        }
    }
}

void updateAvailability(struct Book* library, int bookCount, const char* ISBN, int availability) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].ISBN, ISBN) == 0) {
            library[i].isAvailable = availability;
            printf("Updated availability for book with ISBN %s\n", ISBN);
            return;
        }
    }
    printf("Book not found!\n");
}

int main() {
    struct Book library[100];
    int bookCount = 0;

    
    addBook(library, &bookCount, "The C Programming Language", "Brian W. Kernighan", "978-0131103627", 1978);
    addBook(library, &bookCount, "The Pragmatic Programmer", "Andrew Hunt", "978-0201616224", 1999);

    
    searchBook(library, bookCount, "C Programming");

    
    updateAvailability(library, bookCount, "978-0131103627", 0); 

    return 0;
}

