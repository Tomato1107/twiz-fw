#include <stdint.h>
#include <stdbool.h>

#include "nordic_common.h"
#include "softdevice_handler.h"
#include "timers.h"
#include "leds.h"
#include "uart.h"
#include "printf.h"
#include "i2c_wrapper.h"


/**
 * @brief Function for application main entry.
 */
int main(void)
{
    // Init SD so that timers have a clock reference, and to be ablr to call SD functions.
    // Must be done first !
    SOFTDEVICE_HANDLER_INIT(NRF_CLOCK_LFCLKSRC_SYNTH_250_PPM, false);
    nrf_delay_ms(100);

    // Init LEDs
    leds_init();

    // Init UART
    uart_init();

    // Init timers
    timer_init();

    // Init TWI
    i2c_init();

    // Run MPU9150 mainloop
    //mpu9150_mainloop();
    //while(1) ;

    // Main loop
    while(1) {
        leds_blink(500);
        static uint32_t t;
        //get_ms(&t);
        //printf("Hello float=%.20f, time=%d\r\n", 1.123456789987654321, t);
    }
    return 0;
}
