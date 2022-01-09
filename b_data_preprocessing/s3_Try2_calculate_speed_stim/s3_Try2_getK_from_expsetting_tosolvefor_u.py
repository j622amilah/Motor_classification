<<<<<<< HEAD
import numpy as np



def Try2_getK_from_expsetting_tosolvefor_u():

	# ------------------------------
	# Idea 2 (control diagram): using the rate known stimulations 
	# (speed_stim = 0.5 and 1.25 degree/s, 3.75 and 17.5 cm/s) for fast and slow motion, 
	# recreate the 1st order system and create stim_ramp.  Get K (the max amplitude for 
	# each experiment and speed) and check if K is near the two clusters from the "pure data" approach
	# ------------------------------
		
	start_val = 0
	stop_val = 20
	ts = 0.1
	f = 1/ts  # sampling frequency
	N = int(f*stop_val)
	t = np.multiply(range(start_val, N), ts) 

	# 
	m = 0.5
	b = 0
	y = m*t + b 
	print('rot sub : y[-1] : ' + str(y[-1]))

	m = 1.25
	b = 0
	y = m*t + b 
	print('rot sup : y[-1] : ' + str(y[-1]))

	start_val = 0
	stop_val = 6
	ts = 0.1
	f = 1/ts  # sampling frequency
	N = int(f*stop_val)
	t = np.multiply(range(start_val, N), ts) 

	# 
	m = 3.75
	b = 0
	y = m*t + b 
	print('trans sub : y[-1] : ' + str(y[-1]))

	m = 17.5
	b = 0
	y = m*t + b 
	print('trans sup : y[-1] : ' + str(y[-1]))

	# rot sub : y[-1] : 9.950000000000001
	# rot sup : y[-1] : 24.875000000000004
	# trans sub : y[-1] : 22.125
	# trans sup : y[-1] : 103.25
	
=======
import numpy as np



def Try2_getK_from_expsetting_tosolvefor_u():

	# ------------------------------
	# Idea 2 (control diagram): using the rate known stimulations 
	# (speed_stim = 0.5 and 1.25 degree/s, 3.75 and 17.5 cm/s) for fast and slow motion, 
	# recreate the 1st order system and create stim_ramp.  Get K (the max amplitude for 
	# each experiment and speed) and check if K is near the two clusters from the "pure data" approach
	# ------------------------------
		
	start_val = 0
	stop_val = 20
	ts = 0.1
	f = 1/ts  # sampling frequency
	N = int(f*stop_val)
	t = np.multiply(range(start_val, N), ts) 

	# 
	m = 0.5
	b = 0
	y = m*t + b 
	print('rot sub : y[-1] : ' + str(y[-1]))

	m = 1.25
	b = 0
	y = m*t + b 
	print('rot sup : y[-1] : ' + str(y[-1]))

	start_val = 0
	stop_val = 6
	ts = 0.1
	f = 1/ts  # sampling frequency
	N = int(f*stop_val)
	t = np.multiply(range(start_val, N), ts) 

	# 
	m = 3.75
	b = 0
	y = m*t + b 
	print('trans sub : y[-1] : ' + str(y[-1]))

	m = 17.5
	b = 0
	y = m*t + b 
	print('trans sup : y[-1] : ' + str(y[-1]))

	# rot sub : y[-1] : 9.950000000000001
	# rot sup : y[-1] : 24.875000000000004
	# trans sub : y[-1] : 22.125
	# trans sup : y[-1] : 103.25
	
>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
	return 