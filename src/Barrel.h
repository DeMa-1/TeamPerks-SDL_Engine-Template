#pragma once
#include "DisplayObject.h"
#include "Animation.h"
#include "PlayerAnimationState.h"
#include <unordered_map>
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

	void setAnimation(const Animation& animation);

private:
	void m_buildAnimations();
	void Animate();
	PlayerAnimationState m_currentAnimationState;
	SpriteSheet* m_pSpriteSheet;
	std::unordered_map<std::string, Animation> m_pAnimations;

};

