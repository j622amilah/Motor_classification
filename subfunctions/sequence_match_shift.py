def sequence_match_shift(motor_seq1, motor_seq2):

	# ---------
	# Check if the vectors are equal to each other :
	# ---------
	# Q : Are motor_seq1 and motor_seq2 unique?  
	# A : result
	if len(motor_seq1) != len(motor_seq2):
		minloc = np.argmin([len(motor_seq1), len(motor_seq2)])
		# print('minloc : ', minloc)

		maxloc = np.argmax([len(motor_seq1), len(motor_seq2)])
		# print('maxloc : ', maxloc)

		sigs = [motor_seq1, motor_seq2]
		sigshort = sigs[minloc]
		siglong = sigs[maxloc]
		
		# ---------
		
		# number of non-touching divisions of small signal into long signal
		numofntdivisons = int(np.floor(len(siglong)/len(sigshort)))
		# print('numofntdivisons : ', numofntdivisons)

		# For each numofntdivisons add ovsc (the overlapping portion to get to the 
		# next non-overlapping division)
		nn = []
		for i in range(numofntdivisons):
			# print('len(sigshort) : ', len(sigshort))

			if len(shortsig) > 1: 
				# the number of times you can shift the short signal : overlapping shift count per 
				# non_touching division
				remaining_places_inlong = len(siglong) - (i+1)*len(sigshort)
				need2shift = len(sigshort)-1

				# Search to see if there are enough remaining places in long to shift short over
				# the overlapping area.
				if remaining_places_inlong > need2shift:
					ovsc = need2shift
				else:
					ovsc = remaining_places_inlong
				# print('ovsc : ', ovsc)
			else:
				# there is no overlapping shift, so do not calculate
				ovsc = 0

			nn.append(1+ovsc) # the one signifies each numofntdivisons
		num_of_shifts = np.sum(nn)
		# print('num_of_shifts : ', num_of_shifts)
		
		# ---------

		out = []
		for i in range(num_of_shifts): 
			siglong_shifted = siglong[i:]
			# print('sigshort : ', sigshort)
			# print('siglong_shifted : ', siglong_shifted)
			out0 = [j for j in range(len(sigshort)) if sigshort[j] == siglong_shifted[j]]
			if len(out0) == len(sigshort):   # if all the entries in each vector are identical
				result0 = False   # sigshort and siglong_shifted are the same (NOT unique)
			else:
				result0 = True  # sigshort and siglong_shifted are unique
			# print('result0 : ', result0)
			out.append(result0)
		# print('out : ', out)
		# if there is a False in the out list --> return False (they are the same)
		
		if len(sigshort) > 1:
			# It is a signal sequence with at least two different sequence 
			# entries : interesting because it has a least one motor change
			# Give found result : 
			# ie : out :  [False, True, False], result :  True
			result = True  # Initialize : if there is no False, then a True will be passed to result
            for q in out:
                if q == False:
                    result = False
                    break
		else:
			# It is a single sequence compared with a multiple sequence :
			# not interesting because you will get a lot of false positives
			result = False

	else:  # signals are the same length
		out = [j for j in range(len(motor_seq1)) if motor_seq1[j] == motor_seq2[j]]
		if len(out) == len(motor_seq1):   # if all the entries in each vector are identical
			result = False   # motor_seq1 and motor_seq2 are the same (NOT unique)
		else:
			result = True  # motor_seq1 and motor_seq2 are unique
			
	return result