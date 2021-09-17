const moment = require('moment');
const chalk = require('chalk');
const constants = require('./constants.js');

var model = require('./model.js');
var logEntries = [];

function formatTimestamp(timestamp) {
	return moment(timestamp).format('YYYY-MM-DD HH:MM:SS');
}

function createLogEntry(message) {
	return {
		'timestamp': new Date(),
		'message': message,
	}
}

function log(message) {
	var newLogItem = createLogEntry(message);
	if (logEntries.length + 1 > constants.MAX_LOG_SIZE) {
		// remove the first one
		logEntries.shift();
	}
	logEntries.push(newLogItem);

	// only output using console.log if the application hasn't
	// been initialized. Otherwise, it'll appear in its own section
	// when rendering.
	if (false == model.initialized) {
		// the screen hasn't been fully initialized
		console.log(
			chalk.blue.bold(formatTimestamp(newLogItem.timestamp)) +
			' ' +
			chalk.green.bold(newLogItem.message)
		);
	}
}

module.exports = log;
