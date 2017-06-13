#include"CGUI.hpp"

// -- Konstruktor --
CGUI::CGUI(CAttractors *attr) {
	// Alloc Mem
	_hopCtrlBtn_lbl = new std::string();
	_edges_num = new int;
	_hopping = new bool;

	// Werte setzen
	_cir_radii.x = 2.F;
	_cir_radii.y = 5.F;
	_cir_radii.z = 3.F;
	attr->setDotRadius(_cir_radii.x);
	attr->setEdgeRadius(_cir_radii.y);
	attr->tracePoint->setRadius(_cir_radii.z);

	*_edges_num = 3;
	attr->addShape(*_edges_num, 400.F, sf::Vector2f(400.F, 400.F));

	*_hopping = false;
	*_hopCtrlBtn_lbl = "Starten";
}

// Methode verwaltet und zeigt das GUI an
// @param rWin   : Aktuelles Fenster
// @param curAttr: Aktuelles Attractors Objekt
//
bool CGUI::showGUI(sf::RenderWindow &rWin, CAttractors *curAttr) {
	ImGui::Begin("Master Control");

	// Ecken-Anzahl abfragen
	if (ImGui::InputInt(EDGES_NUM_INB, _edges_num)) {
		curAttr->reset();
		curAttr->addShape(*_edges_num, 400.F, sf::Vector2f(400.F, 400.F));
	}

	// Dot-Farbe abfragen
	if (ImGui::ColorEdit3(DOT_COLOR, _dt_color)) {
		curAttr->setDotColor(sf::Color(
			static_cast<sf::Uint8>(_dt_color[0] * 255.F),
			static_cast<sf::Uint8>(_dt_color[1] * 255.F),
			static_cast<sf::Uint8>(_dt_color[2] * 255.F)));
	}

	// Ecken-Farbe abfragen
	if (ImGui::ColorEdit3(EDGE_COLOR_CE, _eg_color)) {
		curAttr->setEdgeColor(sf::Color(
			static_cast<sf::Uint8>(_eg_color[0] * 255.F),
			static_cast<sf::Uint8>(_eg_color[1] * 255.F),
			static_cast<sf::Uint8>(_eg_color[2] * 255.F)));
	}

	// TracePoint-Farbe abfragen
	if (ImGui::ColorEdit3(TRACEP_COLOR_CE, _tp_color)) {
		curAttr->tracePoint->setFillColor(sf::Color(
			static_cast<sf::Uint8>(_tp_color[0] * 255.F),
			static_cast<sf::Uint8>(_tp_color[1] * 255.F),
			static_cast<sf::Uint8>(_tp_color[2] * 255.F)));
	}

	// Dot-Radius abfragen
	if (ImGui::InputFloat(DOT_R_IN, &_cir_radii.x))
		curAttr->setDotRadius(_cir_radii.x);

	// Ecken-Radius abfragen
	if (ImGui::InputFloat(EDGE_R_IN, &_cir_radii.y))
		curAttr->setEdgeRadius(_cir_radii.y);

	// TracePoint-Radius abfragen
	if (ImGui::InputFloat(TP_R_IN, &_cir_radii.z))
		curAttr->tracePoint->setRadius(_cir_radii.z);

	// Start/Stop-Knopf
	if (*_hopping) {
		*_hopCtrlBtn_lbl = "Stoppen";
		curAttr->hop();
	} else {
		*_hopCtrlBtn_lbl = "Starten";
	}

	if (ImGui::Button(_hopCtrlBtn_lbl->c_str()))
		*_hopping = !(*_hopping);

	// Abfragen ob ein hop gemacht werden soll
	if (ImGui::Button(ONE_HOP))
		curAttr->hop();

	ImGui::End();

	return true;
}

// -- Destruktor --
CGUI::~CGUI() {
	SAFE_DELETE(_hopCtrlBtn_lbl);
	SAFE_DELETE(_edges_num);
	SAFE_DELETE(_hopping);
}