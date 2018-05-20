#ifndef __CATPOO_COMMS_H_
#define __CATPOO_COMMS_H_

#define I2C_ADDR 0x45
#define COMM_BUFFER_LENGTH 128

namespace Comms
{
  void init();
  void loop();
  void processBuffer();
  void resetBuffer();
}

#endif
