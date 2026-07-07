#include <console.h>

#define UART_BASE  ((volatile char *)0x40600000)
#define UART_LSR   5
#define UART_THR   0

/* kbd_intr - try to feed input characters from keyboard */
void kbd_intr(void) {}

/* serial_intr - try to feed input characters from serial port */
void serial_intr(void) {}

/* cons_init - initializes the console devices */
void cons_init(void) {}

static void uart_putc(char c) {
    /* 等待发送缓冲空闲（LSR bit5 = 1） */
    while (!(UART_BASE[UART_LSR] & 0x20));
    UART_BASE[UART_THR] = c;
}

static int uart_getc(void) {
    /* 检查是否有数据可读（LSR bit0 = 1） */
    if (UART_BASE[UART_LSR] & 0x01)
        return (unsigned char)UART_BASE[0];
    return 0;
}

/* cons_putc - print a single character @c to console devices */
void cons_putc(int c) { uart_putc(c); }

/* cons_getc - return the next input character from console */
int cons_getc(void) { return uart_getc(); }
