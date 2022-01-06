



def solve_for_u(tf_pred, sysmeth, discon):

	# Tried the full goal (solving for u : u/outSIG = [1 - R(s)*H(s)]) 
	# --------------------
	print('tf_pred : ' + str(tf_pred))
	print('sysmeth : ' + str(sysmeth))
	print('discon : ' + str(discon))
	# --------------------


	if sysmeth != 300 or sysmeth != 200:

	# --------------------
	# Check if best H model was discrete or continuous
	if discon == 0:   # Discrete
		# Treat model as Continuous
		sys_type = 'cont'
		den_pp = pole_placement(tf_pred, sys_type)
		num = make_a_properlist(tf_pred[0])
		tf_con = (num, den_pp)human-in-the-loop block
	elif discon == 1:   # Continuous
		tf_con = tf_pred
	# --------------------

	print('tf_con : ' + str(tf_con))

	# --------------------
	# Continuous time model:
	num = make_a_properlist(tf_con[0])
	den = make_a_properlist(tf_con[1])

	a1 = num[2]
	b1 = num[1]
	c1 = num[0]

	a2 = den[2]
	b2 = den[1]
	c2 = den[0]
	# --------------------

	# --------------------
	# Write out robot system : R(z) = 1/[z^-2 + bz^-1 + c]

	# 1st attempt to write the correct 2nd order robot system
	# TT = 4
	# b = (3.6*math.pi)/TT  # 1st order denomenator
	# c = math.pi/(TT*0.9)  # 0th order denomenator

	# 2nd attempt to write the correct 2nd order robot system
	# b = 4*0.8*math.pi
	# c = math.pi/0.8

	# 3rd attempt to write the correct 2nd order robot system
	zeta = 0.8
	T = 4 # 4
	wn = 1/(T*zeta)
	# num = [1]  # classical formulation numerator is [wn*wn], but we used [1]
	# den = [1, 2*zeta*wn, wn*wn]
	b = 2*zeta*wn
	c = wn*wn
	# --------------------

	# --------------------
	# Multiply robot system with human system : R(z)*H(z)
	num = [a1, b1, c1]
	den = [a2, b2+b*a2, c2+b*b2+c*a2, b*c2+c*b2, c*c2]
	print('num : ' + str(num))
	print('den : ' + str(den))
	print('Roots of R(s)*H(s) : ' + str(np.roots(den)))
	# --------------------

	# --------------------
	# Solve for u using the closedloop expression of outSIG wrt u=stim_ramp*t
	# outSIG/u = 1/[1 - R(s)*H(s)]

	# We invert the transfer function, because we want to solve for u
	# u/outSIG = [1 - R(s)*H(s)]
	num_cl = [a2, b2+b*a2, c2+b*b2+c*a2-a1, b*c2+c*b2-b1, c*c2-c1]
	den_cl = [a2, b2+b*a2, c2+b*b2+c*a2, b*c2+c*b2, c*c2]

	# print('num : ' + str(num_cl))
	# print('den_cl : ' + str(den_cl))
	# cl_sysroots = np.roots(den_cl)
	# print('Roots of inverted closedloop to solve for u) : ' + str(cl_sysroots))
	# --------------------

	# --------------------
	# Check if continuous closedloop expression is stable
	sys_type = 'cont'
	tf_con_cl = (num_cl, den_cl)
	den_pp = pole_placement(tf_con_cl, sys_type)
	tf_con_cl = (num_cl, den_pp)

	roots_out = np.roots(den_pp)
	print('outSIG/u = 1/[1 - R(s)*H(s)] roots_out: ' + str(roots_out))
	# --------------------

	# --------------------
	# Solve for u
	# Continuous time: 
	u_t, u, xout = lsim((num_cl, den_pp), U=outputs_org, T=t)

	# Discrete time:
	# u_t, u  = signal.dlsim((num_cl, den_cl, ts), inputs, t=t)
	# u = make_a_properlist(u)
	# u_t = make_a_properlist(u_t)
	# --------------------

	# --------------------
	# u should be an increasing and/or flat-slope line
	# the initial slope of u should give if the robot is 
	# moving fast(sup) or slow (sub)
	fig = go.Figure()
	config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

	fig.add_trace(go.Scatter(x=t, y=inputs_org, name='inputs_org', line = dict(color='green', width=2, dash='dash'), showlegend=True))
	fig.add_trace(go.Scatter(x=t, y=outputs_org, name='outputs_org', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
	fig.add_trace(go.Scatter(x=u_t, y=u, name='u', line = dict(color='red', width=2, dash='dash'), showlegend=True))

	fig.update_layout(title='u', xaxis_title='time', yaxis_title='signal')
	fig.show(config=config)
	# --------------------

	return u, u_t