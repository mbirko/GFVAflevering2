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

#ifndef LM75_H
#define LM75_H
    
    #include <stdint.h>
    #include <stdbool.h>
    
    
    enum {LM75_1 = 0x48, LM75_2 = 0x49};
    
    bool getTemp(int16_t *temp, uint8_t slaveAddress);
    
    float convertToCeltius(int16_t temp);
    
    
    
    
#endif

/* [] END OF FILE */
