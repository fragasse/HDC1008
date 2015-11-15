/*HDC10008 Temperature and Humidity Sensor Class
* Author: Gus Fragasse
*Created on 10/30/2015
*/

#include "type.h"
#include "base_main_Rate44_pps_driver.h"
#include "Audio_AIC.h"
#include "I2C.h"
#include "misc.h"
#include "msp.h"
#include <stdint.h>

namespace LooperPedal {
	
	HDC10008 ::~ HDC10008(){
		//Deconstructor
	}
	HDC10008::HDC10008(unsigned char address, I2C &i_i2c_manager) {
		i2c_manager = i_i2c_manager;
		//Initialize Settings for HDC10008
		
	}
	
}