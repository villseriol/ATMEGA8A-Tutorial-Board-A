#include <avr/builtins.h>
#include <avr/io.h>

void setup()
{
}

int main(int argc, char const *argv[])
{
    __builtin_avr_cli();

    __builtin_avr_sei();

    while (1)
    {
        // do something
    }

    return 0;
}