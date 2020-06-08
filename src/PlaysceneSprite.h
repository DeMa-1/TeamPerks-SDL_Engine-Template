#pragma once

#include "DisplayObject.h"
#include "TextureManager.h"


class PlaysceneSprite : public DisplayObject
{
public:
	PlaysceneSprite();
	~PlaysceneSprite();

	// Life Cycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

};
