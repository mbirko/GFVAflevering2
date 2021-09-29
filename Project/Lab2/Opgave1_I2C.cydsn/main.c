/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdint.h>
#include "CustomPrint.h"

//interubt service rutines prototypes 
CY_ISR_PROTO (UART_Rx_CT_Handeler);

int main(void)
{
    UART_CT_PutString("Program started!\r\n");
    //interrubt enablers! 
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_UART_CT_StartEx(UART_Rx_CT_Handeler);
    
    //componet enables 
    UART_CT_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {

    }
}

// interubt services rutines 


CY_ISR (UART_Rx_CT_Handeler)
{
    uint8_t numberOfBytes = UART_CT_GetRxBufferSize();
    
    for (uint8_t i = 0; i < numberOfBytes; i++)
    {
        char c = UART_CT_GetChar();
        
        // takes actions based on input. 
        switch (c)
        {
            case 't' :             
            {
                UART_CT_PutString("test!\r\n");
                 PrintStringFloat("int", 3, 7);
            }
            break;
            case 'i' :             
            {
                UART_CT_PutString("testing print int!\r\n");
                PrintStringFloat("int", 3, 7);
            }
            break;
            case 'f' :             
            {   
                UART_CT_PutString("test print float!\r\n");
                PrintStringFloat("float", 5, 3.6);
            }
            break;
            default:                
            {
                UART_CT_PutChar(c);
                UART_CT_PutString("\r\n");
            }
            break;
        }
    }
} // end of uart handeler

/* [] END OF FILE */
