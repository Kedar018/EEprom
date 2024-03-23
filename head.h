#define u32 unsigned int
#define s32 signed int
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned char u8; 
typedef signed char s8;
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern void uart0_tx_string(char *ptr);
extern unsigned char uart0_rx(void);
extern void uart0_rx_string(signed char *ptr,signed int max_bytes);
extern void uart0_tx_integer(int num);
extern void uart0_tx_float(float num);
extern void i2c_init(void);
extern void i2c_bytes_write_frame(u8 sa, u8 mr,u8 data);
extern u8 i2c_byte_read_frame(u8 sa,u8 mr);
extern unsigned int in_to_hex(int num);
extern void delay_ms(unsigned int ms);

