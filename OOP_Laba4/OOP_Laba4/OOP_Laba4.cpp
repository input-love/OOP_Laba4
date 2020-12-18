#include <vld.h>
#include <clocale>
#include "Console.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Console console;
    console.start();

    return 0;
}