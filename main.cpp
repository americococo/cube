#include "./cube/cube.h"
#include "kbhit.h"
#include <iostream>
#include <stdlib.h>

void just_one(char value) {
}

int main() {
	cubeManager *cubeO = new cubeManager();
	cubeO->Init();

  std::cout<<"Press to = key";
  
	// cubeO->printcube(0);
	cubeO->printDetail();
	while (1) {
		char value = linux_kbhit();
		if (value != -1) {
			std::cout << value << std::endl;

			cubeO->just_one(value);

			cubeO->printDetail();

			// int floor = value - '0';

			// if(floor>=1 && floor<=6)
			//   cubeO->printcube(floor-1);
		}
	}
}