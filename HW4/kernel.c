#include "kernel.h"
#include "keyboard_map.h"
#define SCREENSIZE 10 * 80 * 2

int curr_loc = 0;
char *VGA = (char*)0xb8000;
struct Interrupt_Table_Entry IDT[256];

/* initialize interrupt table so the handler can match addresses with interrupt numbers */
void interrupt_table_init( ){

  long keyboard_address;
  long interrupt_address;
  long interrupt_table_ptr[2];

  keyboard_address = (long)keyboard_handler;
  IDT[0x21].offset_lower_bits = keyboard_address & 0xffff;
  IDT[0x21].selector = 0x08;
  IDT[0x21].zero = 0;
  IDT[0x21].flag_type = 0x8e;
  IDT[0x21].offset_higher_bits = (keyboard_address & 0xffff0000) >> 16;

/* remaps PCI interrupts to avoid double faults in protected mode*/
  out_port(0x20 , 0x11);
  out_port(0xA0 , 0x11);
  out_port(0x21 , 0x20);
  out_port(0xA1 , 0x28);
  out_port(0x21 , 0x00);
  out_port(0xA1 , 0x00);
  out_port(0x21 , 0x01);
  out_port(0xA1 , 0x01);
  out_port(0x21 , 0xff);
  out_port(0xA1 , 0xff);

  interrupt_address = (long)IDT ;
  interrupt_table_ptr[0] = (sizeof (struct Interrupt_Table_Entry) * 256) + ((interrupt_address & 0xffff) << 16);
  interrupt_table_ptr[1] = interrupt_address >> 16 ;
  load_interupt_loc(interrupt_table_ptr);
}
/* not implemented correctly function to move flashing cursor */
void move_cursor( int curr_loc ){
    int temp;
    //temp = 10 * 80 + 2;
    temp = curr_loc;
    out_port(0x3D4, 14);
    out_port(0x3D5, temp >> 8);
    out_port(0x3D4, 15);
    out_port(0x3D5, temp);
}

/* initialize keyboard interrupt requests */
void keyboard_init( ){
  out_port(0x21 , 0xFD);
}

void print_screen( char *str){
  int i = 0;
  while (str[i] != '\0') {
    VGA[curr_loc++] = str[i++];
    VGA[curr_loc++] = 0x07;
    move_cursor(curr_loc);
  }
}

void print_newline( ){
  int line_size = 2 * 80;
  curr_loc = curr_loc + (line_size - curr_loc % (line_size));
  move_cursor(curr_loc);
}


void clear_screen( ){
  int i = 0;
  while (i < SCREENSIZE) {
    VGA[i++] = ' ';
    VGA[i++] = 0x07;
  }
}

void shell( ){
  char * intro = "Start Typing....";
  clear_screen();
  print_screen(intro);

}

void keyboard_main( ){

  char status;
  char key_code;

  out_port(0x20, 0x20);
  status = in_port(0x64); // io pressed key port for keyboards

  if (status & 0x01) {
    key_code = in_port(0x60); // io status key port for keyboard 
   if(key_code < 0) 
      return;

    if(key_code == 0x1C) { // check if it's the enter key that was pressed
      print_newline(); 
      return;
    }

    VGA[curr_loc++] = keyboard_map[(unsigned char) key_code];
    VGA[curr_loc++] = 0x07;
  }
}
