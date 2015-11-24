char keyboard_map[128];
void keyboard_handler( );
char in_port(short port);
void out_port(short port, char data);
void load_interupt_loc(long *idt_ptr);
void move_cursor(int );

/* data structure to handle interrupt requests */
struct Interrupt_Table_Entry {
  short int offset_lower_bits;
  short int selector;
  char zero;
  char flag_type;
  short int offset_higher_bits;
};
