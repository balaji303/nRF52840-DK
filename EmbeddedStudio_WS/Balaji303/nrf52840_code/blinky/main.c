/**
 * @file main.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief LED1 Blink
 * @version 1
 * @date 08-11-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */

#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    /* Configure board. */
    //bsp_board_init(BSP_INIT_LEDS);
    nrf_gpio_cfg_output(LED_1);

    /* Toggle LEDs. */
    while (true)
    {
        for (int i = 0; i < LEDS_NUMBER; i++)
        {
            //bsp_board_led_invert(i);
            nrf_gpio_pin_toggle(LED_1);
            nrf_delay_ms(500);
        }
    }
    return 0;
}

/**
 *@}
 **/
