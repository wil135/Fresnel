#pragma once

#include "Event.h"

#include <sstream>

namespace Fresnel
{
	class FRESNEL_API KeyEvent
		: public Event
	{
	protected:
		int m_KeyCode;
	public:
		inline int getKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}
	};

	class FRESNEL_API KeyPressedEvent
		: public KeyEvent
	{
	private:
		int m_RepeatCount;
	public:
		KeyPressedEvent(int keycode, int repeatCnt)
			: KeyEvent(keycode), m_RepeatCount(repeatCnt) 
		{
		}

		inline int getRepeatCount() const { return m_RepeatCount; }

		std::string toString() const override
		{
			std::stringstream returnVal;
			returnVal << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return returnVal.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);
	};

	class FRESNEL_API KeyReleasedEvent
		: public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) 
		{
		}

		std::string toString() const override
		{
			std::stringstream returnVal;
			returnVal << "KeyReleasedEvent: " << m_KeyCode;
			return returnVal.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}