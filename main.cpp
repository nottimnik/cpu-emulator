#include <stdio.h>
#include <stdlib.h>

    using Byte = unsigned char;
    using Word = unsigned short;
    using u32 = unsigned int;

struct Memory { //Memory that the CPU will use
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialise() {
        for( u32 i = 0; i < MAX_mem; i++) {
            Data[i] = 0;
        }
    }
};

struct CPU { //The CPU

    Word PC; //Program Counter
    Word SP; //Stack Pointer

    Byte A, X, Y; //registers

    Byte C : 1; //status flag
    Byte Z : 1; //status flag
    Byte I : 1; //status flag
    Byte D : 1; //status flag
    Byte B : 1; //status flag
    Byte V : 1; //status flag
    Byte N : 1; //status flag

    void Reset( Memory& memory) { //Resets the CPU
        PC = 0xFFFC;
        SP = 0x0100;
        C = Z = I = D = B = V = N = 0;
        A = X = Y = 0;
        memory.Initialise();
    }
};

int main() {

    CPU cpu;
    cpu.reset( Memory );
    return 0;
}
