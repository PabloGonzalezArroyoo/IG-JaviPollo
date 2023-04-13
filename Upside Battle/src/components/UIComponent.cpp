#include "UIComponent.h"

UIComponent::UIComponent(int p) : player(p), points(0) { }

void UIComponent::initComponent() {
	tr = myObj->getComponent<Transform>();

	uiPlayerBox.x = tr->getPosition().x;
	uiPlayerBox.y = tr->getPosition().y;
	uiPlayerBox.width = tr->getWidth() / 4;
	uiPlayerBox.height = tr->getHeight();

	uiPointsBox.x = uiPlayerBox.x + uiPlayerBox.width;
	uiPointsBox.y = tr->getPosition().y;
	uiPointsBox.width = tr->getWidth() - (tr->getWidth() / 4);
	uiPointsBox.height = tr->getHeight();

	uiPoints.load("../../resources/phantomstorm.ttf", HUD_FONT_SIZE);
	uiPlayer.load("../../resources/phantomstorm.ttf", HUD_FONT_SIZE);
}

void UIComponent::render() {
	if (player == 1) ofSetColor(219, 131, 33);
	else ofSetColor(135, 168, 14);
	ofDrawRectangle(uiPlayerBox.position, uiPlayerBox.width, uiPlayerBox.height);

	if (player == 1) ofSetColor(200, 125, 30);
	else ofSetColor(116, 162, 11);
	ofDrawRectangle(uiPointsBox.position, uiPointsBox.width, uiPointsBox.height);

	ofSetColor(12, 12, 12);
	playerString = "P" + to_string(player);
	uiPlayer.drawString(playerString,
		uiPlayerBox.x + uiPlayerBox.width / 2 - uiPlayer.stringWidth(playerString) / 2,
		uiPlayerBox.y + uiPlayerBox.height / 2 + HUD_FONT_SIZE / 2);
	pointsString = to_string(points) + " / 25";
	uiPoints.drawString(pointsString,
		uiPointsBox.x + uiPointsBox.width / 2 - uiPoints.stringWidth(pointsString) / 2,
		uiPointsBox.y + uiPointsBox.height / 2 + HUD_FONT_SIZE / 2);
}

void UIComponent::updatePoints(int pts) {
	points += pts;
}