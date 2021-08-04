'use strict';

import _ from 'lodash';

const pins = require('gpio-pins');

var gpio = require('rpi-gpio').promise;

gpio.setup(pins.WHEEL_1_ENABLE, gpio.DIR_OUT)
	.then(() => {
		return gpio.write(pins.WHEEL_1_ENABLE, true)
	});
