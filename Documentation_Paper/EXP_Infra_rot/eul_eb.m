function eul_mat = eul_eb(angles)

% Euler matrix for rotation from Earth to Body

% Input vector  angles  = [phi, teta, psi]
% output vector eul_mat = the euler matrix (e->b)

phi  = angles(1);
teta = angles(2);
psi  = angles(3);

PSI =	[	cos(psi), 	sin(psi), 	0.;
			-sin(psi),	cos(psi),	0.;
				0.,		0.,		1.	];

TET = [	cos(teta),	0.,		-sin(teta);
			0.,			1.,		0.;
			sin(teta),	0.,		cos(teta)];

PHI = [	1.,		0.,		0.;
			0.,		cos(phi),	sin(phi);
			0.,		-sin(phi),	cos(phi)];

eul_mat = PHI * TET * PSI;



	
