/*
 * file: gpio_uno_adapter.h
 * author: Shane Snover <ssnover95>
 * purpose: Implementation of the GPIO_INTF class for Arduino UNO development
 *          board.
 */

#ifndef __GPIO_UNO_ADAPTER_H__
#define __GPIO_UNO_ADAPTER_H__


#include "gpio_intf.h"


class GPIO_UNO_ADAPTER : public GPIO_INTF
{

public:

    enum class PIN
    {
        PB0 = 0u,
        PB1 = 1u,
        PB2 = 2u,
        PB3 = 3u,
        PB4 = 4u,
        PB5 = 5u,
        PB6 = 6u,
        PB7 = 7u,
        PC0 = 8u,
        PC1 = 9u,
        PC2 = 10u,
        PC3 = 11u,
        PC4 = 12u,
        PC5 = 13u,
        PC6 = 14u,
        PD0 = 16u,
        PD1 = 17u,
        PD2 = 18u,
        PD3 = 19u,
        PD4 = 20u,
        PD5 = 21u,
        PD6 = 22u,
        PD7 = 23u,
        D0  = PD0,
        D1  = PD1,
        D2  = PD2,
        D3  = PD3,
        D4  = PD4,
        D5  = PD5,
        D6  = PD6,
        D7  = PD7,
        D8  = PB0,
        D9  = PB1,
        D10 = PB2,
        D11 = PB3,
        D12 = PB4,
        D13 = PB5,
        A0  = PC0,
        A1  = PC1,
        A2  = PC2,
        A3  = PC3,
        A4  = PC4,
        A5  = PC5,
    }; // PIN


    GPIO_UNO_ADAPTER(PIN _pin);

    ~GPIO_UNO_ADAPTER();

    void setPinDirection(DIRECTION direction) override;

    void writePin(STATE state) override;

    STATE readPin(void) override;

private:

    enum class PORT
    {
        B   = 0u,
        C   = 1u,
        D   = 2u,
    }; // PORT

    PIN my_gpio_pin;
    PORT my_gpio_port;

}; // GPIO_UNO_ADAPTER


#endif // __GPIO_UNO_ADAPTER__