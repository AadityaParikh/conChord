#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/joystick.h>

int main(int argc,char** argv) {
	int conFd = open("/dev/input/js0", O_RDONLY); //TODO change file to be inputted
	struct js_event ev;
	//read(conFd, &ev, sizeof(ev));
	unsigned long time = 0;
	char buttonStates[3][16]; // current, old, new
	// entry is 17 bytes, one for each button and one for the char being entered
	
	while(1) {
		read(conFd, &ev, sizeof(ev));
		if(ev.type == 0x01 && ev.time>time) {
			buttonStates[0][ev.number] = ev.value; // changing current buttons
			//code here will have access to up to date button states

			
			buttonStates[1][ev.number] = ev.value; // updating buttons
		}
	}
	close(conFd);
}
