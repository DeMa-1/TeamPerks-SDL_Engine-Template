#include "PlaneSprite.h"
#include "TextureManager.h"

PlaneSprite::PlaneSprite()
{
	TheTextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/spider03.png, spritesheet");

	m_pSpriteSheet = TheTextureManager::Instance()->getSpriteSheet("spritesheet");

	// set frame width
	setWidth(65);

	// set frame height
	setHeight(65);

	getTransform()->position = glm::vec2(400.0f, 200.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLANE);

	m_buildAnimations();
}

PlaneSprite::~PlaneSprite()
= default;

void PlaneSprite::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// drawing spider animation
	TheTextureManager::Instance()->playAnimation(
		"spritesheet", m_pAnimations["spider"],
		x, y, 0.5f, 0, 255, true);
}

void PlaneSprite::update()
{
}

void PlaneSprite::clean()
{
}

void PlaneSprite::setAnimation(const Animation& animation)
{
	m_pAnimations[animation.name] = animation;
}

void PlaneSprite::m_buildAnimations()
{
	Animation planeAnimation = Animation();

	planeAnimation.name = "spider";
	planeAnimation.frames.push_back(m_pSpriteSheet->getFrame("spider03-idle"));
	planeAnimation.frames.push_back(m_pSpriteSheet->getFrame("spider03-move2"));
	planeAnimation.frames.push_back(m_pSpriteSheet->getFrame("spidr03-move3"));

	m_pAnimations["spider"] = planeAnimation;
}





