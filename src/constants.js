
const CONSTANTS = {
	/**
	 * Maximum number of log entries to keep before deleting old ones.
	 * @type {Number}
	 */
	MAX_LOG_SIZE: 100,

	/**
	 * How often should the main loop run in milliseconds.
	 * @type {Number}
	 */
	LOOP_INTERVAL: 100,

	TERMINAL_MIN_COLS: 80,
	TERMINAL_MIN_ROWS: 24,
};

module.exports = CONSTANTS;
