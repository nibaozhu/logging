#include "logging.h"

void handler(int signum) {
	fprintf(stderr, "%s:%d: %s: signum = %d\n", __FILE__, __LINE__, __func__, signum);
}

void set_disposition() {
	signal(SIGINT, handler); // Ctrl-C
	signal(SIGTERM, handler); // default signal when kill ...
}

int main(int argc, char **argv) {
	(void)argc;

	set_disposition();

	/* (1): Begin ... */
	initializing(argv[0], P_tmpdir, "w+", debug, debug, LOGGING_INTERVAL, LOGGING_CACHE, LOGGING_SIZE);
	do {
		enum level x = (enum level) (rand() % (debug + 1));
		int timeout = rand() % (int)(1e6);

		/* (2): dadada ... */
		LOGGING(x, "This is a logging message. { timeout: %d }\n", timeout);
		// usleep(timeout);
	} while (true);

	/* (3): End ... */
	return uninitialized();
}
