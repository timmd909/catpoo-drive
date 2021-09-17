//
// MASSIVELY UGLY CODE WARNING!
//
// JUST VERIFYING THAT WHEELS TURN ON AND THE POWER REQUIREMENTS SPIKE!
//

'use strict';

const gpio = require('rpi-gpio');

gpio.setMode(gpio.MODE_BCM);

console.log('Turning on wheels ', pins.WHEEL_1_ENABLE);

Promise.resolve(gpio.promise.setup(pins.WHEEL_1_ENABLE, gpio.DIR_OUT))
Promise.resolve(gpio.promise.setup(pins.WHEEL_2_ENABLE, gpio.DIR_OUT))
Promise.resolve(gpio.promise.setup(pins.WHEEL_3_ENABLE, gpio.DIR_OUT))
Promise.resolve(gpio.promise.setup(pins.WHEEL_4_ENABLE, gpio.DIR_OUT))

setTimeout(function () {
  console.log('ON');
  gpio.write(pins.WHEEL_1_ENABLE, true);
  gpio.write(pins.WHEEL_2_ENABLE, true);
  gpio.write(pins.WHEEL_3_ENABLE, true);
  gpio.write(pins.WHEEL_4_ENABLE, true);
}, 1000);

setTimeout(function () {
  console.log('OFF');
  gpio.write(pins.WHEEL_1_ENABLE, false);
  gpio.write(pins.WHEEL_2_ENABLE, false);
  gpio.write(pins.WHEEL_3_ENABLE, false);
  gpio.write(pins.WHEEL_4_ENABLE, false);

  setTimeout(function () {
    console.log('Done');
    process.exit(0);
  }, 1000);
}, 5000);
