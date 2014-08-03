/**
 * @file serialDevice.h
 *
 */

#ifndef SERIALDEVICE_H_
#define SERIALDEVICE_H_

#ifndef __arm__
#define UART_PORT "/dev/ttyUSB0"//"/dev/ttyS0"
#else
#ifdef __fsl__
#define UART_PORT "/dev/ttymxc1"
#else
#define UART_PORT "/dev/ttySAC0"
#endif
#endif


#endif /* SERIALDEVICE_H_ */
