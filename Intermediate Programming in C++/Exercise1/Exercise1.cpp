/*
Tanner Kleintop
Februaury 7, 2023
The purpose of this code is to create a functioning simple machine computer that can read integers with + or - that give the computer a sign of where to store the data.
*/

//I tried my best to write through the code with some parts functioning and others not
//seems like every error I tried to fix caused another so I decided to stop here before
//I had something that wouldnt compile to submit.

#include <iostream>
#include <iomanip>

const int MEMORY_SIZE = 100; // initalizes memory array

int main() {

    //initalizes each of these variables to start at zero
    int memory[MEMORY_SIZE]; 
    int accumulator = 0;
    int instructionCounter = 0;
    int instructionRegister = 0;
    int operationCode = 0;
    int operand = 0;

    //Welcoming message
    std::cout << "*** Welcome to Simpletron! ***\n";
    std::cout << "*** Please enter your program one instruction ***\n";
    std::cout << "*** (or data word) at a time. I will type the ***\n";
    std::cout << "*** location number and a question mark (?).  ***\n";
    std::cout << "*** You then type the word for that location.  ***\n";
    std::cout << "*** Type the sentinel -99999 to stop entering ***\n";
    std::cout << "*** your program. ***\n";

    //input program to the memory
    int input;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        std::cout << i << " ? ";
        std::cin >> input;
        if (input == -99999) break;
        memory[i] = input;
    }


    //program loading message
    std::cout << "*** Program loading completed ***\n";
    std::cout << "*** Program execution begins ***\n";

    //initalizes instruction counterm instruction register, operation code and operand
    instructionCounter = 0;
    //sets instruction register to be equal to memory array of instruction counter
    instructionRegister = memory[instructionCounter];
    //sets operation code equal to the instruction register divided by 100
    operationCode = instructionRegister / 100;
    //sets the operand equal to instruction register mod 100
    operand = instructionRegister % 100;


    //while loop that executes the program
    while (operationCode != 43) {
        switch (operationCode) {
        case 10: //reads input into memory
            std::cin >> memory[operand];
            break;
        case 11: //load accumulator with memory
            accumulator = memory[operand];
            break;
        case 20://add memory to accumulator
            accumulator += memory[operand];
            break;
        case 21: //subtract memory from accumulator
            break;
        case 30: //jump to operand
            instructionCounter = operand;
            break;
        case 31: //jump to operand if accumulator is negative
            break;
        case 40:
            //end program execution
            //displays the output messages with all the data provided from the inputs
                std::cout << "*** Simpletron execution terminated ***\n";
                std::cout << "REGISTERS:\n";
                std::cout << "accumulator\t\t" << std::showpos << std::setw(4) << std::setfill('0') << accumulator << '\n';
                std::cout << "instructionCounter\t" << std::setw(2) << std::noshowpos << instructionCounter << '\n';
                std::cout << "instructionRegister\t" << std::showpos << std::setw(4) << std::setfill('0') << instructionRegister << '\n';
                std::cout << "operationCode\t\t" << std::setw(2) << std::noshowpos << operationCode << '\n';
                std::cout << "operand\t\t\t" << std::setw(2) << operand << '\n';
                std::cout << "MEMORY:\n";
                for (int i = 0; i < MEMORY_SIZE; i += 10) {
                    std::cout << i << ' ';
                    for (int j = 0; j < 10; j++) {
                        std::cout << std::showpos << std::setw(4) << std::setfill('0') << memory[i + j] << ' ';
                    }
                    std::cout << '\n';
                }
            break;
        }
        //increments the instruction counter
        instructionCounter++;
        instructionRegister = memory[instructionCounter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;
    }

    return 0;
}
