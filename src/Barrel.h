#pragma once
#include "SpriteSheet.h"
#include "TextureManager.h"
#include "StaticSprite.h"
#include "GameObject.h"
#include "DisplayObject.h"
#include "Animation.h"
#include <map>
#include "DisplayObject.h"
#include "PlayerAnimationState.h"
#include "SpriteSheet.h"
class Barrel : Scene
{
public:
	Barrel();
	~Barrel();

	// Life Cycle Functions
	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void m_buildAnimations();
	void Animate();
	PlayerAnimationState m_currentAnimationState;
	SpriteSheet* m_pSpriteSheet;
	std::unordered_map<std::string, Animation> m_pAnimations;

};

