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
		Serial.println("COMMS: OK");
		memset(receiveBuffer, 0, BUFFER_LENGTH);
		receiveBufferIndex = 0;
	}

	void processBuffer()
	{
		char* token;

		token = strtok(receiveBuffer, " ");
		// strip off whitespace in a hacky manner... do it right better later
		String tokenStr = String(token);
		tokenStr.trim();
		token = tokenStr.c_str();

		if (0 == strcmp(token, "DANCE")) {
			Serial.println("RUNNING TEST: DANCE");
			Tests::dance();
			Serial.println("TEST COMPLETE");

		} else if (0 == strcmp(token, "WHEEL")) {
			Serial.println("TESTS: WHEEL");
			Tests::wheel();
			Serial.println("TEST COMPLETE");

		} else if (!soBad && 0 == strcmp(token, "GOOD") && strstr(receiveBuffer, "AND YOU") != NULL) {
			Serial.print("YOU: "); Serial.println(receiveBuffer);
			Serial.println("ME: NOT SO BAD");
			soBad = true;

		} else if (0 == strcmp(token, "RESET")) {
			Serial.println("MOTORS: RESET");
			Motors::reset();

		} else if (0 == strcmp(token, "MOVE")) {
			token = strtok(NULL, " ");
			int xDistance = atoi(token);

			token = strtok(NULL, " ");
			int yDistance = atoi(token);

			Serial.print("MOTORS: MOVE "); Serial.print(xDistance); Serial.println(yDistance);
			Motors::move(xDistance, yDistance);

		} else if (0 == strcmp(token, "ROTATE")) {
			token = strtok(NULL, " ");
			int rotation = atoi(token);

			Serial.print("MOTORS: ROTATE "); Serial.println(rotation);
			Motors::rotate(rotation);

		} else {
			Serial.print("DAFUQ: ");
			Serial.println(receiveBuffer);
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
