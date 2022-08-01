$gtk.ffi_misc.gtk_dlopen("pigpio-bridge")

module PIGPIO
  # Mode:
  INPUT     = 0
  OUTPUT    = 1

  # Pull up/down:
  PUD_OFF   = 0
  PUD_DOWN  = 1
  PUD_UP    = 2

  # State:
  LOW       = 0
  HIGH      = 1
  OFF       = 0
  ON        = 1
  CLEAR     = 0
  SET       = 1

  ##############################################################################
  # Library Setup :                                                            #
  ##############################################################################
  def gpio_initialise
    FFI::C_PIGPIO::bridge_gpio_initialise()
  end
  
  def gpio_terminate
    FFI::C_PIGPIO::bridge_gpio_terminate()
  end


  ##############################################################################
  # GPIO Setup :                                                               #
  ##############################################################################
  def gpio_set_mode(gpio,mode)
    FFI::C_PIGPIO::bridge_gpio_set_mode(gpio, mode)
  end

  def gpio_set_pull_up_down(gpio,pud)
    FFI::C_PIGPIO::bridge_gpio_set_pull_up_down(gpio, pud)
  end

  def gpio_glitch_filter(gpio,steady)
    FFI::C_PIGPIO::bridge_gpio_glitch_filter(gpio, steady)
  end


  ##############################################################################
  # GPIO Read and Write :                                                      #
  ##############################################################################
  def gpio_read(gpio)
    FFI::C_PIGPIO::bridge_gpio_read(gpio)
  end

  def gpio_write(gpio,value)
    FFI::C_PIGPIO::bridge_gpio_write(gpio, value)
  end
end
