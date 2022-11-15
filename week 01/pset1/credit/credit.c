#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // Getting user inputs
    long credit_card = get_long("Number: ");

    // Initiating variables
    int digit_count = 0;
    long divided_number = credit_card;
    long individual_number = credit_card;
    int sum = 0;

    // Calculating CheckSum
    while (divided_number > 0)
    {
        individual_number = divided_number % 10; // Getting the last digit of the credit card
        divided_number = divided_number / 10;   // Divide the number by 10 to get the next digit
        digit_count++;  // Counting the number of digits

        // Check whether the digit count is even or odd
        if (digit_count % 2 == 0)
        {
            int tmp_sum = individual_number * 2;

            if (tmp_sum > 9)
            {
                sum += (tmp_sum % 10 + tmp_sum / 10);
            }

            else
            {
                sum += tmp_sum;
            }
        }

        else
        {
            sum += individual_number;
        }
    }

    // Checking validity of the card
    if (sum % 10 == 0)
    {
        // AmericanExpress
        int amex = credit_card / 10000000000000;
        if ((digit_count == 15) && (amex == 37 || amex == 34))
        {
            printf("AMEX\n");
            return 0;
        }

        // MasterCard
        int master = credit_card / 100000000000000;
        if ((digit_count == 16) && (master >= 50 && master <= 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }

        // Visa
        int visa = credit_card / 1000000000000;
        if ((digit_count >= 13 && digit_count <= 16) && (visa == 4 || (master / 10 == 4)))
        {
            printf("VISA\n");
            return 0;
        }

        // If no card number matched
        printf("INVALID\n");
    }

    else
    {
        printf("INVALID\n");
    }
}