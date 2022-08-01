#include <pigpio.h>
#include "pigpio-bridge.h"

DRB_FFI
int bridge_gpio_initialise(void) {
  return gpioInitialise();
}

DRB_FFI
void bridge_gpio_terminate(void) {
  gpioTerminate();
}

DRB_FFI
int bridge_gpio_set_mode(int gpio,int mode) {
  return gpioSetMode((unsigned int)gpio, (unsigned int)mode);
}

DRB_FFI
int bridge_gpio_set_pull_up_down(int gpio,int pud) {
  return gpioSetPullUpDown((unsigned int)gpio,(unsigned int)pud);
}

DRB_FFI
int bridge_gpio_glitch_filter(int gpio,int steady) {
  return gpioGlitchFilter((unsigned int)gpio,(unsigned int)steady);
}

DRB_FFI
int bridge_gpio_read(int gpio) {
  return gpioRead((unsigned int)gpio);
}

DRB_FFI
int bridge_gpio_write(int gpio,int value) {
  return gpioWrite((unsigned int)gpio,(unsigned int)value);
}
