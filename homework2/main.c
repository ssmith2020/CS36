#include<stdio.h>
#include<stdlib.h>

//local declarations 
static int get_totalcharges(int mot, int hotel, int meals, int nod);
static int get_foodcharges (int meals, int number_of_meals, int number_of_days);
static int get_roomcharges (int hotel, int nod);
static void display_results(char* source_city,char * destination_city, char * mot, int mot_total_charges, 
                            char* hotel, int number_of_days, char* meals, int number_of_meals, int total_roomcharge, int total_foodcharge, int total_charges);

int main (int argc, char* argv [])
{

    return (0);
}
///////////////////////////////////////////////////////////////////////
static int get_totalcharges(int mot, int hotel, int meals, int nod)
{
    int totalcharges = 0;
    totalcharges = mot +((hotel + meals) * nod);
    return (totalcharges);
} 
///////////////////////////////////////////////////////////////////////
static int get_foodcharges (int meals, int number_of_meals, int number_of_days)
{
    int total_foodcharges = 0;
    total_foodcharges = meals * number_of_meals * number_of_days;
    return (total_foodcharges);
}
///////////////////////////////////////////////////////////////////////
static int get_roomcharges (int hotel, int nod)
{
    int total_roomcharges = 0;
    total_roomcharges = hotel * nod;
    return (total_roomcharges);
}

///////////////////////////////////////////////////////////////////////Nu
static void display_results(char* source_city,char * destination_city, char * mot, int mot_total_charges, 
                            char* hotel, int number_of_days, char* meals, int number_of_meals, int total_roomcharge, int total_foodcharge, int total_charges)
{
    printf("********************\n");
    printf("TOTAL CHARGES TO TRAVEL from %s to %s\n", source_city, destination_city ); 
    printf("********************\n");
    printf("TRANSPORTATION CHARGES (%s)=%d\n", mot, mot_total_charges);
    printf("NUMBER OF DAYS OF STAY: (%s) = %d\n", hotel, number_of_days);
    printf("NUMBEER OF MEALS IN A DAY: (%s)= %d\n", meals,number_of_meals);
    printf("ROOM CHARGES: %d\n", total_roomcharge);
    printf("FOOD CHARGES: %d\n", total_foodcharge);
    printf("********************\n");
    printf("TOTAL CHARGES: %d\n", total_charges);
    printf("********************\n");
}