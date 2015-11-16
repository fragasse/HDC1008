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
		
	}
	void disableHeater(){//no return value, registr setting
		
	}
	void setTemperatureResolution(){ //no return value, register setting
		if(resolution == 11){ //11 bit resolution, set register value
			
		}
		
		else {// bin everything else to 14 bit resolution, set register value
			
		}
	}
	void setHumidityResolution(int resolution) { //no return value needed, register setting
		if (resolution == 8){ //8 bit resolution, set register value
	
		}
		
		else if(resolution == 11){ //11 bit resolution, set register value
			
		}
		
		else {// bin everything else to 14 bit resolution, set register value
			
		}
	}
	
	void setAcquisitionMode(int mode){
		
	}
	 bool batteryStatus(){ //returns 1 if battery voltage > 2.8V and 0 if less
		 
	 }
	 
	 //Private (Helper Function) Definitions
	 double readRawTemperature(){//access the raw temperature register
		 
	 }
	 
	 double readRaw
}