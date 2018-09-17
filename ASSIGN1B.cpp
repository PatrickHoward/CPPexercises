/*
    Prgm: Assignment 1-B Name: Patrick M. Howard
    Purpose: This program will calculate the number of calories burned based on
    the metabolic equivalent (MET) and the time spent on a particular activity.
*/
#include <iostream>
#include <iomanip>

int main()
{
  //Variables for calculating weight
  float weight_in_pounds;
  float weight_in_kilograms;

  //Variables for MET & Time
  int minutes_active;
  int metabolic_eqivalent;

  //Variable for calories burned.
  float calories_burned_rate;
  float total_calories_burned;

  //Greeting and inquiry for weight.
  std::cout << "Assignment 1-B: Calorie Burning Calculator\n"
    << "Hello! Please enter your weight (in pounds): ";

  std::cin >> weight_in_pounds;

  //Converting wieght from pounds to kilograms.
  weight_in_kilograms = weight_in_pounds / 2.2;

  //Inquire about a MET.
  std::cout << "Please insert a metabolic equivalent (MET): ";
  std::cin >> metabolic_eqivalent;

  //Inquire time (in minutes).
  std::cout << "How long (in minutes) did you do this exercise?: ";
  std::cin >> minutes_active;

  //Perform final calculations...
  calories_burned_rate = 0.0175 * metabolic_eqivalent * weight_in_kilograms;

  total_calories_burned = calories_burned_rate * minutes_active;

  //Display final calculations
  std::cout << "You burned a total of " << total_calories_burned << " calories. At a rate of "
    << std::showpoint << std::setprecision(3) << calories_burned_rate << " calories.\n";

  //No problems here!
  return 0;
}
