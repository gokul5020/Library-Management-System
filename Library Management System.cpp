#include <stdio.h>
#include <string.h>
// Structure to hold book details
struct Book {
 char book_name[100];
 char author_name[100];
 float cost;
 int no_of_pages;
};
// Hardcoded login credentials
#define USERNAME "admin"
#define PASSWORD "password"
// Function prototypes
int login();
void addBook(struct Book books[], int *count);
void displayBooks(struct Book books[], int count);
void removeBook(struct Book books[], int *count);
void modifyBook(struct Book books[], int count);
int main() {
 struct Book books[100]; // Array to hold multiple books
 int count = 0; // Count of books
 int choice;
 // Authenticate user
 if (!login()) {
 return 0; // Exit if login fails
 }
 while(1) {
 printf("\nLibrary Management System");
 printf("\n1. Add Book");
 printf("\n2. Display Books");
 printf("\n3. Remove Book");
 printf("\n4. Modify Book");
 printf("\n5. Exit");
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 switch(choice) {
 case 1:
 addBook(books, &count);
 break;
 case 2:
 displayBooks(books, count);
 break;
 case 3:
 removeBook(books, &count);
 break;
 case 4:
 modifyBook(books, count);
 break;
 case 5:
 return 0; // Exit the program
 default:
 printf("Invalid choice! Please try again.\n");
 }
 }
 return 0;
}
// Function to authenticate the user
int login() {
 char username[50], password[50];
 printf("Enter username: ");
 scanf("%s", username);
 printf("Enter password: ");
 scanf("%s", password);
 if (strcmp(username, USERNAME) == 0 && 
strcmp(password, PASSWORD) == 0) {
 printf("Login successful!\n");
 return 1;
 } 
 else {
 printf("Login failed! Incorrect username or password.\n");
 return 0;
 }
}
// Function to add a book
void addBook(struct Book books[], int *count) {
 printf("\nEnter book name: ");
 scanf(" %[^\n]", books[*count].book_name);
 printf("Enter author name: ");
 scanf(" %[^\n]", books[*count].author_name);
 printf("Enter cost: ");
 scanf("%f", &books[*count].cost);
 printf("Enter number of pages: ");
 scanf("%d", &books[*count].no_of_pages);
 (*count)++;
 printf("Book added successfully!\n");
}
// Function to display all books
void displayBooks(struct Book books[], int count) {
 if(count == 0) {
 printf("No books available.\n");
 return;
 }
 for(int i = 0; i < count; i++) {
 printf("\nBook %d\n", i+1);
 printf("Name: %s\n", books[i].book_name);
 printf("Author: %s\n", books[i].author_name);
 printf("Cost: %.2f\n", books[i].cost);
 printf("Number of Pages: %d\n", 
books[i].no_of_pages);
 }
}
// Function to remove a book
void removeBook(struct Book books[], int *count) {
 char name[100];
 printf("\nEnter the name of the book to remove: ");
 scanf(" %[^\n]", name);
 for(int i = 0; i < *count; i++) {
 if(strcmp(books[i].book_name, name) == 0) {
 for(int j = i; j < *count - 1; j++) {
 books[j] = books[j + 1];
 }
 (*count)--;
 printf("Book removed successfully!\n");
 return;
 }
 }
 printf("Book not found.\n");
}
// Function to modify a book's details
void modifyBook(struct Book books[], int count) {
 char name[100];
 printf("\nEnter the name of the book to modify: ");
 scanf(" %[^\n]", name);
 for(int i = 0; i < count; i++) {
 if(strcmp(books[i].book_name, name) == 0) {
 printf("Enter new book name: ");
 scanf(" %[^\n]", books[i].book_name);
 printf("Enter new author name: ");
 scanf(" %[^\n]", books[i].author_name);
 printf("Enter new cost: ");
 scanf("%f", &books[i].cost);
 printf("Enter new number of pages: ");
 scanf("%d", &books[i].no_of_pages);
 printf("Book details modified successfully!\n");
 return;
 }
 }
 printf("Book not found.\n");
}

