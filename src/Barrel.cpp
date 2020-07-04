#include "Barrel.h"
#include "SpriteSheet.h"
#include "Animation.h"
#include <map>
#include "TextureManager.h"
#include "StaticSprite.h"
#include "GameObject.h"

Barrel::Barrel()
{
	TheTextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/Barrels.txt",
		"../Assets/sprites/Barrels.png",
		"Barrels");

	m_pSpriteSheet = TheTextureManager::Instance()->getSpriteSheet("Barrels");
	m_pSpriteSheet->setWidthAndHeight(128, 128);
	// set frame width
	setWidth(64);

	//set frame height
	setHeight(64);

	getTransform()->position = glm::vec2(600.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(BACKGROUND);

	m_buildAnimations();

}

Barrel::~Barrel()
{
}

void Barrel::draw()
{
	Animate();
}

void Barrel::update()
{
	static int tempCounter = 0;
	if (tempCounter > 120) {
		int randomNum = rand() % 2;
		if (randomNum == 0)
		{
			m_currentAnimationState = ABILITY_UP;
		}
		
		//m_currentAnimationState = static_cast<PlayerAnimationState>(rand() % 8); //num of animation states

		tempCounter = 0;
	}
	tempCounter++;
}

void Barrel::clean()
{
}

void Barrel::setAnimation(const Animation& animation)
{
}

void Barrel::m_buildAnimations()
{
	Animation barrelidleAnimation = Animation();
	barrelidleAnimation.name = "barrels_up";

	barrelidleAnimation.frames.push_back(m_pSpriteSheet->getFrame("Barrels_idle1"));
	barrelidleAnimation.frames.push_back(m_pSpriteSheet->getFrame("Barrels_idle2"));
	barrelidleAnimation.frames.push_back(m_pSpriteSheet->getFrame("Barrels_idle3"));
	barrelidleAnimation.frames.push_back(m_pSpriteSheet->getFrame("Barrels_idel4"));
	m_pAnimations["barrels_up"] = barrelidleAnimation;

	Animation barrelfallAnimation = Animation();
	barrelfallAnimation.name = "barrels_fall";
	barrelfallAnimation.frames.push_back(m_pSpriteSheet->getFrame("Barrels_fellover1"));
	m_pAnimations["barrels_fall"] = barrelfallAnimation;
	

}

void Barrel::Animate()
{
}
