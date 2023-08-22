#include <iostream>
#include <iomanip>

const int memorySize = 100;

int memory[memorySize];
int accumulator = 0;
int instructionCounter = 0;
int instructionRegister = 0;
int operationCode = 0;
int operand = 0;

void read() {
    std::cin >> memory[operand];
}

void load() {
    accumulator = memory[operand];
}

void add() {
    accumulator += memory[operand];
}

void branch() {
    instructionCounter = operand;
}

void dump() {
    std::cout << "REGISTERS:" << std::endl;
    std::cout << "accumulator" << std::setw(10) << std::showpos << std::setfill('0') << std::internal << std::setw(4) << accumulator << std::noshowpos << std::endl;
    std::cout << "instructionCounter" << std::setw(2) << std::setfill('0') << std::internal << std::setw(2) << instructionCounter << std::endl;
    std::cout << "instructionRegister" << std::setw(5) << std::showpos << std::setfill('0') << std::internal << std::setw(4) << instructionRegister << std::noshowpos << std::endl;
    std::cout << "operationCode" << std::setw(7) << std::setfill('0') << std::internal << std::setw(2) << operationCode << std::endl;
    std::cout << "operand" << std::setw(10) << std::setfill('0') << std::internal << std::setw(2) << operand << std::endl << std::endl;

    std::cout << "MEMORY:" << std::endl;
    for (int i = 0; i < memorySize; i++) {
        std::cout << std::setw(2) << std::setfill('0') << std::internal << i << " ";
        std::cout << std::showpos << std::setfill('0') << std::internal << std::setw(4) << memory[i] << std::noshowpos << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
}

int main() {
    std::cout << "*** Welcome to Simpletron! ***" << std::endl;
    std::cout << "*** Please enter your program one instruction ***" << std::endl;
    std::cout << "*** (or data word) at a time. I will type the ***" << std::endl;
    std::cout << "*** location number and a question mark (?). ***" << std::endl;
    std::cout << "*** You then type the word for that location. ***" << std::endl;
    std::cout << "*** Type the sentinel -99999 to stop entering ***" << std::endl;
    
}

