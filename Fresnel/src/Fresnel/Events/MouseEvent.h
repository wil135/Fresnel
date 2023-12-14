#pragma once

#include "Event.h"
#include <sstream>

namespace Fresnel
{
	class FRESNEL_API MouseMoveEvent
		: public Event
	{
	private:
		float m_MouseX, m_MouseY;
	public:
		MouseMoveEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y)
		{
		}

		inline float getX() const { return m_MouseX; }
		inline float getY() const { return m_MouseY; }

		std::string toString() const override
		{
			std::stringstream returnVal;
			returnVal << "MouseMoveEvent: " << m_MouseX << ", " << m_MouseY;
			return returnVal.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class FRESNEL_API MouseScrolledEvent
		: public Event
	{
	private:
		float m_XOffset, m_YOffset;
	public:
		MouseScrolledEvent(float x, float y)
			: m_XOffset(x), m_YOffset(y)
		{
		}

		inline float getXOffset() const { return m_XOffset; }
		inline float getYOffset() const { return m_YOffset; }

		std::string toString() const override
		{
			std::stringstream returnVal;
			returnVal << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return returnVal.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	/*class FRESNEL_API MouseButtonPressedEvent
		: public Event
	{
	private:
		float m_XOffset, m_YOffset;
	public:
		MouseScrolledEvent(float x, float y)
			: m_XOffset(x), m_YOffset(y)
		{
		}

		inline float getXOffset() const { return m_XOffset; }
		inline float getYOffset() const { return m_YOffset; }

		std::string toString() const override
		{
			std::stringstream returnVal;
			returnVal << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return returnVal.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};*/

}