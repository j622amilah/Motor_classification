  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 18;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (M43_Sim_Forcing_003h_Trajectory_P)
    ;%
      section.nData     = 330;
      section.data(330)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_Size
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 31;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 33;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 34;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 36;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 37;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 39;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 40;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 42;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_Size_i
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 71;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_i
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 73;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_Size_m
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 102;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_a
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 104;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_Size_f
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 105;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_e
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 107;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_Size_j
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 108;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_c
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 110;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_Size_c
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 111;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_o
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 113;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.x_e2_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 142;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.x_e1_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 143;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainval
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 144;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 145;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator2_gainval
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 146;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator2_IC
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 147;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.y_e1_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 148;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.TargetPSI_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 149;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 150;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.newmidpoint_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 151;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Nominalmidpointcheckwithselecte
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 152;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.z_e1_Value
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 153;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainval
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 154;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 155;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Phi1_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 156;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Theta1_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 157;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_i
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 158;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_m
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 159;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.y_e2_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 160;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P1_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 161;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 163;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P2_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 195;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P2
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 197;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P3_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 198;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P3
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 200;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P4_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 201;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P4
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 203;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P1_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 204;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P1
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 206;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P2_Size
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 238;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P2
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 240;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P3_Size
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 241;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P3
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 243;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P4_Size
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 244;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P4
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 246;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P1_Size
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 247;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P1
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 249;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P2_Size
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 281;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P2
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 283;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P3_Size
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 284;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P3
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 286;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P4_Size
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 287;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P4
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 289;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 290;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 296;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_Size_n
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 302;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_n
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 304;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_Size_l
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 333;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_i
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 335;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_Size_p
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 336;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_j
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 338;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_Size_n
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 339;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_g
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 341;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 342;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_h
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 343;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value_l
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 344;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_Size_p
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 345;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_ob
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 347;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_Size_o
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 376;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_j
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 378;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_Size_c
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 407;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_c
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 409;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_Size_d
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 410;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_eq
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 412;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_Size_c
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 413;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_m
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 415;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_Size_d
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 416;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_h
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 418;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.x_e_Value
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 447;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_e
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 448;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_d
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 449;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.fromcmtom_Gain
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 450;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_j
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 451;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_o
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 452;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.fromcmtom_Gain_d
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 453;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.y_e_Value
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 454;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.z_e_Value
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 455;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_f
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 456;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_h
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 457;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.fromcmtom_Gain_n
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 458;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainv_ex
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 459;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_c
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 460;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 461;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Phi_Value
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 462;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainv_jz
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 463;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_f
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 464;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_a
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 465;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Theta_Value
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 466;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AllowedPsi_Value
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 467;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.forenable_Value
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 468;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_l
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 469;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_g
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 470;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Psi_Value
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 471;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.UnitDelay_X0
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 472;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_a
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 478;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_k
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 479;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 480;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_p
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 481;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_k
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 487;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 493;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.UnitDelay6_X0
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 494;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Value
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 500;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_e
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 501;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_InitialSt
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 502;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerator
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 503;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denominat
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 508;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 513;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA1_UpperSat
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 514;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA1_LowerSat
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 515;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA1_RisingLim
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 516;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA1_FallingLim
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 517;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA1_IC
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 518;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_k
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 519;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_l
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 520;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA2_UpperSat
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 521;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA2_LowerSat
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 522;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA2_RisingLim
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 523;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA2_FallingLim
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 524;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA2_IC
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 525;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_j
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 526;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_d
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 527;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA3_UpperSat
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 528;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA3_LowerSat
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 529;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA3_RisingLim
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 530;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA3_FallingLim
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 531;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA3_IC
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 532;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_c
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 533;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_p
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 534;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA4_UpperSat
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 535;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA4_LowerSat
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 536;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA4_RisingLim
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 537;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA4_FallingLim
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 538;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA4_IC
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 539;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_n
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 540;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_i
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 541;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiter3_UpperSat
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 542;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiter3_LowerSat
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 543;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA5_RisingLim
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 544;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA5_FallingLim
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 545;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA5_IC
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 546;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_nt
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 547;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_m
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 548;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiter6_UpperSat
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 549;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.VelLimiter6_LowerSat
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 550;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA6_RisingLim
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 551;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA6_FallingLim
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 552;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA6_IC
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 553;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_k
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 554;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_i
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 555;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 556;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 557;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 558;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain5_Gain
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 559;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_j
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 560;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_p
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 561;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.fromcmtom_Gain_h
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 562;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.pizetaT_transfers_gainval
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 563;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.pizetaT_transfers_IC
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 564;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_c
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 565;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Initial_f
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 566;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_a
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 567;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_p
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 572;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_o
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 577;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_g
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 580;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_c
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 581;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_i
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 582;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gain_a4
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 583;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_k
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 584;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_p
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 585;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_kd
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 586;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_a
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 587;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_g
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 588;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_f
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 589;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_pa
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 590;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_g
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 591;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_n
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 592;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_m
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 593;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_h
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 594;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_b
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 595;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_p
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 596;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.x_max_Value
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 597;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_l
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 598;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_j
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 599;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_hu
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 600;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value_g
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 601;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator3_gainval
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 602;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator3_IC
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 603;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.frommtocm_Gain
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 604;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.frommtocm_Gain_i
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 605;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_n
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 606;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.zetapiT_transfers_gainval
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 607;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.zetapiT_transfers_IC
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 608;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.zetapi_Gain
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 609;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.pizeta_Gain
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 610;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_i
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 611;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_o
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 612;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P1_Size_o
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 613;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P1_g
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 615;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P2_Size_b
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 647;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P2_e
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 649;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P3_Size_p
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 650;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P3_e
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 652;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P4_Size_a
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 653;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P4_o
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 655;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANController_P1_Size
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 656;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANController_P1
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 658;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANController_P2_Size
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 690;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANController_P2
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 692;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P1_Size
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 704;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P1
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 706;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P2_Size
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 735;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P2
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 737;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P1_Size
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 751;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P1
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 753;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P2_Size
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 782;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P2
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 784;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite_P1_Size
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 798;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite_P1
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 800;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite1_P1_Size
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 829;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite1_P1
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 831;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_p3
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 860;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_j
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 861;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_p
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 862;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_m
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 863;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_l
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 864;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_c
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 865;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_ik
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 866;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_f
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 867;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P1_Size
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 868;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P1
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 870;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P2_Size
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 902;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P2
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 904;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_n
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 905;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_m
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 906;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_o
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 907;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_g
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 908;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_j
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 909;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_l
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 910;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_oc
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 911;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_c
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 912;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX1_P1_Size
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 913;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX1_P1
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 915;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX1_P2_Size
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 947;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX1_P2
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 949;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_jm
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 950;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_p
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 951;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_h
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 952;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_fl
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 953;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_d
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 954;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_i
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 955;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_p5
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 956;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_gu
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 957;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX2_P1_Size
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 958;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX2_P1
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 960;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX2_P2_Size
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 992;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX2_P2
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 994;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_b
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 995;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.PSEA2_Value
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 996;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_i
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 997;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_h
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 998;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_k
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 999;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_a
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 1000;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_f
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 1001;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_iw
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 1002;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_kw
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 1003;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.setforoptimizingxandy_Value
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 1004;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.setforoptimizingpurez_Value
	  section.data(287).logicalSrcIdx = 286;
	  section.data(287).dtTransOffset = 1010;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.setforoptimizingz_Value
	  section.data(288).logicalSrcIdx = 287;
	  section.data(288).dtTransOffset = 1016;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value_e
	  section.data(289).logicalSrcIdx = 288;
	  section.data(289).dtTransOffset = 1022;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Forsavingpositionandvelocityunt
	  section.data(290).logicalSrcIdx = 289;
	  section.data(290).dtTransOffset = 1023;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.TSamp_WtEt
	  section.data(291).logicalSrcIdx = 290;
	  section.data(291).dtTransOffset = 1024;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.UD_X0
	  section.data(292).logicalSrcIdx = 291;
	  section.data(292).dtTransOffset = 1025;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.zetaT_transferpi_Gain
	  section.data(293).logicalSrcIdx = 292;
	  section.data(293).dtTransOffset = 1026;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.pizetaT_transfers_gainval_c
	  section.data(294).logicalSrcIdx = 293;
	  section.data(294).dtTransOffset = 1027;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.zetapiT_transfers_gainval_j
	  section.data(295).logicalSrcIdx = 294;
	  section.data(295).dtTransOffset = 1028;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.zetapi_Gain_n
	  section.data(296).logicalSrcIdx = 295;
	  section.data(296).dtTransOffset = 1029;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.pizeta_Gain_h
	  section.data(297).logicalSrcIdx = 296;
	  section.data(297).dtTransOffset = 1030;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant7_Value
	  section.data(298).logicalSrcIdx = 297;
	  section.data(298).dtTransOffset = 1031;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_hy
	  section.data(299).logicalSrcIdx = 298;
	  section.data(299).dtTransOffset = 1032;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch1_Threshold
	  section.data(300).logicalSrcIdx = 299;
	  section.data(300).dtTransOffset = 1033;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_ki
	  section.data(301).logicalSrcIdx = 300;
	  section.data(301).dtTransOffset = 1034;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch2_Threshold
	  section.data(302).logicalSrcIdx = 301;
	  section.data(302).dtTransOffset = 1035;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P1_Size_g
	  section.data(303).logicalSrcIdx = 302;
	  section.data(303).dtTransOffset = 1036;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P1_n
	  section.data(304).logicalSrcIdx = 303;
	  section.data(304).dtTransOffset = 1038;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P2_Size_l
	  section.data(305).logicalSrcIdx = 304;
	  section.data(305).dtTransOffset = 1067;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P2_n
	  section.data(306).logicalSrcIdx = 305;
	  section.data(306).dtTransOffset = 1069;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P1_Size_b
	  section.data(307).logicalSrcIdx = 306;
	  section.data(307).dtTransOffset = 1083;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P1_j
	  section.data(308).logicalSrcIdx = 307;
	  section.data(308).dtTransOffset = 1085;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P2_Size_a
	  section.data(309).logicalSrcIdx = 308;
	  section.data(309).dtTransOffset = 1114;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P2_n
	  section.data(310).logicalSrcIdx = 309;
	  section.data(310).dtTransOffset = 1116;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX2_P1_Size
	  section.data(311).logicalSrcIdx = 310;
	  section.data(311).dtTransOffset = 1130;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX2_P1
	  section.data(312).logicalSrcIdx = 311;
	  section.data(312).dtTransOffset = 1132;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX2_P2_Size
	  section.data(313).logicalSrcIdx = 312;
	  section.data(313).dtTransOffset = 1161;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX2_P2
	  section.data(314).logicalSrcIdx = 313;
	  section.data(314).dtTransOffset = 1163;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite_P1_Size_f
	  section.data(315).logicalSrcIdx = 314;
	  section.data(315).dtTransOffset = 1177;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite_P1_f
	  section.data(316).logicalSrcIdx = 315;
	  section.data(316).dtTransOffset = 1179;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite1_P1_Size_m
	  section.data(317).logicalSrcIdx = 316;
	  section.data(317).dtTransOffset = 1208;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite1_P1_e
	  section.data(318).logicalSrcIdx = 317;
	  section.data(318).dtTransOffset = 1210;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite2_P1_Size
	  section.data(319).logicalSrcIdx = 318;
	  section.data(319).dtTransOffset = 1239;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite2_P1
	  section.data(320).logicalSrcIdx = 319;
	  section.data(320).dtTransOffset = 1241;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_f
	  section.data(321).logicalSrcIdx = 320;
	  section.data(321).dtTransOffset = 1270;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P1_Size_h
	  section.data(322).logicalSrcIdx = 321;
	  section.data(322).dtTransOffset = 1271;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P1_n
	  section.data(323).logicalSrcIdx = 322;
	  section.data(323).dtTransOffset = 1273;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P2_Size_d
	  section.data(324).logicalSrcIdx = 323;
	  section.data(324).dtTransOffset = 1305;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P2_c
	  section.data(325).logicalSrcIdx = 324;
	  section.data(325).dtTransOffset = 1307;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P1_Size_f
	  section.data(326).logicalSrcIdx = 325;
	  section.data(326).dtTransOffset = 1308;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P1_h
	  section.data(327).logicalSrcIdx = 326;
	  section.data(327).dtTransOffset = 1310;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P2_Size_i
	  section.data(328).logicalSrcIdx = 327;
	  section.data(328).dtTransOffset = 1342;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P2_k
	  section.data(329).logicalSrcIdx = 328;
	  section.data(329).dtTransOffset = 1344;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_p
	  section.data(330).logicalSrcIdx = 329;
	  section.data(330).dtTransOffset = 1345;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Initial_l
	  section.data(1).logicalSrcIdx = 330;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_k
	  section.data(2).logicalSrcIdx = 331;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_f
	  section.data(3).logicalSrcIdx = 332;
	  section.data(3).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_mm
	  section.data(4).logicalSrcIdx = 333;
	  section.data(4).dtTransOffset = 11;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_k
	  section.data(5).logicalSrcIdx = 334;
	  section.data(5).dtTransOffset = 12;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_g
	  section.data(6).logicalSrcIdx = 335;
	  section.data(6).dtTransOffset = 13;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_k
	  section.data(7).logicalSrcIdx = 336;
	  section.data(7).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_h
	  section.data(8).logicalSrcIdx = 337;
	  section.data(8).dtTransOffset = 15;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_UpperSa
	  section.data(9).logicalSrcIdx = 338;
	  section.data(9).dtTransOffset = 16;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_LowerSa
	  section.data(10).logicalSrcIdx = 339;
	  section.data(10).dtTransOffset = 17;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_h
	  section.data(11).logicalSrcIdx = 340;
	  section.data(11).dtTransOffset = 18;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_ir
	  section.data(12).logicalSrcIdx = 341;
	  section.data(12).dtTransOffset = 19;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_lz
	  section.data(13).logicalSrcIdx = 342;
	  section.data(13).dtTransOffset = 20;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_o
	  section.data(14).logicalSrcIdx = 343;
	  section.data(14).dtTransOffset = 21;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_l
	  section.data(15).logicalSrcIdx = 344;
	  section.data(15).dtTransOffset = 22;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gain_p4
	  section.data(16).logicalSrcIdx = 345;
	  section.data(16).dtTransOffset = 23;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_o
	  section.data(17).logicalSrcIdx = 346;
	  section.data(17).dtTransOffset = 24;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Upper_a
	  section.data(18).logicalSrcIdx = 347;
	  section.data(18).dtTransOffset = 25;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Lower_p
	  section.data(19).logicalSrcIdx = 348;
	  section.data(19).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant3_Value
	  section.data(1).logicalSrcIdx = 349;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant4_Value
	  section.data(2).logicalSrcIdx = 350;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.TXCANID1_Value
	  section.data(3).logicalSrcIdx = 351;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.TXCANID2_Value
	  section.data(4).logicalSrcIdx = 352;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.TXCANID3_Value
	  section.data(5).logicalSrcIdx = 353;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant3_Value_n
	  section.data(6).logicalSrcIdx = 354;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant4_Value_c
	  section.data(7).logicalSrcIdx = 355;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant6_Value
	  section.data(8).logicalSrcIdx = 356;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.TXCANID1_Value_f
	  section.data(9).logicalSrcIdx = 357;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.TXCANID1_Value_h
	  section.data(10).logicalSrcIdx = 358;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_it
	  section.data(1).logicalSrcIdx = 359;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_a
	  section.data(2).logicalSrcIdx = 360;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain6_Gain
	  section.data(3).logicalSrcIdx = 361;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_b
	  section.data(4).logicalSrcIdx = 362;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_d
	  section.data(5).logicalSrcIdx = 363;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_fc
	  section.data(6).logicalSrcIdx = 364;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent
	  section.data(1).logicalSrcIdx = 365;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_g
	  section.data(2).logicalSrcIdx = 366;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_k
	  section.data(3).logicalSrcIdx = 367;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_n
	  section.data(4).logicalSrcIdx = 368;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_c
	  section.data(5).logicalSrcIdx = 369;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_e
	  section.data(6).logicalSrcIdx = 370;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_j
	  section.data(7).logicalSrcIdx = 371;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_a
	  section.data(8).logicalSrcIdx = 372;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_p
	  section.data(9).logicalSrcIdx = 373;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_d
	  section.data(10).logicalSrcIdx = 374;
	  section.data(10).dtTransOffset = 9;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_nk
	  section.data(11).logicalSrcIdx = 375;
	  section.data(11).dtTransOffset = 10;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_kt
	  section.data(12).logicalSrcIdx = 376;
	  section.data(12).dtTransOffset = 11;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_dd
	  section.data(13).logicalSrcIdx = 377;
	  section.data(13).dtTransOffset = 12;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_g3
	  section.data(14).logicalSrcIdx = 378;
	  section.data(14).dtTransOffset = 13;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_f
	  section.data(15).logicalSrcIdx = 379;
	  section.data(15).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_nj
	  section.data(16).logicalSrcIdx = 380;
	  section.data(16).dtTransOffset = 15;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_gq
	  section.data(17).logicalSrcIdx = 381;
	  section.data(17).dtTransOffset = 16;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_ed
	  section.data(18).logicalSrcIdx = 382;
	  section.data(18).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value_l
	  section.data(1).logicalSrcIdx = 383;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value_d
	  section.data(2).logicalSrcIdx = 384;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value_i
	  section.data(3).logicalSrcIdx = 385;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value_i
	  section.data(4).logicalSrcIdx = 386;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant5_Value
	  section.data(5).logicalSrcIdx = 387;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_g
	  section.data(1).logicalSrcIdx = 388;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.SwitchControl_Threshold
	  section.data(2).logicalSrcIdx = 389;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch1_Threshold_a
	  section.data(3).logicalSrcIdx = 390;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_d
	  section.data(4).logicalSrcIdx = 391;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Switch1_Threshold_a2
	  section.data(5).logicalSrcIdx = 392;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_e
	  section.data(6).logicalSrcIdx = 393;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.SwitchControl_Threshold_a
	  section.data(7).logicalSrcIdx = 394;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_d
	  section.data(8).logicalSrcIdx = 395;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.SwitchControl_Threshold_p
	  section.data(9).logicalSrcIdx = 396;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.TXData_Value
	  section.data(10).logicalSrcIdx = 397;
	  section.data(10).dtTransOffset = 9;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.TXData_Value_d
	  section.data(11).logicalSrcIdx = 398;
	  section.data(11).dtTransOffset = 10;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_g
	  section.data(12).logicalSrcIdx = 399;
	  section.data(12).dtTransOffset = 11;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_k
	  section.data(13).logicalSrcIdx = 400;
	  section.data(13).dtTransOffset = 12;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_f
	  section.data(14).logicalSrcIdx = 401;
	  section.data(14).dtTransOffset = 13;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_h
	  section.data(15).logicalSrcIdx = 402;
	  section.data(15).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_ia
	  section.data(16).logicalSrcIdx = 403;
	  section.data(16).dtTransOffset = 15;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_ip
	  section.data(17).logicalSrcIdx = 404;
	  section.data(17).dtTransOffset = 16;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_f
	  section.data(18).logicalSrcIdx = 405;
	  section.data(18).dtTransOffset = 17;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_b
	  section.data(19).logicalSrcIdx = 406;
	  section.data(19).dtTransOffset = 18;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_mk
	  section.data(20).logicalSrcIdx = 407;
	  section.data(20).dtTransOffset = 19;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_mo
	  section.data(21).logicalSrcIdx = 408;
	  section.data(21).dtTransOffset = 20;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_kp
	  section.data(22).logicalSrcIdx = 409;
	  section.data(22).dtTransOffset = 21;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_d2
	  section.data(23).logicalSrcIdx = 410;
	  section.data(23).dtTransOffset = 22;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_m1
	  section.data(24).logicalSrcIdx = 411;
	  section.data(24).dtTransOffset = 23;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_e
	  section.data(25).logicalSrcIdx = 412;
	  section.data(25).dtTransOffset = 24;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_ck
	  section.data(26).logicalSrcIdx = 413;
	  section.data(26).dtTransOffset = 25;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_e0
	  section.data(27).logicalSrcIdx = 414;
	  section.data(27).dtTransOffset = 26;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_l
	  section.data(28).logicalSrcIdx = 415;
	  section.data(28).dtTransOffset = 27;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_b
	  section.data(29).logicalSrcIdx = 416;
	  section.data(29).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_e.PSEA2_Value
	  section.data(1).logicalSrcIdx = 417;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_e.Switch_Threshold
	  section.data(2).logicalSrcIdx = 418;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_d0.PSEA2_Value
	  section.data(1).logicalSrcIdx = 419;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_d0.Switch_Threshold
	  section.data(2).logicalSrcIdx = 420;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_d.PSEA2_Value
	  section.data(1).logicalSrcIdx = 421;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_d.Switch_Threshold
	  section.data(2).logicalSrcIdx = 422;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_e.PSEA2_Value
	  section.data(1).logicalSrcIdx = 423;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_e.Switch_Threshold
	  section.data(2).logicalSrcIdx = 424;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_p.PSEA2_Value
	  section.data(1).logicalSrcIdx = 425;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_p.Switch_Threshold
	  section.data(2).logicalSrcIdx = 426;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_d.PSEA2_Value
	  section.data(1).logicalSrcIdx = 427;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_d.Switch_Threshold
	  section.data(2).logicalSrcIdx = 428;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_k.PSEA2_Value
	  section.data(1).logicalSrcIdx = 429;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_k.Switch_Threshold
	  section.data(2).logicalSrcIdx = 430;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_i.PSEA2_Value
	  section.data(1).logicalSrcIdx = 431;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_i.Switch_Threshold
	  section.data(2).logicalSrcIdx = 432;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_f.PSEA2_Value
	  section.data(1).logicalSrcIdx = 433;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_f.Switch_Threshold
	  section.data(2).logicalSrcIdx = 434;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_h.PSEA2_Value
	  section.data(1).logicalSrcIdx = 435;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_h.Switch_Threshold
	  section.data(2).logicalSrcIdx = 436;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1.PSEA2_Value
	  section.data(1).logicalSrcIdx = 437;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1.Switch_Threshold
	  section.data(2).logicalSrcIdx = 438;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 14;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (M43_Sim_Forcing_003h_Trajectory_B)
    ;%
      section.nData     = 132;
      section.data(132)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum9
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum15
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.TargetPSI
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum11
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Phi1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Theta1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum_j
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.SwitchControl
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum3_d
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 17;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.fromcmtom
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 18;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum1_n
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 19;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.fromcmtom_f
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 20;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum8
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 21;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum4
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 22;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum7
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 23;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum5
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 24;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.AllowedPsi
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 25;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 26;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum12
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 27;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.UnitDelay
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 28;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch1
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 34;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum_d
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 35;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 41;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum_n
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 47;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum1_k
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 53;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 59;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum_b
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 66;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum2_b
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 72;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs2
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 73;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum1_o
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 74;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum_k
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 80;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 86;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch_m
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 92;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs1
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 98;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch1_d
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 99;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA1
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 100;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs2_m
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 101;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs1_h
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 102;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch1_a
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 103;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA2
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 104;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs2_g
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 105;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs1_i
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 106;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch1_b
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 107;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA3
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 108;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs2_c
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 109;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs1_ha
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 110;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch1_n
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 111;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA4
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 112;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs2_b
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 113;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs1_f
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 114;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch1_c
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 115;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA5
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 116;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs2_f
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 117;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Abs1_f5
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 118;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch1_f
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 119;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA6
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 120;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum1_ks
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 121;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 127;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 128;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain2
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 129;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain3
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 130;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain4
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 131;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain5
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 132;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 133;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Product1
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 134;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Product4
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 135;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Product
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 138;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum5_c
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 139;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum4_k
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 140;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_l
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 141;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum4_g
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 142;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum5_d
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 143;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum4_k2
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 144;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_i
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 145;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum4_b
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 146;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_b
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 147;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum4_o
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 148;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_k
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 149;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.x_max
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 150;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum_nx
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 151;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Constant1
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 152;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Product_g
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 153;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator3
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 154;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Product1_j
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 155;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Product2
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 156;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.frommtocm
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 157;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.frommtocm_a
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 158;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.zetapi
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 159;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.pizeta
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 160;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain_f
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 161;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_j
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 167;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.out
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 173;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.out_g
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 180;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum1_j
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 187;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.out_m
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 193;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum_c
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 199;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.v_body
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 200;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.x_out
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 201;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.MultiportSwitch
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 202;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Forsavingpositionandvelocityunt
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 208;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.TSamp
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 209;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.zetaT_transferpi
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 210;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers_d
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 211;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.zetapi_b
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 212;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.pizeta_i
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 213;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.x
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 214;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.z
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 215;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.psi
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 216;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.set_out
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 217;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.R
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 223;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.d_psi
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 224;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch_mx
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 225;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch_p
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 226;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch_d
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 227;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch_n
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 228;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch_dh
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 229;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch_dx
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 230;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch_po
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 231;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_a
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 232;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_l
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 238;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_h
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 239;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.ControlLoopGain
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 240;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 246;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Divide1
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 249;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Product_k
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 250;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 253;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 265;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Switch2
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 277;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain_m
	  section.data(1).logicalSrcIdx = 150;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain2_e
	  section.data(2).logicalSrcIdx = 151;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain6
	  section.data(3).logicalSrcIdx = 152;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_e
	  section.data(4).logicalSrcIdx = 153;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain3_b
	  section.data(5).logicalSrcIdx = 154;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain4_m
	  section.data(6).logicalSrcIdx = 155;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2
	  section.data(1).logicalSrcIdx = 156;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3
	  section.data(2).logicalSrcIdx = 157;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4
	  section.data(3).logicalSrcIdx = 158;
	  section.data(3).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o5
	  section.data(4).logicalSrcIdx = 159;
	  section.data(4).dtTransOffset = 13;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1
	  section.data(5).logicalSrcIdx = 160;
	  section.data(5).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3_p
	  section.data(6).logicalSrcIdx = 161;
	  section.data(6).dtTransOffset = 17;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_o
	  section.data(7).logicalSrcIdx = 162;
	  section.data(7).dtTransOffset = 18;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_a
	  section.data(8).logicalSrcIdx = 163;
	  section.data(8).dtTransOffset = 21;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_a
	  section.data(9).logicalSrcIdx = 164;
	  section.data(9).dtTransOffset = 22;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3_k
	  section.data(10).logicalSrcIdx = 165;
	  section.data(10).dtTransOffset = 23;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4_n
	  section.data(11).logicalSrcIdx = 166;
	  section.data(11).dtTransOffset = 24;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o5_o
	  section.data(12).logicalSrcIdx = 167;
	  section.data(12).dtTransOffset = 25;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o6
	  section.data(13).logicalSrcIdx = 168;
	  section.data(13).dtTransOffset = 26;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack
	  section.data(14).logicalSrcIdx = 169;
	  section.data(14).dtTransOffset = 27;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3
	  section.data(15).logicalSrcIdx = 170;
	  section.data(15).dtTransOffset = 28;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion
	  section.data(16).logicalSrcIdx = 171;
	  section.data(16).dtTransOffset = 29;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_m
	  section.data(17).logicalSrcIdx = 172;
	  section.data(17).dtTransOffset = 35;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_p
	  section.data(18).logicalSrcIdx = 173;
	  section.data(18).dtTransOffset = 41;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b
	  section.data(19).logicalSrcIdx = 174;
	  section.data(19).dtTransOffset = 47;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4
	  section.data(20).logicalSrcIdx = 175;
	  section.data(20).dtTransOffset = 53;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_g
	  section.data(21).logicalSrcIdx = 176;
	  section.data(21).dtTransOffset = 59;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain_j
	  section.data(22).logicalSrcIdx = 177;
	  section.data(22).dtTransOffset = 60;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Sum_l
	  section.data(23).logicalSrcIdx = 178;
	  section.data(23).dtTransOffset = 61;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d
	  section.data(24).logicalSrcIdx = 179;
	  section.data(24).dtTransOffset = 62;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_c
	  section.data(25).logicalSrcIdx = 180;
	  section.data(25).dtTransOffset = 68;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_ae
	  section.data(26).logicalSrcIdx = 181;
	  section.data(26).dtTransOffset = 69;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_a
	  section.data(27).logicalSrcIdx = 182;
	  section.data(27).dtTransOffset = 70;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_pr
	  section.data(28).logicalSrcIdx = 183;
	  section.data(28).dtTransOffset = 71;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Product_m
	  section.data(29).logicalSrcIdx = 184;
	  section.data(29).dtTransOffset = 72;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion2
	  section.data(30).logicalSrcIdx = 185;
	  section.data(30).dtTransOffset = 73;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz_i
	  section.data(31).logicalSrcIdx = 186;
	  section.data(31).dtTransOffset = 79;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion2_o
	  section.data(32).logicalSrcIdx = 187;
	  section.data(32).dtTransOffset = 82;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o6
	  section.data(1).logicalSrcIdx = 194;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o6_a
	  section.data(2).logicalSrcIdx = 195;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o1
	  section.data(3).logicalSrcIdx = 196;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o1
	  section.data(4).logicalSrcIdx = 197;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o1
	  section.data(5).logicalSrcIdx = 198;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o6_b
	  section.data(6).logicalSrcIdx = 199;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o6_m
	  section.data(7).logicalSrcIdx = 200;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o1_f
	  section.data(8).logicalSrcIdx = 201;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX
	  section.data(9).logicalSrcIdx = 202;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX1
	  section.data(10).logicalSrcIdx = 203;
	  section.data(10).dtTransOffset = 9;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX2
	  section.data(11).logicalSrcIdx = 204;
	  section.data(11).dtTransOffset = 10;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX_b
	  section.data(12).logicalSrcIdx = 205;
	  section.data(12).dtTransOffset = 11;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX1_e
	  section.data(13).logicalSrcIdx = 206;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o2
	  section.data(1).logicalSrcIdx = 208;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o2_d
	  section.data(2).logicalSrcIdx = 209;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o6
	  section.data(3).logicalSrcIdx = 210;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o6
	  section.data(4).logicalSrcIdx = 211;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o6
	  section.data(5).logicalSrcIdx = 212;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o2_p
	  section.data(6).logicalSrcIdx = 213;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o2_l
	  section.data(7).logicalSrcIdx = 214;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o6_h
	  section.data(8).logicalSrcIdx = 215;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o5
	  section.data(1).logicalSrcIdx = 216;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o5_c
	  section.data(2).logicalSrcIdx = 217;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o5_f
	  section.data(3).logicalSrcIdx = 218;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o5_g
	  section.data(4).logicalSrcIdx = 219;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 53;
      section.data(53)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1
	  section.data(1).logicalSrcIdx = 223;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o4
	  section.data(2).logicalSrcIdx = 224;
	  section.data(2).dtTransOffset = 66;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c
	  section.data(3).logicalSrcIdx = 225;
	  section.data(3).dtTransOffset = 70;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_o
	  section.data(4).logicalSrcIdx = 226;
	  section.data(4).dtTransOffset = 80;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o4_k
	  section.data(5).logicalSrcIdx = 227;
	  section.data(5).dtTransOffset = 104;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p
	  section.data(6).logicalSrcIdx = 228;
	  section.data(6).dtTransOffset = 108;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Compare
	  section.data(7).logicalSrcIdx = 229;
	  section.data(7).dtTransOffset = 116;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2
	  section.data(8).logicalSrcIdx = 230;
	  section.data(8).dtTransOffset = 117;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o3
	  section.data(9).logicalSrcIdx = 231;
	  section.data(9).dtTransOffset = 125;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o4
	  section.data(10).logicalSrcIdx = 232;
	  section.data(10).dtTransOffset = 126;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2
	  section.data(11).logicalSrcIdx = 233;
	  section.data(11).dtTransOffset = 127;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o3
	  section.data(12).logicalSrcIdx = 234;
	  section.data(12).dtTransOffset = 135;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o4
	  section.data(13).logicalSrcIdx = 235;
	  section.data(13).dtTransOffset = 136;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2
	  section.data(14).logicalSrcIdx = 236;
	  section.data(14).dtTransOffset = 137;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o3
	  section.data(15).logicalSrcIdx = 237;
	  section.data(15).dtTransOffset = 145;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o4
	  section.data(16).logicalSrcIdx = 238;
	  section.data(16).dtTransOffset = 146;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_f
	  section.data(17).logicalSrcIdx = 239;
	  section.data(17).dtTransOffset = 147;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o4_b
	  section.data(18).logicalSrcIdx = 240;
	  section.data(18).dtTransOffset = 171;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_d
	  section.data(19).logicalSrcIdx = 241;
	  section.data(19).dtTransOffset = 175;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o4_g
	  section.data(20).logicalSrcIdx = 242;
	  section.data(20).dtTransOffset = 179;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2_d
	  section.data(21).logicalSrcIdx = 243;
	  section.data(21).dtTransOffset = 183;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o3_e
	  section.data(22).logicalSrcIdx = 244;
	  section.data(22).dtTransOffset = 191;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o4_d
	  section.data(23).logicalSrcIdx = 245;
	  section.data(23).dtTransOffset = 192;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.BytePacking
	  section.data(24).logicalSrcIdx = 246;
	  section.data(24).dtTransOffset = 193;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.BytePacking1
	  section.data(25).logicalSrcIdx = 247;
	  section.data(25).dtTransOffset = 265;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.BytePacking2
	  section.data(26).logicalSrcIdx = 248;
	  section.data(26).dtTransOffset = 289;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_p
	  section.data(27).logicalSrcIdx = 249;
	  section.data(27).dtTransOffset = 313;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain2_b
	  section.data(28).logicalSrcIdx = 250;
	  section.data(28).dtTransOffset = 314;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain3_i
	  section.data(29).logicalSrcIdx = 251;
	  section.data(29).dtTransOffset = 315;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain4_b
	  section.data(30).logicalSrcIdx = 252;
	  section.data(30).dtTransOffset = 316;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_a
	  section.data(31).logicalSrcIdx = 253;
	  section.data(31).dtTransOffset = 317;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain2_g
	  section.data(32).logicalSrcIdx = 254;
	  section.data(32).dtTransOffset = 318;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain3_be
	  section.data(33).logicalSrcIdx = 255;
	  section.data(33).dtTransOffset = 319;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain4_n
	  section.data(34).logicalSrcIdx = 256;
	  section.data(34).dtTransOffset = 320;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_n
	  section.data(35).logicalSrcIdx = 257;
	  section.data(35).dtTransOffset = 321;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain2_l
	  section.data(36).logicalSrcIdx = 258;
	  section.data(36).dtTransOffset = 322;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain3_ic
	  section.data(37).logicalSrcIdx = 259;
	  section.data(37).dtTransOffset = 323;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain4_g
	  section.data(38).logicalSrcIdx = 260;
	  section.data(38).dtTransOffset = 324;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_op
	  section.data(39).logicalSrcIdx = 261;
	  section.data(39).dtTransOffset = 325;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain2_ga
	  section.data(40).logicalSrcIdx = 262;
	  section.data(40).dtTransOffset = 326;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain3_l
	  section.data(41).logicalSrcIdx = 263;
	  section.data(41).dtTransOffset = 327;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain4_c
	  section.data(42).logicalSrcIdx = 264;
	  section.data(42).dtTransOffset = 328;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_d
	  section.data(43).logicalSrcIdx = 265;
	  section.data(43).dtTransOffset = 329;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain2_f
	  section.data(44).logicalSrcIdx = 266;
	  section.data(44).dtTransOffset = 330;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain3_d
	  section.data(45).logicalSrcIdx = 267;
	  section.data(45).dtTransOffset = 331;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain4_k
	  section.data(46).logicalSrcIdx = 268;
	  section.data(46).dtTransOffset = 332;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain1_p2
	  section.data(47).logicalSrcIdx = 269;
	  section.data(47).dtTransOffset = 333;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain2_p
	  section.data(48).logicalSrcIdx = 270;
	  section.data(48).dtTransOffset = 334;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain3_ha
	  section.data(49).logicalSrcIdx = 271;
	  section.data(49).dtTransOffset = 335;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.Gain4_h
	  section.data(50).logicalSrcIdx = 272;
	  section.data(50).dtTransOffset = 336;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.BytePacking_g
	  section.data(51).logicalSrcIdx = 273;
	  section.data(51).dtTransOffset = 337;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.BytePacking1_m
	  section.data(52).logicalSrcIdx = 274;
	  section.data(52).dtTransOffset = 365;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.SumofElements
	  section.data(53).logicalSrcIdx = 275;
	  section.data(53).dtTransOffset = 397;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o3
	  section.data(1).logicalSrcIdx = 276;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o3_o
	  section.data(2).logicalSrcIdx = 277;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o5
	  section.data(3).logicalSrcIdx = 278;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o5
	  section.data(4).logicalSrcIdx = 279;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o5
	  section.data(5).logicalSrcIdx = 280;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o3_l
	  section.data(6).logicalSrcIdx = 281;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o3_d
	  section.data(7).logicalSrcIdx = 282;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator
	  section.data(8).logicalSrcIdx = 283;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o5_i
	  section.data(9).logicalSrcIdx = 284;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator_a
	  section.data(10).logicalSrcIdx = 285;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_e.Switch
	  section.data(1).logicalSrcIdx = 286;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d0.Switch
	  section.data(1).logicalSrcIdx = 287;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_d.Switch
	  section.data(2).logicalSrcIdx = 288;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_e.Switch
	  section.data(1).logicalSrcIdx = 289;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_p.Switch
	  section.data(2).logicalSrcIdx = 290;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d.Switch
	  section.data(1).logicalSrcIdx = 291;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_k.Switch
	  section.data(2).logicalSrcIdx = 292;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_i.Switch
	  section.data(1).logicalSrcIdx = 293;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_f.Switch
	  section.data(2).logicalSrcIdx = 294;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_h.Switch
	  section.data(1).logicalSrcIdx = 295;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1.Switch
	  section.data(2).logicalSrcIdx = 296;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 19;
    sectIdxOffset = 14;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (M43_Sim_Forcing_003h_Trajectory_DWork)
    ;%
      section.nData     = 39;
      section.data(39)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_d
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_c
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_e
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_d
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_i
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_g
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_f
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay_DSTATE
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_l
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_b
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 22;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay6_DSTATE
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 28;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 34;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_k
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 58;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 59;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 60;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ds
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 64;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_n
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 65;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_b
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 66;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_o
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 67;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ko
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 68;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_DSTATE
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 69;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 70;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.Forsavingpositionandvelocityunt
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 71;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.UD_DSTATE
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 72;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE_i
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 73;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE_p
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 74;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.Sum2_DWORK1
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 75;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.Sum1_DWORK1
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 76;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 82;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.PrevY
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 88;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_n
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 89;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_i
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 90;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_b
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 91;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_bp
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 92;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_p
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 93;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_f
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 94;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK_b
	  section.data(3).logicalSrcIdx = 41;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK_f
	  section.data(4).logicalSrcIdx = 42;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX1_PWORK
	  section.data(5).logicalSrcIdx = 43;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX2_PWORK
	  section.data(6).logicalSrcIdx = 44;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX3_PWORK
	  section.data(7).logicalSrcIdx = 45;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK_l
	  section.data(8).logicalSrcIdx = 46;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK_g
	  section.data(9).logicalSrcIdx = 47;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK_bv
	  section.data(10).logicalSrcIdx = 48;
	  section.data(10).dtTransOffset = 9;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK_l
	  section.data(11).logicalSrcIdx = 49;
	  section.data(11).dtTransOffset = 10;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.INC_Comparison_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 50;
	  section.data(12).dtTransOffset = 11;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.J_ANG_ERROR_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 51;
	  section.data(13).dtTransOffset = 12;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.ANG_ACT_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 52;
	  section.data(14).dtTransOffset = 13;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.POS_ACT_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 53;
	  section.data(15).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.ANGCOM_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 54;
	  section.data(16).dtTransOffset = 15;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.POSCOM_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 55;
	  section.data(17).dtTransOffset = 16;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.Scope_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 56;
	  section.data(18).dtTransOffset = 17;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.Scope1_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 57;
	  section.data(19).dtTransOffset = 18;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX2_PWORK_a
	  section.data(20).logicalSrcIdx = 58;
	  section.data(20).dtTransOffset = 19;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANController_PWORK
	  section.data(21).logicalSrcIdx = 59;
	  section.data(21).dtTransOffset = 20;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX_PWORK
	  section.data(22).logicalSrcIdx = 60;
	  section.data(22).dtTransOffset = 21;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX_PWORK_l
	  section.data(23).logicalSrcIdx = 61;
	  section.data(23).dtTransOffset = 22;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX_PWORK
	  section.data(24).logicalSrcIdx = 62;
	  section.data(24).dtTransOffset = 23;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX1_PWORK
	  section.data(25).logicalSrcIdx = 63;
	  section.data(25).dtTransOffset = 25;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX2_PWORK
	  section.data(26).logicalSrcIdx = 64;
	  section.data(26).dtTransOffset = 27;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite_PWORK
	  section.data(27).logicalSrcIdx = 65;
	  section.data(27).dtTransOffset = 29;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite1_PWORK
	  section.data(28).logicalSrcIdx = 66;
	  section.data(28).dtTransOffset = 30;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite2_PWORK
	  section.data(29).logicalSrcIdx = 67;
	  section.data(29).dtTransOffset = 31;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX_PWORK_j
	  section.data(30).logicalSrcIdx = 68;
	  section.data(30).dtTransOffset = 32;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX1_PWORK
	  section.data(31).logicalSrcIdx = 69;
	  section.data(31).dtTransOffset = 33;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX2_PWORK
	  section.data(32).logicalSrcIdx = 70;
	  section.data(32).dtTransOffset = 34;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX_PWORK_o
	  section.data(33).logicalSrcIdx = 71;
	  section.data(33).dtTransOffset = 35;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX1_PWORK_f
	  section.data(34).logicalSrcIdx = 72;
	  section.data(34).dtTransOffset = 37;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite_PWORK_m
	  section.data(35).logicalSrcIdx = 73;
	  section.data(35).dtTransOffset = 39;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite1_PWORK_j
	  section.data(36).logicalSrcIdx = 74;
	  section.data(36).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g
	  section.data(2).logicalSrcIdx = 76;
	  section.data(2).dtTransOffset = 12;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_n
	  section.data(3).logicalSrcIdx = 77;
	  section.data(3).dtTransOffset = 13;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f
	  section.data(4).logicalSrcIdx = 78;
	  section.data(4).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_p
	  section.data(5).logicalSrcIdx = 79;
	  section.data(5).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.Add_DWORK1
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK_a
	  section.data(2).logicalSrcIdx = 82;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK_j
	  section.data(3).logicalSrcIdx = 83;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK_p
	  section.data(4).logicalSrcIdx = 84;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.BytePacking_IWORK
	  section.data(5).logicalSrcIdx = 85;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.BytePacking1_IWORK
	  section.data(6).logicalSrcIdx = 86;
	  section.data(6).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.BytePacking2_IWORK
	  section.data(7).logicalSrcIdx = 87;
	  section.data(7).dtTransOffset = 16;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.BytePacking_IWORK_m
	  section.data(8).logicalSrcIdx = 88;
	  section.data(8).dtTransOffset = 18;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.BytePacking1_IWORK_e
	  section.data(9).logicalSrcIdx = 89;
	  section.data(9).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRese
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_PrevRes
	  section.data(2).logicalSrcIdx = 91;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.MoveUP1_SubsysRanBC
	  section.data(3).logicalSrcIdx = 92;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevRes
	  section.data(4).logicalSrcIdx = 93;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_p
	  section.data(5).logicalSrcIdx = 94;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork._DOFControl_SubsysRanBC
	  section.data(6).logicalSrcIdx = 95;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.SimplifiedInverseKin_SubsysRanB
	  section.data(7).logicalSrcIdx = 96;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_k
	  section.data(8).logicalSrcIdx = 97;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRe_d
	  section.data(9).logicalSrcIdx = 98;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.fullinversekin_SubsysRanBC
	  section.data(10).logicalSrcIdx = 99;
	  section.data(10).dtTransOffset = 9;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork._DOFVisualCab120615_SubsysRanBC
	  section.data(11).logicalSrcIdx = 100;
	  section.data(11).dtTransOffset = 10;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_SubsysRanBC
	  section.data(12).logicalSrcIdx = 101;
	  section.data(12).dtTransOffset = 11;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_SubsysRanBC
	  section.data(13).logicalSrcIdx = 102;
	  section.data(13).dtTransOffset = 12;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_b
	  section.data(14).logicalSrcIdx = 103;
	  section.data(14).dtTransOffset = 13;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_f
	  section.data(15).logicalSrcIdx = 104;
	  section.data(15).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_PrevRes
	  section.data(16).logicalSrcIdx = 105;
	  section.data(16).dtTransOffset = 15;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_SubsysRanBC_p
	  section.data(17).logicalSrcIdx = 106;
	  section.data(17).dtTransOffset = 16;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_SubsysRanB_l
	  section.data(18).logicalSrcIdx = 107;
	  section.data(18).dtTransOffset = 17;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_PrevResetStat
	  section.data(19).logicalSrcIdx = 108;
	  section.data(19).dtTransOffset = 18;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_PrevResetStat
	  section.data(20).logicalSrcIdx = 109;
	  section.data(20).dtTransOffset = 19;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_c
	  section.data(21).logicalSrcIdx = 110;
	  section.data(21).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_IC_LOAD
	  section.data(1).logicalSrcIdx = 111;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_IC_LOADI
	  section.data(2).logicalSrcIdx = 112;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c7_M43_Sim_Forcing_00
	  section.data(3).logicalSrcIdx = 113;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c6_M43_Sim_Forcing_00
	  section.data(4).logicalSrcIdx = 114;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c5_M43_Sim_Forcing_00
	  section.data(5).logicalSrcIdx = 115;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c10_M43_Sim_Forcing_0
	  section.data(6).logicalSrcIdx = 116;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c2_M43_Sim_Forcing_00
	  section.data(7).logicalSrcIdx = 117;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_IC_LOADING
	  section.data(8).logicalSrcIdx = 118;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_IC_LOADING
	  section.data(9).logicalSrcIdx = 119;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c8_M43_Sim_Forcing_00
	  section.data(10).logicalSrcIdx = 120;
	  section.data(10).dtTransOffset = 9;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c1_M43_Sim_Forcing_00
	  section.data(11).logicalSrcIdx = 121;
	  section.data(11).dtTransOffset = 10;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c4_M43_Sim_Forcing_00
	  section.data(12).logicalSrcIdx = 122;
	  section.data(12).dtTransOffset = 11;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c3_M43_Sim_Forcing_00
	  section.data(13).logicalSrcIdx = 123;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.isStable
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 125;
	  section.data(2).dtTransOffset = 1;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.isStable_f
	  section.data(3).logicalSrcIdx = 126;
	  section.data(3).dtTransOffset = 2;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.doneDoubleBufferReInit_j
	  section.data(4).logicalSrcIdx = 127;
	  section.data(4).dtTransOffset = 3;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.isStable_fp
	  section.data(5).logicalSrcIdx = 128;
	  section.data(5).dtTransOffset = 4;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.doneDoubleBufferReInit_o
	  section.data(6).logicalSrcIdx = 129;
	  section.data(6).dtTransOffset = 5;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.isStable_m
	  section.data(7).logicalSrcIdx = 130;
	  section.data(7).dtTransOffset = 6;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.doneDoubleBufferReInit_jd
	  section.data(8).logicalSrcIdx = 131;
	  section.data(8).dtTransOffset = 7;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.isStable_fz
	  section.data(9).logicalSrcIdx = 132;
	  section.data(9).dtTransOffset = 8;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.doneDoubleBufferReInit_e
	  section.data(10).logicalSrcIdx = 133;
	  section.data(10).dtTransOffset = 9;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.isStable_m5
	  section.data(11).logicalSrcIdx = 134;
	  section.data(11).dtTransOffset = 10;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.doneDoubleBufferReInit_k
	  section.data(12).logicalSrcIdx = 135;
	  section.data(12).dtTransOffset = 11;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.isStable_l
	  section.data(13).logicalSrcIdx = 136;
	  section.data(13).dtTransOffset = 12;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.doneDoubleBufferReInit_c
	  section.data(14).logicalSrcIdx = 137;
	  section.data(14).dtTransOffset = 13;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.isStable_fk
	  section.data(15).logicalSrcIdx = 138;
	  section.data(15).dtTransOffset = 14;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.doneDoubleBufferReInit_m
	  section.data(16).logicalSrcIdx = 139;
	  section.data(16).dtTransOffset = 15;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.isStable_a
	  section.data(17).logicalSrcIdx = 140;
	  section.data(17).dtTransOffset = 16;
	
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.doneDoubleBufferReInit_n
	  section.data(18).logicalSrcIdx = 141;
	  section.data(18).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d0.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_d.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_e.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_p.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 146;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 147;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_k.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 148;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_i.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 149;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 150;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 151;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 152;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2587801539;
  targMap.checksum1 = 3199151868;
  targMap.checksum2 = 3146686446;
  targMap.checksum3 = 2988718197;

