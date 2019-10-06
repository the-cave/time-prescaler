# Time Prescaler

## What is it?

Time Prescaler is a library that helps you prescale time.
The most common use case is low-frequency signal generation, using timer interrupt as a signal source.
Says, if you want a 10Hz signal from 1kHz timer interrupts, this library is a perfect fit for you.

## Compatabilities

The library will work anywhere as long as the C language works.
The author of the library uses it on STM8 devices, but it should run fine on AVR, PIC, MCS-51, etc.
If it is not, please open an issue on GitHub, you just found a bug.

## How to use this?

Just include the header to your project.
~~~c
#include "time_prescaler8.h"
~~~
Declaring the function to be called periodically.
~~~c
void periodic_function(void) {
  // do something
}
~~~
Setup an instance
~~~c
const TimePrescaler8_Config prescaler_config = {
    // point to the function we declared earlier
    .target = &periodic_function,
    // we want 10Hz from 1kHz so we scale it by a factor of 100
    // 0x100 is a constant depict an overflowed conter value
    .reload_value = 0x100 - 100
};
static TimePrescaler8_State prescaler_state;

// somewhere in main()
time_prescaler8__init(
  &prescaler_config,
  &prescaler_state
);
~~~
And lastly, hooks the source signal
~~~c
void timer_overflow_isr() {
  time_prescaler8__tick(
    &prescaler_config,
    &prescaler_state
  );
}
~~~

## License

Time Prescaler is released under the [BSD 3-Clause License](LICENSE.md). :tada:
