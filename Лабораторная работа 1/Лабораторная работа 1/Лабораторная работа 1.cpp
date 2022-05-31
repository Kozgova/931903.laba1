#include <iostream>

using namespace std;

void FirstLaba() {
    cout << "First laba" << endl;
}

class Operations {
public:
    static int Add(int, int);
    static int Sub(int, int);
    static int Mult(int, int);
    static int Div(int, int);

    static bool Equal(int, int);
    static bool Less(int, int);
    static bool LessEqual(int, int);

    static bool Not(bool);
    static bool Or(bool, bool);
    static bool And(bool, bool);
    static bool Xor(bool, bool);

    static int Index(int[], int);

    static int Left(int, int);
    static int Right(int, int);

    static void Iter(void*, int);
};


int Operations::Add(int a, int b) {
    int result;
    _asm {
        mov eax, a
        add eax, b
        mov result, eax
    }
    return result;
}

int Operations::Sub(int a, int b) {
    int result;
    _asm {
        mov eax, a
        sub eax, b
        mov result, eax
    }
    return result;
}

int Operations::Mult(int a, int b) {
    int result;
    _asm {
        mov eax, a
        imul eax, b
        mov result, eax
    }
    return result;
}

int Operations::Div(int a, int b) {
    int result;
    _asm {
        mov edx, 0
        mov eax, a
        mov ebx, b
        idiv ebx
        mov result, eax
    }

    return result;
}

bool Operations::Equal(int a, int b) {
    int result;
    _asm {
        mov ebx, 1
        mov eax, a
        cmp eax, b
        je L
        mov ebx, 0
        L:  mov result, ebx
    }
    return bool(result);
}

bool Operations::Less(int a, int b) {
    int result;
    _asm {
        mov ebx, 1
        mov eax, a
        cmp eax, b
        jl L
        mov ebx, 0
        L:  mov result, ebx
    }
    return result;
}

bool Operations::LessEqual(int a, int b) {
    int result;
    _asm {
        mov ebx, 1
        mov eax, a
        cmp eax, b
        jle L
        mov ebx, 0
        L:  mov result, ebx
    }
    return result;
}

bool Operations::Not(bool a) {
    bool result;
    _asm {
        mov ah, 1
        mov al, a
        not al
        cmp al, 255
        je L
        mov ah, 0
        L: mov result, ah
    }
    return result;
}

bool Operations::Or(bool a, bool b) {
    bool result;
    _asm {
        mov al, a
        or al, b
        mov result, al
    }
    return result;
}

bool Operations::And(bool a, bool b) {
    bool result;
    _asm {
        mov al, a
        and al, b
        mov result, al
    }
    return result;
}

bool Operations::Xor(bool a, bool b) {
    bool result;
    _asm {
        mov al, a
        xor al, b
        mov result, al
    }
    return result;
}

int Operations::Index(int mass[], int ind)
{
    int result;
    _asm {
        mov ebx, mass
        mov ecx, ind
        mov eax, [ebx + 4 * ecx]
        mov result, eax
    }
    return result;
}

int Operations::Left(int toShift, int num)
{
    int result;
    _asm {
        mov eax, toShift
        mov ecx, num
        shl eax, cl
        mov result, eax
    }
    return result;
}

int Operations::Right(int toShift, int num)
{
    int result;
    _asm {
        mov eax, toShift
        mov ecx, num
        shr eax, cl
        mov result, eax
    }
    return result;
}

void Operations::Iter(void* func, int iter)
{
    _asm {
        mov edi, 0
        mov esi, iter
        L : call func
        inc   edi
        cmp   edi, esi
        jb    L
    }
}

int main()
{
    int massA[5] = { 10, 20, 30, 40, 50 };

    cout << endl << "Add: " << Operations::Add(-5, 10) << endl;
    cout << "Sub: " << Operations::Sub(-9, 20) << endl;
    cout << "Mult: " << Operations::Mult(4, 4) << endl;
    cout << "Div: " << Operations::Div(12, 2) << endl << endl;

    cout << "Equal: " << Operations::Equal(5, 7) << endl;
    cout << "Equal: " << Operations::Equal(5, 5) << endl;
    cout << "Equal: " << Operations::Equal(7, 5) << endl << endl;

    cout << "Less: " << Operations::Less(2, 4) << endl;
    cout << "Less: " << Operations::Less(4, 4) << endl;
    cout << "Less: " << Operations::Less(4, 2) << endl << endl;

    cout << "Less or Equal: " << Operations::LessEqual(6, 9) << endl;
    cout << "Less or Equal: " << Operations::LessEqual(9, 9) << endl;
    cout << "Less or Equal: " << Operations::LessEqual(9, 6) << endl << endl;

    cout << "Not: " << Operations::Not(true) << endl;
    cout << "Or: " << Operations::Or(true, false) << endl;
    cout << "And: " << Operations::And(false, true) << endl;
    cout << "Xor: " << Operations::Xor(true, true) << endl << endl;

    cout << "Index: " << Operations::Index(massA, 4) << endl << endl;

    cout << "Left: " << Operations::Left(15, 3) << endl;
    cout << "Right: " << Operations::Right(15, 2) << endl << endl;

    Operations::Iter(FirstLaba, 10);
}
