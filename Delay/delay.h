/*
 * delay.h
 *
 *  Created on: Jul 28, 2019
 *      Author: MetalStriker
 */

#ifndef FQMC_SYSTEM_INCLUDE_DELAY_H_
#define FQMC_SYSTEM_INCLUDE_DELAY_H_


void delay(int milli_sec)
{
    //time_cycle = 0.0000000033 or 300Mhz
    int scale_factor = 30000;
    int final_cycle = scale_factor * milli_sec;

    while(final_cycle != 0)
    {
        final_cycle--;
    }

}


#endif /* FQMC_SYSTEM_INCLUDE_DELAY_H_ */
