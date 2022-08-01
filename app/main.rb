require 'lib/pigpio.rb'

TEST_GPIO       = 21
CHECK_INTERVAL  = 12

def setup(args)
  PIGPIO::gpio_initialise
  PIGPIO::gpio_set_mode(TEST_GPIO, INPUT)
  PIGPIO::gpio_set_pull_up_down(TEST_GPIO, PUD_UP)
  PIGPIO::gpio_glitch_filter(TEST_GPIO, 2000)

  args.state.setup_done = true
end

def tick(args)
  if args.state.tick_count % CHECK_INTERVAL == O then
    puts 'pushed button!!!'
  end

  setup(args) unless args.state.setup_done
end
