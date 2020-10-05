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
int trip_calculator(void);
int get_totalcharges(int mot, int hotel, int meals, int number_of_meals_perday, int nod);
int get_foodcharges (int meals, int number_of_meals, int number_of_days);
int get_roomcharges (int hotel, int nod);
void display_results(char* source_city,char * destination_city, char * mot_type_name, int mot_total_charges, 
                            char* hotel_type_name, int number_of_days, char* meals_type_name, int number_of_meals, int total_roomcharge, int total_foodcharge, int total_charges);
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
void get_mot_name (char mot, char* name);
void get_hotel_type_name(char hotel_type, char* name);
void get_meal_type_name(char meal_type, char* name);
void clear_stdbuff (void);

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
char source_city_name [64];
char destination_city_name [64];
char mot_name [64];
char hotel_type_name [64];
char meal_type_name [64];
///////////////////////////////////////////////////////////////////////
int main (int argc, char* argv [])
{
    //run 1
    if (trip_calculator() == 0)
    {
        printf ("Test run 1 failed\n");
    }
    /*
    *  ----------------- output: -------------------------------------
        Enter source city( B, H, N, P) 
        p 
        Enter destination city( D, M, K, C) 
        c
        Enter travel mode ( A, R, B) 
        b
        Enter hotel_type_input type( F, T, O) 
        o
        Enter meal type( V, N, C) 
        c
        Enter number of meal per day 
        5
        Enter number days to travel 
        7
        ********************
        TOTAL CHARGES TO TRAVEL from Pasadena to Clarkson
        ********************
        TRANSPORTATION CHARGES (bus)=7000
        NUMBER OF DAYS OF STAY: (Ordinary) = 7
        NUMBEER OF MEALS IN A DAY: (Continental)= 5
        ROOM CHARGES: 700
        FOOD CHARGES: 350
        ********************
        TOTAL CHARGES: 2050
        ********************
    */

    //run 2
    if (trip_calculator() == 0)
    {
        printf ("Test run 2 failed\n");
    }
    /*
    *  ----------------- output: -------------------------------------
        Enter source city( B, H, N, P) 
        n
        Enter destination city( D, M, K, C) 
        k
        Enter travel mode ( A, R, B) 
        r
        Enter hotel_type_input type( F, T, O) 
        t
        Enter meal type( V, N, C) 
        n
        Enter number of meal per day 
        8
        Enter number days to travel 
        5
        ********************
        TOTAL CHARGES TO TRAVEL from Nashville to Knoxville
        ********************
        TRANSPORTATION CHARGES (Train)=12500
        NUMBER OF DAYS OF STAY: (Three Start) = 5
        NUMBEER OF MEALS IN A DAY: (Non-Vegetarian)= 8
        ROOM CHARGES: 1500
        FOOD CHARGES: 1200
        ********************
        TOTAL CHARGES: 5200
        ********************

    */
    //run 3
    if (trip_calculator() == 0)
    {
        printf ("Test run 3 failed\n");
    }
    /*
    *  ----------------- output: -------------------------------------
        Enter source city( B, H, N, P) 
        h
        Enter destination city( D, M, K, C) 
        m
        Enter travel mode ( A, R, B) 
        a
        Enter hotel_type_input type( F, T, O) 
        f
        Enter meal type( V, N, C) 
        v
        Enter number of meal per day 
        6
        Enter number days to travel 
        3
        ********************
        TOTAL CHARGES TO TRAVEL from Chatanooga to Madison
        ********************
        TRANSPORTATION CHARGES (Air)=12000
        NUMBER OF DAYS OF STAY: (Five) = 3
        NUMBEER OF MEALS IN A DAY: (Vegetarian)= 6
        ROOM CHARGES: 1500
        FOOD CHARGES: 270
        ********************
        TOTAL CHARGES: 5770
        ********************

    */
    //run 4
    if (trip_calculator() == 0)
    {
        printf ("Test run 4 failed\n");
    }
    /*
    *  ----------------- output: -------------------------------------
        Enter source city( B, H, N, P) 
        b
        Enter destination city( D, M, K, C) 
        d
        Enter travel mode ( A, R, B) 
        a
        Enter hotel_type_input type( F, T, O) 
        f
        Enter meal type( V, N, C) 
        n
        Enter number of meal per day 
        4
        Enter number days to travel 
        15
        ********************
        TOTAL CHARGES TO TRAVEL from Baltimore to Denver
        ********************
        TRANSPORTATION CHARGES (Air)=75000
        NUMBER OF DAYS OF STAY: (Five) = 15
        NUMBEER OF MEALS IN A DAY: (Non-Vegetarian)= 4
        ROOM CHARGES: 7500
        FOOD CHARGES: 1800
        ********************
        TOTAL CHARGES: 14300
        ********************
    */
    //run 5
    if (trip_calculator() == 0)
    {
        printf ("Test run 5 failed\n");
    }
    /*
    *  ----------------- output: -------------------------------------
        Enter source city( B, H, N, P) 
        h
        Enter destination city( D, M, K, C) 
        d
        Enter travel mode ( A, R, B) 
        r
        Enter hotel_type_input type( F, T, O) 
        o
        Enter meal type( V, N, C) 
        v
        Enter number of meal per day 
        4
        Enter number days to travel 

        9
        ********************
        TOTAL CHARGES TO TRAVEL from Chatanooga to Denver
        ********************
        TRANSPORTATION CHARGES (Train)=22500
        NUMBER OF DAYS OF STAY: (Ordinary) = 9
        NUMBEER OF MEALS IN A DAY: (Vegetarian)= 4
        ROOM CHARGES: 900
        FOOD CHARGES: 540
        ********************
        TOTAL CHARGES: 3940
        ********************
    */
    return (0);

}

