require 'lib/pigpio.rb'

def setup(args)
  # setup stuff here:
  
  args.state.setup_done = true
end

def tick(aegs)
  # do stuff here:

  setup(args) unless args.state.setup_done
end
