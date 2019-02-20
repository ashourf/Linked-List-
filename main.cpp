/*
 *******************************************************
*  Name      :   Faisal Ashour             
*  Student ID:    106105110             
*  Class     :  CSC 2421         
*  Due Date  :  September 29, 2018
This a program to implement a linked list container. 
*/ 
#include <iostream>
#include "LinkedList.h"
int main()
{
  char insertion = 0;
  int index = 0;
  LinkedList list;
 int option; // allows users to select values from menu
    bool repeat = false;
    do {
        std::cout << "1. Create list of the alphabet" << std::endl;
        std::cout << "2. Display current list" << std::endl;
        std::cout << "3.Insert at front" << std::endl;
        std::cout << "4.Insert at back" << std::endl;
        std::cout << "5.Insert before postion" << std::endl;
        std::cout << "6.Delete at postion" << std::endl;
        std::cout << "7. delete at front" << std::endl;
        std::cout << "8.delete at back" << std::endl;
        std::cout << "9. Clear list" << std::endl;
        std::cout << "10.Exit" << std::endl;
        std::cin >> option;
             if (std::cin.fail())
        {
           cout << "ERROR -- You did not enter an integer\n"; //modfied from top answer https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected

           // get rid of failure state
           std::cin.clear();
           std::cin.ignore();

        } 
//cascading if/else to load menu options 
        if (option == 1)
        {
           list.clear(); // clear after every run
            for(char letter='A'; letter<='Z'; ++letter) // creates a link list of the entire alphabet 
            {
                list.insertAtBack(letter);
            }
            repeat = true ;
        }
        else if (option == 2)
        {
            if(list.empty()!= true)
            {   
                std::cout << list;
            }
            else std::cout << "No list found please use option one or add your own elements using the other options" << std::endl;
            repeat = true;
        }
        else if (option == 3)
        {
            std::cout << "Enter value to insert" << std::endl;
            std::cin >> insertion;
            list.insertAtFront(insertion);
            repeat = true;
        }
        else if (option == 4)
        {
           
                std::cout << "Enter value to insert" << std::endl;
                std::cin >> insertion;
                list.insertAtBack(insertion);
            
            repeat = true;
        }
        else if (option == 5)
        {   if(list.empty()!= true)
            {  std::cout << "Enter value to insert" << std::endl;
                std::cin >> insertion;
                std::cout << "Enter postion to insert" << std::endl;
                std::cin >> index;
                list.insertBeforePosition(insertion,index);
                
            }
            else std::cout << "No list found please use option one or add your own elements using the other options" << std::endl;

            repeat = true;
        }
        else if (option == 6)
        {
            if(list.empty()!= true)
            {
                std::cout << "Enter postion to delete" << std::endl;
                std::cin >> index;
                list.deletePosition(index);
            }
            else std::cout << "No list found please use option one or add your own elements using the other options" << std::endl;

            repeat = true;
        }
        else if (option == 7)
        {
            if(list.empty()!= true)
            {  
                list.deleteAtFront();
            }
            else std::cout << "No list found please use option one or add your own elements using the other options" << std::endl;

            repeat = true;
        }
        else if (option == 8)
        {
            if(list.empty()!= true)
            {  
                list.deleteAtBack();
            }
            else std::cout << "No list found please use option one or add your own elements using the other options" << std::endl;

            repeat = true;
        }
        else if (option == 9)
        {
            if(list.empty()!= true)
            {  
                list.clear();
            }
            else std::cout << "This list is already empty!" << std::endl;

            repeat = true;
        }
        else if (option == 10)
        {
            std::cout << "Goodbye!" << std::endl;
            repeat = false;
        }
       
       else {
            std::cout << "Not a valid option. Please Try again. " << std::endl;
        }



    } while (repeat == true);
 return 0;
}
