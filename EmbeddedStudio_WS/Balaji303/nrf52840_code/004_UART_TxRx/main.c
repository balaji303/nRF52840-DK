


/*Note: Have This project near to the root dir*/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "app_uart.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf.h"
#include "bsp.h"
#include "nrf_uart.h"


#define UART_TX_BUFF_SIZE 16 // TX buffer size
#define UART_RX_BUFF_SIZE 16 // RX Buffer size
#define MAX_TEST_DATA_BYTES     (11U) 
#define UART_HWFC APP_UART_FLOW_CONTROL_DISABLED

// A simple error handler for uart if something goes wrong...
void uart_err_handle(app_uart_evt_type_t * p)
{
  
}

int main(void)
{
  uint32_t err_code; // a variable to hold the error value
  uint8_t cr; // create a variable to hold the UART char data
  uint8_t *tx_data_on = (uint8_t *)("\r\nLED ON!\r\n");
  uint8_t *tx_data_off = (uint8_t *)("\r\nLED OFF\r\n");
    
  bsp_board_init(BSP_INIT_LEDS); // initialize leds

  const app_uart_comm_params_t com_params = // struct to hold the uart configurations
  {
    RX_PIN_NUMBER, 
    TX_PIN_NUMBER,
    RTS_PIN_NUMBER,
    CTS_PIN_NUMBER,
    UART_HWFC, // hardware flow control disabled
    false, // parity = none
    NRF_UART_BAUDRATE_115200 // set this baud rate for communication

  };

  // pass all the values to this function to initialize the UART module
  APP_UART_FIFO_INIT(&com_params, UART_RX_BUFF_SIZE, UART_TX_BUFF_SIZE, uart_err_handle, APP_IRQ_PRIORITY_LOWEST, err_code);

  // check if everything initialized correctly
  APP_ERROR_CHECK(err_code);


  while(true)
  {
    while(app_uart_get(&cr) != NRF_SUCCESS); // wait here until it receives a char from pc

    if(cr == '1') // check if the received char is t
    {
      bsp_board_leds_on(); // turn on all the leds
  
      for (uint32_t i = 0; i < MAX_TEST_DATA_BYTES; i++)
      {
        while (app_uart_put(tx_data_on[i]) != NRF_SUCCESS);
      }
    }

    if(cr == '0') // check if the received chart is k
    {
      bsp_board_leds_off(); // turn off all the leds
  
      for (uint32_t i = 0; i < MAX_TEST_DATA_BYTES; i++)
      {
        while (app_uart_put(tx_data_off[i]) != NRF_SUCCESS);
      }
    }


    } // while loop closed


   
} // main function closed

