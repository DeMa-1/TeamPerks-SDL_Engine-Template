#include "Button.h"
#include <utility>
#include "CollisionManager.h"
#include "TextureManager.h"
#include "EventManager.h"


/**
 * @brief Construct a new Button:: Button object
 * 
 * @param image_path 
 * @param button_name 
 * @param type 
 * @param position 
 * @param is_centered 
 */
Button::Button(const std::string& image_path, std::string button_name, const GameObjectType type,
               const glm::vec2 position, const bool is_centered):
m_alpha(255), m_name(std::move(button_name)), m_isCentered(is_centered),
m_mouseOver(false), m_mouseOverActive(false), m_mouseOutActive(false), m_active(true)
{
	TheTextureManager::Instance()->load(image_path,m_name);

	const auto size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	getTransform()->position = position;
	setType(type);
}

Button::~Button()
= default;

void Button::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the button
	TheTextureManager::Instance()->draw(m_name, x, y, 0, m_alpha, true);
}

void Button::update()
{
	m_mousePosition = EventManager::Instance().getMousePosition();

	//check mouse position
	m_checkMouseOverAndOut();

	// check if left mouse is clicked
	if (EventManager::Instance().getMouseButton(LEFT))
	{
		if ((m_events[CLICK]) && (m_mouseOver) && !m_mouseButtonClicked)
		{
			m_mouseButtonClicked = true;
			m_events[CLICK](this); // call click event
		}
	}
	else
	{
		m_mouseButtonClicked = false;
	}
}

void Button::clean()
{
}

void Button::m_checkMouseOverAndOut()
{
	if (CollisionManager::pointRectCheck(m_mousePosition, getTransform()->position, getWidth(), getHeight()))
	{
		m_mouseOver = true;
	}
	else
	{
		m_mouseOver = false;
	}

	if ((m_events[MOUSE_OVER]) && (!m_mouseOverActive))
	{
		if (m_mouseOver)
		{
			m_events[MOUSE_OVER](this);
			m_mouseOverActive = true;
		}
	}
	else if ((m_events[MOUSE_OVER]) && (!m_mouseOver))
	{
		m_mouseOverActive = false;
	}

	if ((m_events[MOUSE_OUT]) && (m_mouseOutActive) && (!m_mouseOver))
	{
		m_events[MOUSE_OUT](this);
		m_mouseOutActive = false;
	}
	else if ((m_events[MOUSE_OUT]) && (m_mouseOver))
	{
		m_mouseOutActive = true;
	}
}

/**
 * @brief checks to see if an event type has been registered
 * 
 * @param id 
 * @return true 
 * @return false 
 */
bool Button::m_eventExists(const Event id)
{
	return m_events.find(id) != m_events.end();
}


/**
 * @brief registers a new event listener for the button
 * options are CLICK, MOUSE_OVER, MOUSE_OUT
 * 
 * @param event 
 * @param handler 
 * @return true 
 * @return false 
 */
bool Button::addEventListener(const Event event, const EventHandler handler)
{
	if(m_eventExists(event))
	{
		return false;
	}
	
	m_events[event] = handler;
	return true;
}

Button::EventHandler Button::getEventHandler(const Event event)
{
	return m_events[event];
}

/**
 * @brief sets the alpha transparency of the button
 * @param alpha
 * @return void
 */
void Button::setAlpha(const Uint8 alpha)
{
	m_alpha = alpha;
}

/**
 * @brief sets the button active boolean
 * @return void
 */
void Button::setActive(const bool value)
{
	m_active = value;
}
