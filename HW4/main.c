#include "kernel.h"

void main(){
  interrupt_table_init();
  keyboard_init();
  shell();
  while(1);
}
