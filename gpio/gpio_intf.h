/*
 * file: io_gpio_intf.h
 * author: Shane Snover <ssnover95>
 * purpose: Define the interface for general purpose inputs and outputs.
 */

#ifndef IO_GPIO_INTF
#define IO_GPIO_INTF


class GPIO_INTF
{

public:

    // Binary logic state of the GPIO pin
    enum class STATE
    {
        LOW     = 0u,
        HIGH    = 1u,
    };

    // The direction for reads and writes on the GPIO pin
    enum class DIRECTION
    {
        INPUT   = 0u,
        OUTPUT  = 1u,
    };


    // Empty initializer
    GPIO_INTF() {}
    // Empty destructor
    virtual ~GPIO_INTF() {}

    // Interface for setting the direction of the GPIO pin
    virtual void setPinDirection(DIRECTION direction) = 0;

    // Interface for writing the output level of a GPIO pin
    virtual void writePin(STATE state) = 0;

    // Interface for reading the input level of a GPIO pin
    virtual STATE readPin(void) = 0;

};


#endif  // IO_GPIO_INTF