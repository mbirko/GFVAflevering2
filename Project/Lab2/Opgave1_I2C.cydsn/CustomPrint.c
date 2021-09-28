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


#include <stdint.h>
#include "project.h"
#include "CustomPrint.h"
#include <stdio.h>
    //prints a sring followed by a interger number 
void PrintStringInt(char string[], uint8_t strLen, uint8_t number)
{
    char conChar[5] = {": %d"}, str[strLen+4], buffer[255]; 
    uint8_t i = 0;
    for (i = 0; i < strLen; i++)
    {
        str[i] = string[i];
    }
    for (i = strLen; i < strLen+4; i++)
    {
        str[i] = conChar[i - strLen];
    }
    
    snprintf(buffer, sizeof(buffer), str, number);

return;
}






    //prints a string followed by a float type number
void PrintStringFloat(char string[], uint8_t strLen, float number); 


/* [] END OF FILE */