///////////////////////////////////////////////////////////////////////

int trip_calculator(void)
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
    total_cost = get_totalcharges(mot, hotel_per_night, meals, meals_per_day, travel_days);
    
    total_meal_charges = get_foodcharges (meals, meals_per_day, travel_days);

    total_room_charges = get_roomcharges (hotel_per_night, travel_days);
    
    get_city_name(source_city_input, source_city_name);    

    get_city_name(destination_city_input, destination_city_name); 

    get_mot_name (mot_input, mot_name);

    get_hotel_type_name(hotel_type_input, hotel_type_name);

    get_meal_type_name(meals_type_input, meal_type_name);
    
    display_results(source_city_name, destination_city_name, mot_name, (mot * travel_days), 
                            hotel_type_name, travel_days, meal_type_name, meals_per_day, total_room_charges, total_meal_charges, total_cost);

    return (1);
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
    source_city_input = getchar();
    clear_stdbuff();

    if (source_city_input < 'a' && source_city_input > 'z' || source_city_input < 'A' && source_city_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }

    source_city_input = tolower (source_city_input);
    if (source_city_input == 'b' || source_city_input == 'h' || source_city_input == 'n' || source_city_input == 'p')
    {
        return (1);
    }

    printf ("Invalid source city");
    return (0);
}
///////////////////////////////////////////////////////////////////////
int get_destination_city ()
{
    printf ("Enter destination city( D, M, K, C) \n");
    destination_city_input = getchar();
    clear_stdbuff();

    if (destination_city_input < 'a' && destination_city_input > 'z' || destination_city_input < 'A' && destination_city_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }

    destination_city_input = tolower (destination_city_input);
    if (destination_city_input == 'd' || destination_city_input == 'm' || destination_city_input == 'k' || destination_city_input == 'c')
    {
        return (1);
    }

    printf ("Invalid destination city");
    return (0);

}
///////////////////////////////////////////////////////////////////////
int get_mot()
{
    printf ("Enter travel mode ( A, R, B) \n");
    mot_input = getchar();
    clear_stdbuff();

    if (mot_input < 'a' && mot_input > 'z' || mot_input < 'A' && mot_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }

    mot_input = tolower (mot_input);
    if (mot_input == 'a' || mot_input == 'r' || mot_input == 'b')
    {
        return (1);
    }
    printf ("Invalid travel mode");
    return (0);
}
///////////////////////////////////////////////////////////////////////
int get_hotel_type()
{
    printf ("Enter hotel_type_input type( F, T, O) \n");
    hotel_type_input = getchar();
    clear_stdbuff();

    if (hotel_type_input < 'a' && hotel_type_input > 'z' || hotel_type_input < 'A' && hotel_type_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }
    hotel_type_input = tolower (hotel_type_input);
    if (hotel_type_input == 'f' || hotel_type_input == 't' || hotel_type_input == 'o')
    {
        return (1);
    }

    printf ("Invalid hotel_type_input");
    return (0);
}
///////////////////////////////////////////////////////////////////////
int get_meal_type()
{
    printf ("Enter meal type( V, N, C) \n");
    meals_type_input = getchar();
    clear_stdbuff();

    if (meals_type_input < 'a' && meals_type_input > 'z' || meals_type_input < 'A' && meals_type_input > 'Z') 
    {
        printf ("Invalid input \n");
        return (0);
    }
    meals_type_input = tolower (meals_type_input);
    if (meals_type_input == 'v' || meals_type_input == 'n' || meals_type_input == 'c')
    {
        return (1);
    }
    printf ("Invalid meal type");
    return (0);
}
///////////////////////////////////////////////////////////////////////
int get_meal_perday()
{
    printf ("Enter number of meal per day \n");
    scanf ("%d", &meals_per_day);
    clear_stdbuff();
    //TODO: check if meals_type_input per day is valie 
    return (1);
}
///////////////////////////////////////////////////////////////////////
int get_number_of_days()
{
    printf ("Enter number days to travel \n");
    scanf ("%d", &travel_days);
    clear_stdbuff();   
    //TODO: check if meals_type_input per day is valie 
    return (1);
}

