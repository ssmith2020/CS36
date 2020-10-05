/**********************************************************************************************************************/
/*  Name: Sophie Smith                                                                                                */
/*  Student ID: 1185180                                                                                               */
/*  Homework 2 Program Set 2                                                                                          */
/*  This program is an expense calculator for travel                                                                  */
/*                                                                                                                    */
/**********************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//local declarations 
int get_totalcharges(int mot, int hotel, int meals, int nod);
int get_foodcharges (int meals, int number_of_meals, int number_of_days);
int get_roomcharges (int hotel, int nod);
void display_results(char* source_city,char * destination_city, char * mot_input, int mot_total_charges, 
                            char* hotel_type_input, int number_of_days, char* meals_type_input, int number_of_meals, int total_roomcharge, int total_foodcharge, int total_charges);
int get_source_city (void);
int get_destination_city (void);
int get_mot(void);
int get_hotel_type(void);
int get_meal_type(void);
int get_meal_perday(void);
int get_number_of_days(void);
int get_travel_expense (void);
int get_travel_input ();
void get_meals (void);
void get_hotel (void);
void baltimore_travel_expense(void);
void chatanooga_travel_expense(void);
void nashville_travel_expense(void);
void pasadena_travel_expense(void);
void get_city_name (char city, char* name);

//global variables 
char source_city_input;
char destination_city_input;
char hotel_type_input;
char meals_type_input;
char mot_input;
int mot = 0;
int meals = 0;
int hotel_per_night = 0;
int meals_per_day = 0;
int travel_days = 0;
int total_cost = 0;
int total_room_charges = 0;
int total_meal_charges = 0;
///////////////////////////////////////////////////////////////////////
int main (int argc, char* argv [])
{
    if (get_travel_input () == 0)
    {
        //failed to get inptu
        return (0);
    }

    if (get_travel_expense () == 0)
    {
        return (0);
    }
    total_cost = get_totalcharges(mot, hotel_per_night, meals, travel_days);
    
    total_meal_charges = get_foodcharges (meals, meals_per_day, travel_days);

    total_room_charges = get_roomcharges (hotel_per_night, travel_days);
    
    //display_results()
    return (0);
}
///////////////////////////////////////////////////////////////////////
int get_travel_input ()
{

    if (get_source_city () == 0)
    {
        return (0);
    }

    if (get_destination_city () == 0)
    {
        return (0);
    }
    if (get_mot() == 0)
    {
        return (0);
    }
    if (get_hotel_type() == 0)
    {

    }
    if (get_meal_type() == 0)
    {
        return (0);
    }

    if (get_meal_perday() == 0)
    {
        return (0);
    }
    if (get_number_of_days() == 0)
    {
        return (0);
    }
    return (1);
}
///////////////////////////////////////////////////////////////////////
int get_source_city ()
{
    printf ("Enter source city( B, H, N, P) \n");
    scanf ("%c", &source_city_input);

    if (source_city_input < 'a' && source_city_input > 'z' || source_city_input < 'A' && source_city_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }
    source_city_input = tolower (source_city_input);
    if (source_city_input != 'b' || source_city_input != 'c' || source_city_input != 'n' || source_city_input != 'p')
    {
        printf ("Invalid source city");
        return (0);
    }

    return (1);
}
///////////////////////////////////////////////////////////////////////
int get_destination_city ()
{
    printf ("Enter source city( D, M, K, C) \n");
    scanf ("%c", &destination_city_input);

    if (destination_city_input < 'a' && destination_city_input > 'z' || destination_city_input < 'A' && destination_city_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }
    destination_city_input = tolower (destination_city_input);
    if (destination_city_input != 'd' || destination_city_input != 'm' || destination_city_input != 'k' || destination_city_input != 'c')
    {
        printf ("Invalid destination city");
        return (0);
    }

    return (1);

}
///////////////////////////////////////////////////////////////////////
int get_mot()
{
    printf ("Enter travle mode ( A, R, B) \n");
    scanf ("%c", &mot_input);

    if (mot_input < 'a' && mot_input > 'z' || mot_input < 'A' && mot_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }
    mot_input = tolower (mot_input);
    if (mot_input != 'a' || mot_input != 'r' || mot_input != 'b')
    {
        printf ("Invalid travel mode");
        return (0);
    }
    return (1);
}
///////////////////////////////////////////////////////////////////////
int get_hotel_type()
{
    printf ("Enter hotel_type_input type( F, T, O) \n");
    scanf ("%c", &hotel_type_input);

    if (hotel_type_input < 'a' && hotel_type_input > 'z' || hotel_type_input < 'A' && hotel_type_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }
    hotel_type_input = tolower (hotel_type_input);
    if (hotel_type_input != 'f' || hotel_type_input != 't' || hotel_type_input != 'o')
    {
        printf ("Invalid hotel_type_input");
        return (0);
    }

    return (1);

}
///////////////////////////////////////////////////////////////////////
int get_meal_type()
{
    printf ("Enter meal type( V, N, C) \n");
    scanf ("%c", &meals_type_input);

    if (meals_type_input < 'a' && meals_type_input > 'z' || meals_type_input < 'A' && meals_type_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }
    meals_type_input = tolower (meals_type_input);
    if (meals_type_input != 'v' || meals_type_input != 'n' || meals_type_input != 'o')
    {
        printf ("Invalid meal type");
        return (0);
    }
    return (1);
}
///////////////////////////////////////////////////////////////////////
int get_meal_perday()
{
    printf ("Enter number of meal per day \n");
    scanf ("%d", &meals_per_day);
    //TODO: check if meals_type_input per day is valie 
    return (1);
}
///////////////////////////////////////////////////////////////////////
int get_number_of_days()
{
    printf ("Enter number days to travle \n");
    scanf ("%d", &travel_days);
    //TODO: check if meals_type_input per day is valie 
    return (1);
}

///////////////////////////////////////////////////////////////////////
int get_totalcharges(int mot_input, int hotel, int meals, int nod)
{
    int totalcharges = 0;
    totalcharges = mot_input +((hotel_type_input + meals_type_input) * nod);
    return (totalcharges);
} 
///////////////////////////////////////////////////////////////////////
int get_foodcharges (int meals_type_input, int number_of_meals, int number_of_days)
{
    int total_foodcharges = 0;
    total_foodcharges = meals_type_input * number_of_meals * number_of_days;
    return (total_foodcharges);
}
///////////////////////////////////////////////////////////////////////
int get_roomcharges (int hotel_type_input, int nod)
{
    int total_roomcharges = 0;
    total_roomcharges = hotel_type_input * nod;
    return (total_roomcharges);
}
///////////////////////////////////////////////////////////////////////
void display_results(char* source_city,char * destination_city, char * mot_input, int mot_total_charges, 
                            char* hotel_type_input, int number_of_days, char* meals_type_input, int number_of_meals, int total_roomcharge, int total_foodcharge, int total_charges)
{
    printf("********************\n");
    printf("TOTAL CHARGES TO TRAVEL from %s to %s\n", source_city, destination_city ); 
    printf("********************\n");
    printf("TRANSPORTATION CHARGES (%s)=%d\n", mot_input, mot_total_charges);
    printf("NUMBER OF DAYS OF STAY: (%s) = %d\n", hotel_type_input, number_of_days);
    printf("NUMBEER OF MEALS IN A DAY: (%s)= %d\n", meals_type_input,number_of_meals);
    printf("ROOM CHARGES: %d\n", total_roomcharge);
    printf("FOOD CHARGES: %d\n", total_foodcharge);
    printf("********************\n");
    printf("TOTAL CHARGES: %d\n", total_charges);
    printf("********************\n");
}
///////////////////////////////////////////////////////////////////////
int get_travel_expense (void)
{
    switch (source_city_input)
    {
        case 'b':
            baltimore_travel_expense();
            break; 
        case 'h':
            chatanooga_travel_expense();
            break;
        case 'n':
            nashville_travel_expense();
            break;
        case 'p':
            pasadena_travel_expense();
            break;
    }

    get_meals ();
    get_hotel ();
}
///////////////////////////////////////////////////////////////////////
void get_meals (void)
{
    switch (meals_type_input)
    {
        case 'v':
            meals = 15;
            break; 
        case 'n':
            meals = 30;
            break; 
        break;
        case 'c':
            meals = 10;
            break; 
        break;
    }
}
///////////////////////////////////////////////////////////////////////
void get_hotel ()
{
    switch (hotel_type_input)
    {
        case 'f':
            hotel_per_night = 500;
        break;
        case 't':
            hotel_per_night = 300;
        break;
        case 'o':
            hotel_per_night = 100;
        break;
    }
}
///////////////////////////////////////////////////////////////////////Nu
void baltimore_travel_expense()
{
    switch (destination_city_input)
    {
        case 'd': 
            switch (mot_input)
                {
                case 'a':
                    mot = 5000;
                    break;
                case 'r':
                    mot = 2500;
                    break;
                case 'b':
                    mot = 2000;
                    break;    
                 }
            break;
        case 'm':
            switch (mot_input)
                {
                case 'a':
                    mot = 4000;
                    break;
                case 'r':
                    mot = 2000;
                    break;
                case 'b':
                    mot = 1000;
                    break;    

                 }
            break;
        case 'k':
            switch (mot_input)
                {
                case 'a':
                    mot = 5000;
                    break;
                case 'r':
                    mot = 2500;
                    break;
                case 'b':
                    mot = 2000;
                    break;    
                 }
            break;
        case 'c':
            switch (mot_input)
                {
                case 'a':
                    mot = 2500;
                    break;
                case 'r':
                    mot = 800;
                    break;
                case 'b':
                    mot = 1000;
                    break;    
                 }
            break;
    }
}
///////////////////////////////////////////////////////////////////////Nu
void chatanooga_travel_expense()
{
    switch (destination_city_input)
    {
        case 'd':
            switch (mot_input)
                {
                case 'a':
                    mot = 5000;
                    break;
                case 'r':
                    mot = 2500;
                    break;
                case 'b':
                    mot = 2000;
                    break;    
                 }
            break;
        case 'm':
            switch (mot_input)
                {
                case 'a':
                    mot = 4000;
                    break;
                case 'r':
                    mot = 2000;
                    break;
                case 'b':
                    mot = 1000;
                    break;    

                 }
            break;
        case 'k':
            switch (mot_input)
                {
                case 'a':
                    mot = 5000;
                    break;
                case 'r':
                    mot = 2500;
                    break;
                case 'b':
                    mot = 2000;
                    break;    
                 }
            break;
        case 'c':
            switch (mot_input)
                {
                case 'a':
                    mot = 2500;
                    break;
                case 'r':
                    mot = 800;
                    break;
                case 'b':
                    mot = 1000;
                    break;    
                 }
            break;
    }
}
////////////////////////////////////////////////////////////////////Nu
void nashville_travel_expense()
{
    switch (destination_city_input)
    {
        case 'd':
            switch (mot_input)
                {
                case 'a':
                    mot = 5000;
                    break;
                case 'r':
                    mot = 2500;
                    break;
                case 'b':
                    mot = 2000;
                    break;    
                 }
            break;
        case 'm':
            switch (mot_input)
                {
                case 'a':
                    mot = 4000;
                    break;
                case 'r':
                    mot = 2000;
                    break;
                case 'b':
                    mot = 1000;
                    break;    

                 }
            break;
        case 'k':
            switch (mot_input)
                {
                case 'a':
                    mot = 5000;
                    break;
                case 'r':
                    mot = 2500;
                    break;
                case 'b':
                    mot = 2000;
                    break;    
                 }
            break;
        case 'c':
            switch (mot_input)
                {
                case 'a':
                    mot = 2500;
                    break;
                case 'r':
                    mot = 800;
                    break;
                case 'b':
                    mot = 1000;
                    break;    
                 }
            break;
    }
}
///////////////////////////////////////////////////////////////////////
void pasadena_travel_expense()
{
    switch (destination_city_input)
    {
        case 'd':
            switch (mot_input)
                {
                case 'a':
                    mot = 5000;
                    break;
                case 'r':
                    mot = 2500;
                    break;
                case 'b':
                    mot = 2000;
                    break;    
                 }
            break;
        case 'm':
            switch (mot_input)
                {
                case 'a':
                    mot = 4000;
                    break;
                case 'r':
                    mot = 2000;
                    break;
                case 'b':
                    mot = 1000;
                    break;    

                 }
            break;
        case 'k':
            switch (mot_input)
                {
                case 'a':
                    mot = 5000;
                    break;
                case 'r':
                    mot = 2500;
                    break;
                case 'b':
                    mot = 2000;
                    break;    
                 }
            break;
        case 'c':
            switch (mot_input)
                {
                case 'a':
                    mot = 2500;
                    break;
                case 'r':
                    mot = 800;
                    break;
                case 'b':
                    mot = 1000;
                    break;    
                 }
            break;
    }
}
///////////////////////////////////////////////////////////////////////
void get_city_name (char city, char* name)
{
    switch (city)
    {
        case 'd':
            strcpy (name,"Denver");
            break;
        case 'm':
            strcpy (name,"Madison");
            break;
        case 'k':
            strcpy (name,"Knoxville");
            break;
        case 'c':
            strcpy (name,"Clarkson");
            break;
        case 'b':
            strcpy (name,"Baltimore");
            break;
        case 'n':
            strcpy (name,"Nashville");
            break;
        case 'p':
            strcpy (name,"Pasadena");
            break;
        case 'h':
            strcpy (name,"Chatanooga");
            break;
    }
}