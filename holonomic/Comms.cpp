#include <HardwareSerial.h>
#include "Comms.h"
#include "Motors.h"
#include "Tests.h"

extern Serial_ Serial;

namespace Comms
{
	const int BUFFER_LENGTH = 1024;
	bool soBad = false;

	char receiveBuffer[BUFFER_LENGTH];
	int receiveBufferIndex = 0;

	void init()
	{
		Serial.println("COMMS: INIT");
		Serial.begin(57600);
		resetBuffer();
	}

	void resetBuffer()
	{
		Serial.println("COMMS: RECV BUFFER RESET");
		memset(receiveBuffer, 0, BUFFER_LENGTH);
		receiveBufferIndex = 0;
	}

	void processBuffer()
	{
		char tokenBuffer[64];

		// convert the buffer to a string for easier processing
		String command(receiveBuffer);
		command.trim();

		if (command.startsWith("DANCE")) {
			Tests::dance();
		} else if (command.startsWith("WHEEL")) {
			Tests::wheel();
		} else if (!soBad && command.indexOf("GOOD") == 0 && command.indexOf("AND YOU") > 0) {
			if (!soBad) {
				Serial.print("YOU: ");
				Serial.println(command);
				Serial.println("ME: NOT SO BAD");
				soBad = true;
			}
		} else if (command.startsWith("RESET")) {
			Motors::reset();
		} else if (command.startsWith("MOVE ")) {
			strtok(command.c_str(), " "); // strip off the front
			String xDistance = String(strtok(NULL, " "));
			String yDistance = String(strtok(NULL, " "));
			Motors::move(xDistance.toInt(), yDistance.toInt());
		} else if (command.startsWith("ROTATE ")) {
			strtok(command.c_str(), " "); // strip off the front
			String angle = String(strtok(NULL, " "));
			Motors::rotate(angle.toInt());
		} else {
			Serial.println(String("DAFUQ: ") + command);
		}

		// cleanup: wipe and reset the receive buffer
		resetBuffer();
	}

	void loop()
	{
		char nextByte;

		while (Serial.available() > 0) {
			nextByte = Serial.read();
			// notice the lack of bounds checking. as an artist, it's what
			// you take out that's more important than what you put in.
			receiveBuffer[receiveBufferIndex++] = nextByte;

			// did we get a newline yet?
			if (nextByte == '\n') {
				// yup! process that!
				processBuffer();
			}
		}

	}
}
