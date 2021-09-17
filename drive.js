'use strict';

const term = require('terminal-kit').terminal;
// const _ = require('lodash');

const constants = require('./src/constants.js');
const logger = require('./src/logger.js');
const render = require('./src/render.js');

const motors = require('./src/motors.js');
const rangeFinders = require('./src/rangeFinders.js');
const mpu6050 = require('./src/mpu6050.js');
const webServer = require('./src/webServer.js');

var model = require('./src/model.js');
var loopInterval;

console.log('do the init here');

function mainLoop() {
	logger('Main loop run');
	//
  // this is where I'll be updating the model based on sensors and such
  //

	// var cursorLocation = Promise.resolve(term.getCursorLocation());
	// console.log('term.stdout = ', term.stdout);

	//
	// Finally, let's render after the model's been updated
	//
	render();
}

term.slowTyping('Initializing CATPOO\'s brain...\n', {
  delay: 20
})
  .then(function () {
		motors.init();
		rangeFinders.init();
		mpu6050.init();
		webServer.init();
		render.init();
		model.initialized = true;
  })
  .then(function () {
		// var model = require('./src/model.js');
		// logger('model = ' + JSON.stringify(model, null, 2));
    loopInterval = setInterval(mainLoop, constants.LOOP_INTERVAL);
  });

//
// var brain = require('./src/brain.js');
//
// const init = require('./src/init.js');
//
// init(brain);
//
// var loopInterval = setInterval(loop, LOOP_INTERVAL);

function shutdown() {
	console.log('\nShutting down...');
	term.hideCursor(false);
}

process.on('SIGINT', function (code) {
	process.exit();
});
process.on('exit', shutdown);
