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
	
	//Public Function definitions:
	double readTemperature() { //return real temperature value
	
		double rawTemperature = 0.0;
		rawTemperature = readRawTemperature(); //from register []
		
		double realTemperature = 0.0;
		realTemperature = rawTemperature * 165 / 2^16 - 40; //implement transfer function from HDC1008 datasheet
		
		return realTemperature; 
	}
	double readHumidity(){//return real humidity value
	
		double rawHumidity = 0.0;
		rawHumidity = readRawHumidity(); //from register []
		
		double realHumidity = 0.0;
		realHumidity = rawHumidity * 100 / 2 ^ 16;
		
		return realHumidity;
	}
	void enableHeater(){//no return value, register setting
		configRegister = configRegister | 0010000000000000; //taking the default contents of the config register and turning on the heater
	}
	void disableHeater(){//no return value, registr setting
		configRegister = configRegister & 1101111111111111; //reset
	}
	void setTemperatureResolution(){ //no return value, register setting
		if(resolution == 11){ //11 bit resolution
		configRegister = configRegister | 0000010000000000; //set register 10 to 1
		}
		
		else {// bin everything else to 14 bit resolution, set register value
		configRegister = configRegister & 1111101111111111; //set register 10 to 0	
		}
	}
	void setHumidityResolution(int resolution) { //no return value needed, register setting
		if (resolution == 8){ //8 bit resolution, set register value
		configRegister = configRegister | 0000001000000000; //set register 9 to 1
		configRegister = configRegister & 1111111011111111; //set register 8 to 0
		}
		
		else if(resolution == 11){ //11 bit resolution, set register value
		configRegister = configRegister & 1111110111111111; //set reg 9 to 0
		configRegister = configRegister | 0000000100000000; //set register 8 to 1
		}
		
		else {// bin everything else to 14 bit resolution, set register value
		configRegister = configRegister & 1111110011111111; //set regs 8 and 9 to 0	
		}
	}
	
	void setAcquisitionMode(int mode){//default = 0, temp or humidity is acquired
		configRegister = configRegister | 0001000000000000; //sets mode to 1, temperature then humidity acquired in sequence
	}
	 bool batteryStatus(){ //returns 1 if battery voltage > 2.8V and 0 if less
		if (configRegister & 0000100000000000 != 0){ //battery voltage less than 2.8V!
			//ties to maybe some visual output? red LED?
		} 
		else {
			//ties to some sensor output, green LED?
		}
	 }
	 
	 
	 
	 //Private (Helper Function) Definitions
	 double readRawTemperature(){//access the raw temperature register
		 
	 }
	 
	 double readRawHumidty(){//access the raw humidity register
		 
	 }
	 
	 void configDefault(){//call this to reset to default config as specified by the datasheet
		 
	 }
}