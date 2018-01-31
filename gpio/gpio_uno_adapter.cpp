/*
 * file: gpio_uno_adapter.cpp
 * author: Shane Snover <ssnover95>
 * purpose: Implement the GPIO_INTF for the Arduino UNO development board.
 */

#include <avr/io.h>
#include "gpio_uno_adapter.h"


GPIO_UNO_ADAPTER::GPIO_UNO_ADAPTER(PIN _pin) : my_gpio_pin(_pin)
{
    // In the PIN class, bits 5 down to 4 are unique to each register.
    // Here we do some logic to filter out those digits to find the port.
    this->my_gpio_port = static_cast<PORT>((static_cast<uint8_t>(_pin) & 0b00011000) >> 3);
}


GPIO_UNO_ADAPTER::~GPIO_UNO_ADAPTER()
{
    // Empty destructor
}


void GPIO_UNO_ADAPTER::setPinDirection(DIRECTION direction)
{
    switch (this->my_gpio_port)
    {
        case PORT::B:
            if (DIRECTION::INPUT == direction)
            {
                DDRB &= ~(1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            else
            {
                DDRB |= (1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            break;
        case PORT::C:
            if (DIRECTION::INPUT == direction)
            {
                DDRC &= ~(1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            else
            {
                DDRC |= (1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            break;
        case PORT::D:
            if (DIRECTION::INPUT == direction)
            {
                DDRD &= ~(1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            else
            {
                DDRD |= (1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            break;
    }
}


void GPIO_UNO_ADAPTER::writePin(STATE state)
{
    switch (this->my_gpio_port)
    {
        case PORT::B:
            if (STATE::LOW == state)
            {
                PINB &= ~(1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            else
            {
                PINB |= (1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            break;
        case PORT::C:
            if (STATE::LOW == state)
            {
                PINC &= ~(1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            else
            {
                PINC |= (1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            break;
        case PORT::D:
            if (STATE::LOW == state)
            {
                PIND &= ~(1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            else
            {
                PIND |= (1 << static_cast<uint8_t>(this->my_gpio_pin));
            }
            break;
    }
}


GPIO_INTF::STATE GPIO_UNO_ADAPTER::readPin()
{

}


