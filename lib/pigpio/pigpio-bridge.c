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
  return gpioSetMode((uint)gpio, (uint)mode);
}

DRB_FFI
int bridge_gpio_set_pull_up_down(int gpio,int pud) {
  return gpioSetPullUpDown((uint)gpio,(uint)pud);
}

DRB_FFI
int bridge_gpio_glitch_filter(int gpio,int steady) {
  return gpioGlitchFilter((uint)gpio,(uint)steady);
}

DRB_FFI
int bridge_gpio_read(int gpio) {
  return gpioRead((uint)gpio);
}

DRB_FFI
int bridge_gpio_write(int gpio,int value) {
  return gpioWrite((uint)gpio,(uint)value);
}
