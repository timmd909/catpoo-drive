'use strict';

//
// This is the object that represents the entire state of the
// robot at any given time. Don't use globals and instead
// use this single variable.
//

const MAX_SYSLOG_LENGTH = 1000;

var model = {
  // Set to true one hardware has been initialized
  initialized: false,

  // Set to true to shutdown the brain
  shutdown: false,

  // last MAX_SYSLOG_LENGTH items in the system log
  syslog: [],

  // Get this easily with something like `mpstat -o JSON`
  cpuUser: 0, // 0 <= X <= 100
  cpuNice: 0, // 0 <= X <= 100
  cpuIdle: 0, // 0 <= X <= 100

  temp: 0, // unit: celsius

  memTotal: 0, // unit: megabytes
  memFree: 0, // unit: megabytes
  memAvailable: 0, // unit: megabytes

  swapTotal: 0,
  swapFree: 0,

  internetAvailable: false,

  nics: [
    // Ex: { 'name': 'eth0', 'address': null }
    // Ex: { 'name': 'wlan0', 'address': '192.168.1.1' }
    // ...
  ],

  // Range: 0 <= X <= 1000 (or maybe 1024ish)
  rangeFinders: [
    0, // front
    0, // right
    0, // back
    0, // left
  ],

  // Range: -100 <= X <= 100
  // Note: setting to 0 will also turn off the motor
  wheels: [
    0, // front left
    0, // front right
    0, // back right
    0, // back left
  ],

  // Range: -100 <= X <= 100
  movement: [
    0, // movement in the X (left/right) axis
    0, // movement in the Y (front/back) axis
    0, // rotation around Z axis
  ],

  accelerometer: [
    0, // X axis
    0, // Y axis
    0, // Z axis
  ],

  gyroscope: [
    0, // X axis
    0, // Y axis
    0, // Z axis
  ],

};

module.exports = model;
