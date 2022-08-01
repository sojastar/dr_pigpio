//#include "dragonruby.h"

DRB_FFI
extern int  bridge_gpio_initialise(void);

DRB_FFI
extern void bridge_gpio_terminate(void);

DRB_FFI
extern int  bridge_gpio_set_mode(int gpio,int mode);

DRB_FFI
extern int  bridge_gpio_set_pull_up_down(int gpio,int pud);

DRB_FFI
extern int  bridge_gpio_glitch_filter(int gpio,int steady);

DRB_FFI
extern int  bridge_gpio_read(int gpio);

DRB_FFI
extern int  bridge_gpio_write(int gpio,int value);
