# i2c
i2c library for Arduino

usage:

  for init: i2cinit()
  
  for start: i2cstart(address)
  
  for reading:
  
	with acknowledge i2creadack()
	
	without acknowledge i2creadnck()
  
  for writing: i2cwrite(data)
  
  for stoping: i2cstop()
