#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    // Zabezpieczenie przed wywolaniem funkcji z 0;
    if (towar == 0) return 0;

    Stocznia stocznia{};
    int      num_of_zaglowiec = 0;
    int      current_towar    = 0;
    while(current_towar < towar) {
        Statek* s = stocznia();

        current_towar = current_towar + s->transportuj();

        if (dynamic_cast< Zaglowiec* >(s)) {
            num_of_zaglowiec++;
        }

        delete s;
    }

    return num_of_zaglowiec;
}