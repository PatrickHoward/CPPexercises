/*
    Program Name: Assign2B | Name: Patrick M. Howard
    Purpose: The purpose of this program is to calculate a grade based on the number of exercises inputed
    and performance done on said exercises.

    Also, I wanted to ensure the data being inputted by the user is indeed valid, so a certain piece of code is repeating in here.
    I will likely fix it when I learn more about functions and object oriented programming in C++.
*/
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

int main()
{
    //Number of assignments used to determine
    int number_of_assignments = 0;
    bool is_valid_int;

    //Holding variables for adding to total_points_worth / scored
    int points_worth = 0;
    int points_scored = 0;

    //Values used for calculation of assignments
    int total_points_worth = 0;
    int total_points_scored = 0;
    float average_score = 0;

    //And the letter grade!
    std::string letter_grade;

    //Do loop to obtain input and validate input.
    do
    {
      //This program automatically assumes the integer is INVALID until proven otherwise. Also known as !(American Criminal Justice System).
      is_valid_int = false;

      //Obtain input
      std::cout << "How many exercises to input? ";
      std::cin >> number_of_assignments;

      //Checks to ensure that the number is within
      if(std::cin.fail() || number_of_assignments < 1)
      {
        //Output if number inputted was invalid.
        std::cout << "Invalid number of assignments, please input an integer greater than 1" << "\n \n";

        std::cin.clear(); //Clean the buffer out
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else
      {
        is_valid_int = true; //If the variable is proven to be true, then stop the loop.
      }

    }while (is_valid_int == false);

    //Now, its time to iterate through each assignment and find out the totals.
    for(int i = 1; i <= number_of_assignments; i++)
    {
      do
      {
        //Once again, begin the validation process. I'm using the same variable to save space and to be more efficient.
        //Therefore, at the beginning of each loop is_valid_int should be set to FALSE.
        is_valid_int = false;

        //Obtain input
        std::cout << "Insert the number of points scored for assignment #" << i << ": ";
        std::cin >> points_scored;

        //Checks to ensure that the number is within
        if(std::cin.fail() || points_scored < 1)
        {
          //Output if number inputted was invalid.
          std::cout << "Invalid points scored, please input an integer greater than 0" << "\n \n";

          std::cin.clear(); //Clean the buffer out
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
          is_valid_int = true; //If the variable is proven to be true, then stop the loop.
        }
      }while (is_valid_int == false);

      do
      {
        //Ugh... I can't wait to learn how to write functions..

        is_valid_int = false;

        //Obtain input
        std::cout << "Insert the number of possible points for assignment #" << i << ": ";
        std::cin >> points_worth;

        //Checks to ensure that the number is within
        if(std::cin.fail() || points_worth < 1)
        {
          //Output if number inputted was invalid.
          std::cout << "Invalid points worth, please input an integer greater than 0" << "\n \n";

          std::cin.clear(); //Clean the buffer out
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
          is_valid_int = true; //If the variable is proven to be true, then stop the loop.
        }
      }while (is_valid_int == false);

      //Add the amounts inputted from this
      total_points_scored += points_scored;
      total_points_worth += points_worth;
    }

    //And the finalie! We calculate the average score using total_points_scored and total_points_worth and give the user his/her letter grade.
    average_score = (float)total_points_scored / (float)total_points_worth;

    average_score *= 100; //This moves the decimal two places so we now have a valid percentage.

    //Assign the letter grade (I couldn't figure out how to make average_score work with a switch statement, so here's a big else-if statment.
    if (average_score > 93)
    {
      letter_grade = "A";
    }
    else if (average_score <= 92.99 && average_score >= 90)
    {
      letter_grade = "A-";
    }
    else if (average_score <= 89.99 && average_score >= 87)
    {
      letter_grade = "B+";
    }
    else if (average_score <= 86.99 && average_score >= 83)
    {
      letter_grade = "B";
    }
    else if (average_score <= 82.99 && average_score >= 80)
    {
      letter_grade = "B-";
    }
    else if (average_score <= 79.99 && average_score >= 77)
    {
      letter_grade = "C+";
    }
    else if (average_score <= 76.99 && average_score >= 73)
    {
      letter_grade = "C";
    }
    else if (average_score <= 72.99 && average_score >= 70)
    {
      letter_grade = "C-";
    }
    else if (average_score <= 69.99 && average_score >= 67)
    {
      letter_grade = "D+";
    }
    else if (average_score <= 66.99 && average_score >= 63)
    {
      letter_grade = "D";
    }
    else if (average_score <= 62.99 && average_score >= 60)
    {
      letter_grade = "D-";
    }
    else
    {
      letter_grade = "F";
    }

    //Print the final statments out.
    std::cout << "Your total is " << total_points_scored << " out of " << total_points_worth << " possible points." << std::endl
      << "That's a " << std::setprecision(4) << average_score << "%" << std::endl
      << "You got a " << letter_grade << "!" << std::endl;

  return 0;
}
