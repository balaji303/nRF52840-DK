/**
 * @file main.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief LED controlled using Button
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
    nrf_gpio_cfg_input(BUTTON_3,BUTTON_PULL);

    /* Toggle LEDs. */
    while (true)
    {
        if(nrf_gpio_pin_read(BUTTON_3) == 0)
        {
            //bsp_board_led_invert(i);
            nrf_gpio_pin_write(LED_1,0);
            nrf_delay_ms(500);
        }
        else
        {
            nrf_gpio_pin_write(LED_1,1);
            nrf_delay_ms(500);
        }
    }
    return 0;
}

/**
 *@}
 **/
