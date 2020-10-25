
#include<stdio.h>

int main (int argc, char* argv[])
{
//    float salary = 2500.001234, rate = 7.001234, raise = 1750.001234, new_salary = 26750.001234;//
    float salary = 0.0, rate = 0.0, raise = 0.0, new_salary = 0.0;

    float total_salary, total_raise, total_new_salary;
    int input_salary;
    char heading [128] = "             Salary      Rate    Raise       New Salary";

    


    //outputting header 
    printf("%-25s \n", heading);
    //get salary 
    printf("Salary: ");
    scanf("%d", &input_salary);

     //while loop statement
    while (input_salary > 0) 
    { 
        //calculation salary
        if (input_salary > 0 && input_salary < 30000)
        {
            rate = 0.07;
        }
        else if (input_salary >= 30000 && input_salary <= 40000)
        {
            rate = 0.055;
        }       
        else if (input_salary >= 40000)
        {
              rate = 0.04;
        }        
        salary = input_salary; 
        //calculate raise
        raise = input_salary * rate;
        //calculate new input_salary
        new_salary = raise + input_salary;
        //output salary data
        printf("%-12s%-12.2f%-4.2f    %-5.2f     %-7.2f \n","             ", salary, rate, raise, new_salary);
        //update running total
        total_salary += salary; 
        total_raise += raise;
        total_new_salary += new_salary;
        //get salary again
        printf("Salary: ");
        scanf("%d", &input_salary); 
    }
    //output totals
    printf("%-13s%-13.2f       %-10.2f  %-10.2f     \n","Total", total_salary, total_raise, total_new_salary);
    return 0;

}
//Output PS1