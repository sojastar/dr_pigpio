#include "dragonruby.h"

DRB_FFI
int  bridge_gpio_initialise(void);
//extern int  bridge_gpio_initialise(void);

DRB_FFI
int bridge_gpio_terminate(void);
//extern int bridge_gpio_terminate(void);

DRB_FFI
int  bridge_gpio_set_mode(int gpio,int mode);
//extern int  bridge_gpio_set_mode(int gpio,int mode);

DRB_FFI
int  bridge_gpio_set_pull_up_down(int gpio,int pud);
//extern int  bridge_gpio_set_pull_up_down(int gpio,int pud);

DRB_FFI
int  bridge_gpio_glitch_filter(int gpio,int steady);
//extern int  bridge_gpio_glitch_filter(int gpio,int steady);

DRB_FFI
int  bridge_gpio_read(int gpio);
//extern int  bridge_gpio_read(int gpio);

DRB_FFI
int  bridge_gpio_write(int gpio,int value);
//extern int  bridge_gpio_write(int gpio,int value);
