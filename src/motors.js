'use strict';

const _ = require('lodash');
const logger = require('./logger.js');

/**
 * Initialize the GPIO for the motor drivers
 */
function init() {
	logger('Initializing motor GPIO pins is not implemented yet');
}

module.exports = {
	init: init,

	WHEEL_1_ENABLE: 4,
  WHEEL_1_STEP: 17,
  WHEEL_1_DIR: 18,

  WHEEL_2_ENABLE: 27,
  WHEEL_2_STEP: 22,
  WHEEL_2_DIR: 23,

  WHEEL_3_ENABLE: 12,
  WHEEL_3_STEP: 13,
  WHEEL_3_DIR: 16,

  WHEEL_4_ENABLE: 19,
  WHEEL_4_STEP: 20,
  WHEEL_4_DIR: 21,

};
