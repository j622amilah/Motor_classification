%--------------------------------------------------------------------------
%                   set_IC
%
%   *** IMPORTANT !!!! ***
%
%   This file should be run BEFORE each Real Time simulation
%
%   It initializes the link angles to the ones of the starting position
%   and sets the roll offset
%   
%   The starting position is in the NED
%   system, and the joint angles are made global
%
%   Written by Arthur J. Grunwald, Nov. 19, 2014
%
%--------------------------------------------------------------------------

clear all

global J_ANG_0

J_ANG_0 = [0; 50; -68; 0; 18; 0];

Roll_Offset = 15.89;