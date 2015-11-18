/*HDC10008 Header File
*Author: Gus Fragasse
* Date: 10/30/2015
*/

#ifndef LIBS_HDC1008_H_
#define LIBS_HDC1008_H_

#include "I2C.h"
//#include "type.h"

namespace LooperPedal {
	
class HDC1008 {
	public:
	//Deconstructor
	virtual ~HDC1008(); //deletes the memory from the heap
	//Constructor and Initialization
	HDC1008(uint8 ADR0, uint8 ADR1, I2C &i_i2c_manager);
	//here I need to make some public read/write functions
	double readTemperature(); 
	double readHumidity();
	// configuration settings
	void enableHeater(); 
	void disableHeater();
	void setTemperatureResolution(int resolution); //adc resolution for temperature measurement
	void setHumitidityResolution(int reolution); //adc resolution for humidity measurement
	void setAcquisitionMode(int mode); //tells the sequence of ADC conversions
	bool readBatteryStatus(); //returns if battery voltage > 2.8V
	
private:
	// Helper Functions 
	double readRawTemperature(); //raw digital reading of temperature
	double readRawHumidity(); //raw digital reading of temperature
	void configDefault(); //will house default settings for the cofiguration ragister
	
	// Private Variables
	unsigned char slaveAddress;
	//register settings, in order from the datasheet
	
	//from register 0x00 (temperature register)
	int temperatureRegister;
	
	//from register 0x01 (humidity register)
	int humidityRegister;
	
	//from register 0x02 (configuration register)
	int configRegister; //the status of the config register, send contents of this variable to 0x02 adrress
	I2C * i2c_manager;
}
