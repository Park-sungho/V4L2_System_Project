#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

#include <sys/ioctl.h>
#include <linux/fb.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <termios.h>

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "oem_camera.h"

#define INPUT_DATA_LENGTH_MAX 256

extern int camera_init();
extern int camera_stop();
/* 
 * cmd 0 : camera v4l2 init
 * cmd 2 : stream on
 */
extern int camera_ctrl(int cmd);
extern int set_callback_preview(preview_cb_t cb);
extern int save_dump_data(src_buf, preview_size);

void handler_signal(int32_t signal) {
  printf("Abort, Signal = %s (%d)..\n", (char*)strsignal(signal), signal);
  exit(0);
}

void reg_signal( void ) {
	signal(SIGABRT, handler_signal);
	signal(SIGSEGV, handler_signal);
 	signal(SIGSTOP, handler_signal);
  signal(SIGINT,  handler_signal);
	signal(SIGTERM, handler_signal);
}

void cb_preview_func(void *src_buf, unsigned long preview_size) {
  printf("preview buffer testing...\n");
  printf(": buffer size = %d\n", preview_size);
  
  // TODO: 
  // Save Preview Data
  // save_dump_data(src_buf, preview_size);
}

int main(int argc, char *argv[]) {
	CameraHALDevice_t camera;

	char buf[INPUT_DATA_LENGTH_MAX];
	int32_t i = 0;
	int32_t len = sizeof(appMenu) / sizeof(APP_MENU);

	reg_signal();
	
  printf("Camera HAL Test application\n);
  printf("1 : camera init\n");
  printf("2 : camera start\n");
  printf("3 : camera stop\n");
  
	while(1)
	{
		printf("Input:");
		fgets(buf, sizeof(buf), stdin);

		if( 0x0A == buf[0] ) {
			continue;
		} else if( 'x' == buf[0] ) {
			printf("Exit\n");
			break;
		} else if( '1' == buf[0] ) {
			camera_init();
			break;
		} else if( '2' == buf[0] ) {
			camera_ctrl(0);
      set_callback_preview(cb_preview_func);
      
      // stream on
      camera_ctrl(2);
			break;
		} else if( '3' == buf[0] ) {
			camera_stop();
			break;
		} 
    return 0;
}



