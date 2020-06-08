#include "PlaysceneSprite.h"

PlaysceneSprite::PlaysceneSprite()
{
	TheTextureManager::Instance()->load("../Assets/textures/MapPlayscene.png", "MapPlayscene");

	auto size = TheTextureManager::Instance()->getTextureSize("MapPlayscene");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 200.0f);
	setType(TITLESPRITE);

}

PlaysceneSprite::~PlaysceneSprite()
{
}

void PlaysceneSprite::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the ship
	TheTextureManager::Instance()->draw("MapPlayscene", x, y, 0, 255, true);
}

void PlaysceneSprite::update()
{
}

void PlaysceneSprite::clean()
{
}
