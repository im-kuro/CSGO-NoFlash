#include "noFlash.h"
#include <thread>


int main() {
	while (true) {
		// constantly run no flash cheat
		runNoFlash();
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
	return 0;

}


