#include "dragonruby.h"

extern int  bridge_gpio_initialise(void);
extern void bridge_gpio_terminate(void);
extern int  bridge_gpio_set_mode(int gpio,int mode);
extern int  bridge_gpio_set_pull_up_down(int gpio,int pud);
extern int  bridge_gpio_glitch_filter(int gpio,int steady);
extern int  bridge_gpio_read(int gpio);
extern int  bridge_gpio_write(int gpio,int value);
