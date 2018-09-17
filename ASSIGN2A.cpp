/*
    Program Name: ASSIGN2A | Name: Patrick M. Howard
    Purpose: To alert the user if the number of students attending exceeds the legal capacity defined.
*/

#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
  //Constants for three different rooms across the University of Akron's campus.
  const int LH312 = 42; //Leigh Hall, room 312
  const int CAS41 = 44; //College of Arts & Sciences, room 41
  const int KH133 = 33; //Kolbe Hall, room 133

  //Variables for the interface.
  int decision; //Decision based on what the user inputs.
  bool is_valid_int = false; //Used for verification on

  //Variables related to student capacities.
  int students_attending;
  int student_capacity;
  int empty_spaces;

  //Display options for user to pick.
  std::cout << "1.) Leigh Hall, room 312" << std::endl;
  std::cout << "2.) College of Arts & Sciences, room 41" << std::endl;
  std::cout << "3.) Kolbe Hall, room 133" << std::endl;


  do
  {
    //A integer is invalid until proven otherwise.
    is_valid_int = false;

    //Loop to ensure the input is valid.
    std::cout << "\n" << "Please make a selection: ";
    std::cin >> decision;

    //Ensure that the value given within the desired range.
    if (std::cin.fail() || (decision < 1 || decision > 3))
    {
      std::cout << "Please make a valid decision \n"
        << "Please select from the menu items above \n \n";

      //Clean out the input buffer.
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        is_valid_int = true;
    }

  }while (is_valid_int == false);

  //Now, we are going to ask for the number of people attending the selected classroom and validate it
  //using the same procedure.

  do
  {
    is_valid_int = false;
    //Loop to ensure the input is valid.
    std::cout << "\n" << "Input the number of students attending this classroom:";
    std::cin >> students_attending;

    //Ensure that the value given within the desired range.
    if (std::cin.fail() || (students_attending < 1))
    {
      std::cout << "Please input a valid integer greater than 0!\n \n";

      //Clean out the input buffer.
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        is_valid_int = true; //Valid! Break the loop!
    }

  }while (is_valid_int == false);

  //Assign student capacity based on user selection.
  switch(decision)
  {
    case 1:
      student_capacity = LH312;
      break;
    case 2:
      student_capacity = CAS41;
      break;
    case 3:
      student_capacity = KH133;
      break;
  }

  //Now we will subtract the number of student_capacity defined above, by students attending.
  empty_spaces = student_capacity - students_attending;

  //The final statement(s) the user will see before the program exits.
  if (empty_spaces > 0)
  {
    std::cout << "There are " << empty_spaces << " more seats available in the classroom!" << std::endl;
  }
  else if (empty_spaces == 0)
  {
    std::cout << "The classroom is filled to capacity!" << std::endl;
  }
  else
  {
    std::cout << "Fire hazard! You are " << empty_spaces * -1 << " over capacity! Move to a bigger room!" << std::endl;
  }

  return 0;

}
