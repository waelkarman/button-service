//Copyright (c) 2019, Alex Mous
//Licensed under the Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-4.0)

//Example code for reading a GPIO pin
//Set GPIO pin number GPIO_PIN as an input and read the current value
//Change #define GPIO_PIN to a different number to use a different GPIO pin

#include <sysfsgpio.h>
#include <iostream>
#include <string>

#define GPIO_PIN "18" //GPIO pin (BCM number) used as an input

int main() {

	while(1){
		int status; //Create a status variable

		GPIO gpio_test(GPIO_PIN); //Create a GPIO object

		status = gpio_test.setupPin(1); //Create pin
		if (status != 0) return 1; //Return error code

		status = gpio_test.setDirection(0); //Set pin direction
		if (status != 0) return 1; //Return error code

		std::string res;
		status = gpio_test.readValue(&res); //Set pin value
		if (status != 0) return 1; //Return error code

		if (res == "1") {
			std::cout << "GPIO pin " << GPIO_PIN << " is HIGH\n";

		}
		else {
			std::cout << "GPIO pin " << GPIO_PIN << " is LOW\n";
		}
		sleep(1000);
	}
		status = gpio_test.setupPin(0); //Disable pin
		if (status != 0) return 1; //Return error code

	
	return 0; //Return default code
}