///////////////////////////////////////////////////////////////////////
int get_totalcharges(int mot_input, int hotel, int meals, int number_of_meals_perday, int nod)
{
    int totalcharges = 0;
    totalcharges = mot + (hotel * nod) + ( (meals * number_of_meals_perday) * nod);
    return (totalcharges);
} 
///////////////////////////////////////////////////////////////////////
int get_foodcharges (int meals, int number_of_meals, int number_of_days)
{
    int total_foodcharges = 0;
    total_foodcharges = meals * number_of_meals * number_of_days;
    return (total_foodcharges);
}
///////////////////////////////////////////////////////////////////////
int get_roomcharges (int hotel, int nod)
{
    int total_roomcharges = 0;
    total_roomcharges = hotel * nod;
    return (total_roomcharges);
}
///////////////////////////////////////////////////////////////////////
void display_results(char* source_city,char * destination_city, char * mot_type_name, int mot_total_charges, 
                            char* hotel_type_name, int number_of_days, char* meals_type_name, int number_of_meals, int total_roomcharge, int total_foodcharge, int total_charges)
{
    printf("********************\n");
    printf("TOTAL CHARGES TO TRAVEL from %s to %s\n", source_city, destination_city ); 
    printf("********************\n");
    printf("TRANSPORTATION CHARGES (%s)=%d\n", mot_type_name, mot_total_charges);
    printf("NUMBER OF DAYS OF STAY: (%s) = %d\n", hotel_type_name, number_of_days);
    printf("NUMBEER OF MEALS IN A DAY: (%s)= %d\n", meals_type_name,number_of_meals);
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

///////////////////////////////////////////////////////////////////////
void get_mot_name (char mot, char* name)
{
    switch (mot)
    {
        case 'a':
            strcpy (name,"Air");
            break;
        case 'r':
            strcpy (name,"Train");
            break;
        case 'b':
            strcpy (name,"bus");
            break;
    }
}
///////////////////////////////////////////////////////////////////////
void get_hotel_type_name(char hotel_type, char* name)
{
   switch (hotel_type)
    {
        case 'f':
            strcpy (name,"Five");
            break;
        case 't':
            strcpy (name,"Three Start");
            break;
        case 'o':
            strcpy (name,"Ordinary");
            break;
    }
}
///////////////////////////////////////////////////////////////////////
void get_meal_type_name(char meal_type, char* name)
{
   switch (meal_type)
    {
        case 'v':
            strcpy (name,"Vegetarian");
            break;
        case 'n':
            strcpy (name,"Non-Vegetarian");
            break;
        case 'c':
            strcpy (name,"Continental");
            break;
    }
}
///////////////////////////////////////////////////////////////////////
void clear_stdbuff (void)
{    
  while ( getchar() != '\n' );
}
