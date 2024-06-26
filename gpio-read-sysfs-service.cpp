#include <sysfsgpio.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ostream>
#include <zmq.hpp>
#include "zhelpers.hpp"


#define GPIO_PIN "530" // controller 512 + pin 18 = 530

int main() {
	int status; 
	GPIO gpio_test(GPIO_PIN); 

	zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    //  Initialize random number generator
    srandom ((unsigned) time (NULL));
	publisher.bind("tcp://*:5554");
	status = gpio_test.setupPin(1);
	if (status != 0) return 1;
	status = gpio_test.setDirection(0);
	if (status != 0) return 1; 

	while(1){
		std::string res;
		status = gpio_test.readValue(&res); 
		if (status != 0) return 1; 

		s_sendmore (publisher, "BUTTON");
		if (res == "1") {	
			s_send (publisher, "Button RELEASED");
		}
		else {
			s_send (publisher, "Button PRESSED");
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	status = gpio_test.setupPin(0);
	if (status != 0) return 1;

	return 0; 
}
