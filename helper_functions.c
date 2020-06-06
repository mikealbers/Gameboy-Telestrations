#include <gb/gb.h>

void performantDelay(UINT8 numloops){
  UINT8 ii;
  for(ii = 0; ii < numloops; ii++){
    wait_vbl_done();
  }
}