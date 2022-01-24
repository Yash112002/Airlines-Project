#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void store(int seq, char string[], int pnr);
void booking(char s1[], char s2[], char s3[], char s4[], char s5[], char s6[], char arriv[]);

int main()
{
    int sno, no, pnr;
    char city[10], flight[8], dest[10], cont = 'y';
    printf("\n\t\t\t WELCOME TO XYZ AIRLINES\n");
    printf(" NOTE:WE ARE CURRENTLY AVAILABLE IN DELHI,MUMBAI,HYDERABAD AND KOLKATA ONLY\n\n");
    while (cont == 'y')
    {
        printf("\t\tLet's start the Booking of flight ticket\n");
        printf("Enter your departure city: ");
        scanf("%s", city);
        if (strcmp(city, "delhi") == 0 || strcmp(city, "Delhi") == 0)
        {
            printf("\n");
            printf("This are the flights available from Delhi\n");
            printf("\n");
            FILE *x = fopen("delhi.txt", "r");
            char ptr = fgetc(x);
            while (ptr != EOF)
            {
                printf("%c", ptr);
                ptr = fgetc(x);
            }
            fclose(x);
            printf("\n\n");
            char s1[10] = "XYZ-507", s2[10] = "Kolkata", s3[10] = "XYZ-609", s4[10] = "Hyderbad";
            char s5[10] = "XYZ-777", s6[10] = "Mumbai";
            booking(s1, s2, s3, s4, s5, s6, "Delhi");
        }
        else if (strcmp(city, "kolkata") == 0 || strcmp(city, "Kolkata") == 0)
        {
            printf("\n");
            printf("This are the flights available from Kolkata\n");
            printf("\n");
            FILE *x = fopen("kolkata.txt", "r");
            char ptr = fgetc(x);
            while (ptr != EOF)
            {
                printf("%c", ptr);
                ptr = fgetc(x);
            }
            fclose(x);
            printf("\n\n");
            char s1[10] = "XYZ-111", s2[10] = "Delhi", s3[10] = "XYZ-453", s4[10] = "Hyderbad";
            char s5[10] = "XYZ-623", s6[10] = "Mumbai";
            booking(s1, s2, s3, s4, s5, s6, "Kolkata");
        }
        else if (strcmp(city, "hyderabad") == 0 || strcmp(city, "Hyderabad") == 0)
        {
            printf("\n");
            printf("This are the flights available from Hyderbad\n");
            printf("\n");
            FILE *x = fopen("hyderbad.txt", "r");
            char ptr = fgetc(x);
            while (ptr != EOF)
            {
                printf("%c", ptr);
                ptr = fgetc(x);
            }
            fclose(x);
            printf("\n\n");
            char s1[10] = "XYZ-987", s2[10] = "Kolkata", s3[10] = "XYZ-574", s4[10] = "Delhi";
            char s5[10] = "XYZ-239", s6[10] = "Mumbai";
            booking(s1, s2, s3, s4, s5, s6, "Hyderabad");
        }
        else if (strcmp(city, "mumbai") == 0 || strcmp(city, "Mumbai") == 0)
        {
            printf("\n");
            printf("This are the flights available from Mumbai\n");
            printf("\n");
            FILE *x = fopen("mumbai.txt", "r");
            char ptr = fgetc(x);
            while (ptr != EOF)
            {
                printf("%c", ptr);
                ptr = fgetc(x);
            }
            fclose(x);
            printf("\n\n");
            char s1[10] = "XYZ-202", s2[10] = "Kolkata", s3[10] = "XYZ-745", s4[10] = "Hyderbad";
            char s5[10] = "XYZ-824", s6[10] = "Delhi";
            booking(s1, s2, s3, s4, s5, s6, "Mumbai");
        }
        else
        {
            printf("Sorry,we are currently not serving in %s", city);
        }
        fflush(stdin);
        printf("\n");
        printf("Do you want to book an another ticket(y/n): ");
        scanf("%c", &cont);
        if (cont == 'n')
        {
            printf("Thanks For Choosing Our Airline,Happy Journey!!");
        }
    }
    return 0;
}

void booking(char s1[], char s2[], char s3[], char s4[], char s5[], char s6[], char arriv[])
{
    int sno, no, pnr;
    char city[10], flight[8], dest[10];
    printf("\n\n");
    printf("Enter the S.no of the flight you want to book: ");
    scanf("%d", &sno);
    if (sno == 1)
    {
        strcpy(flight, s1);
        strcpy(dest, s2);
    }
    else if (sno == 2)
    {
        strcpy(flight, s3);
        strcpy(dest, s4);
    }
    else if (sno == 3)
    {
        strcpy(flight, s5);
        strcpy(dest, s6);
    }
    printf("Enter the no of passengers: ");
    scanf("%d", &no);
    for (int i = 1; i <= no; i++)
    {
        srand(time(0));
        pnr = rand() % 1000 + 101; // Generates a random number between 101 and 1000
        store(i, flight, pnr);
    }
    printf("Congratulations your ticket is booked!!\n", flight, arriv, dest);
}

void store(int seq, char string[], int pnr)
{
    FILE *book = fopen("booked.txt", "a");
    int age;
    char name[20], gender;
    printf("Please Enter the Details of passenger %d\n", seq);
    printf("Full Name: ");
    fflush(stdin);
    gets(name);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Gender(M/F): ");
    fflush(stdin);
    scanf("%c", &gender);
    printf("\n");
    fprintf(book, "\n%d       %c         %s       XY%d   %s", age, gender, string, pnr, name);
    fclose(book);
}