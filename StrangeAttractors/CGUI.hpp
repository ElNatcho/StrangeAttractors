#ifndef CGUI_HPP
#define CGUI_HPP

// Includes
#include<imgui-SFML.h>
#include<imgui.h>
#include<iostream>
#include<string>
#include"CAttractors.hpp"

#define EDGES_NUM_INB "Ecken Anzahl"

#define DOT_COLOR "Dot Farbe"
#define EDGE_COLOR_CE "Ecken Farbe"
#define TRACEP_COLOR_CE "TracePoint Farbe"

#define DOT_R_IN "Dot Radius"
#define EDGE_R_IN "Ecken Radius"
#define TP_R_IN "TracePoint Radius"

#define REL_HOP_DIST "Relative Hop-Entfernung"

#define ONE_HOP "Einen Hop"

#define RESET_BTN "Reset"

// CGUI
class CGUI {
public:

	// -- Kon/Destruktor --
	CGUI(CAttractors *attr);
	~CGUI();

	// -- Methoden --
	bool showGUI(sf::RenderWindow &rWin, CAttractors *curAttr);

private:

	// -- Member Vars --
	int *_edges_num;
	
	float _tp_color[3] = { 0.F, 1.F, 0.F };
	float _eg_color[3] = { 1.F, 0.F, 0.F };
	float _dt_color[3] = { 0.F, 0.F, 1.F };

	struct v3 {
		float x;
		float y;
		float z;
	} _cir_radii;

	bool *_hopping;
	float *_relHopDist;
	std::string *_hopCtrlBtn_lbl;

};

#endif