#pragma once

#include "Constants.h"

using namespace std;

// COMPONENTES
using cmpId_type = unsigned int;

enum cmpId : cmpId_type {
	_TRANSFORM,
	_HEALTH,
	_BLOCK,
	_INPUT,
	_UI,
	_COLLIDER,
	_WEAPON,
	_BULLET,
	_PICKUP,

	//DO NOT REMOVE THIS
	_LAST_CMP_ID
};

constexpr cmpId_type maxComponentId = _LAST_CMP_ID;

// GRUPOS
using grpId_type = unsigned int;

enum grpId : grpId_type {
	_grp_GENERAL,
	_grp_WEAPONS,
	_grp_BULLETS,
	_grp_MAP,
	_grp_UI,

	//DO NOT REMOVE THIS
	_LAST_GRP_ID
};

constexpr grpId_type maxGroupId = _LAST_GRP_ID;

// HANDLER
using hdlrId_type = unsigned int;

enum hdlrId : hdlrId_type {
	_hdlr_FIGHTER,

	//DO NOT REMOVE THIS
	_LAST_HDLR_ID
};

constexpr hdlrId_type maxHandlerId = _LAST_HDLR_ID;

//#include <functional>
//// Tipo de funcion que devuelve y recibe void, funciona tambion con funciones lambda con capturas
//class Entity;
//using CallBackCol = std::function<void(Entity*)>;