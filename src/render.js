'use strict';

const term = require('terminal-kit').terminal;
const constants = require('./constants.js');
const packageJson = require('../package.json');

// process.exit();

var model = require('./model.js');

// default the cols/rows to the minimum until the screen is initialized
var NUM_COLS = constants.TERMINAL_MIN_COLS;
var NUM_ROWS = constants.TERMINAL_MIN_ROWS;

// Set to true to enable a full refresh. Otherwise static text doesn't
// need to be redrawn.
var NEEDS_REFRESH = true;

var i = 1;

function renderTerminalTooSmall() {
	var errorMessageHeader = 'NEEDS A BIGGER TERMINAL!';
	term.moveTo(NUM_COLS - errorMessageHeader.length + 1, 0);
	term.bgWhite.red(errorMessageHeader);

	var errorMessageCenter = 'Dude... seriously...';
	term.moveTo((NUM_COLS - errorMessageCenter.length) / 2, NUM_ROWS / 2 + 1);
	term.red.bold(errorMessageCenter);
}

// function renderFrame(startX, startY, width, height, title) {
// 	var currX = startX;
// 	var currY = startY;
// 	var i;
//
// 	for (i = 0; i < width; i++) {
//
// 	}
//
// 	term.moveTo()
// }

function renderStaticParts() {
	term.clear();

	term.moveTo(0, 0);
	for (let i = 0; i < NUM_COLS; i++) {
		term.bgBlue(' ');
	}

	term.moveTo(0, 0);
	term.bgBlue.white.bold('CATPOO ');
	term.bgBlue.yellow.bold(packageJson.version);

	// terminal size is good enough check
	if (NUM_COLS < constants.TERMINAL_MIN_COLS || NUM_ROWS < constants.TERMINAL_MIN_ROWS) {
		// it was not good enough
		renderTerminalTooSmall();
		return;
	}

	new termRect(2, 4, 8, 16);
}

function render() {
	if (NEEDS_REFRESH) {
		renderStaticParts();
		NEEDS_REFRESH = false;
	}
}

render.init = function () {
	term.fullscreen(true);
	term.hideCursor();

	NUM_COLS = term.stdout.columns;
	NUM_ROWS = term.stdout.rows;

	term.on('resize', function (cols, rows) {
		NEEDS_REFRESH = true;
		NUM_COLS = cols;
		NUM_ROWS = rows;
	});
}

module.exports = render;