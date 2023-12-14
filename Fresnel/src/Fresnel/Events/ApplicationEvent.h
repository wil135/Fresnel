#pragma once

#include "Event.h"
#include <sstream>

namespace Fresnel
{
	class FRESNEL_API WindowResizeEvent
		: public Event
	{
	private:
		size_t m_Width, m_Height;
	public:
		WindowResizeEvent(size_t width, size_t height)
			: m_Width(width), m_Height(height)
		{}

		inline size_t getWidth() const { return this->m_Width; }
		inline size_t getHeight() const { return this->m_Height; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << this->m_Width << ", " << this->m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FRESNEL_API WindowCloseEvent
		: public Event
	{
		WindowCloseEvent(){}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FRESNEL_API AppTickEvent
		: public Event
	{
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FRESNEL_API AppUpdateEvent
		: public Event
	{
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FRESNEL_API AppRenderEvent
		: public Event
	{
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}