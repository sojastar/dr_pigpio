$gtk.ffi_misc.gtk_dlopen("PIGPIO")

module PIGPIO
  LOW   = 0
  HIGH  = 1
  OFF   = 0
  ON    = 1
  CLEAR = 0
  SET   = 1

  ##############################################################################
  # Library Setup :                                                            #
  ##############################################################################
  def gpio_initialise
    FFI::c_PI_GPIO::bridge_gpio_initialise()
  end
  
  def gpio_terminate
    FFI::c_PI_GPIO::bridge_gpio_terminate()
  end


  ##############################################################################
  # GPIO Setup :                                                               #
  ##############################################################################
  def gpio_set_mode(gpio,mode)
    FFI::c_PI_GPIO::bridge_gpio_set_mode(gpio, mode)
  end

  def gpio_set_pull_up_down(gpio,pud)
    FFI::c_PI_GPIO::bridge_gpio_set_pull_up_down(gpio, pud)
  end

  def gpio_glitch_filter(gpio,steady)
    FFI::c_PI_GPIO::bridge_gpio_glitch_filter(gpio, steady)
  end


  ##############################################################################
  # GPIO Read and Write :                                                      #
  ##############################################################################
  def gpio_read(gpio)
    FFI::c_PI_GPIO::bridge_gpio_read(gpio)
  end

  def gpio_write(gpio,value)
    FFI::c_PI_GPIO::bridge_gpio_write(gpio, value)
  end
end
