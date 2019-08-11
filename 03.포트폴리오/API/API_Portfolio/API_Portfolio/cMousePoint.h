#pragma once

class cMousePoint
{
public:
	cMousePoint();
	~cMousePoint();
public:

	static POINTFLOAT GetPos()
	{
		POINT tagPoint;

		GetCursorPos(&tagPoint);
		ScreenToClient(g_hwnd, &tagPoint);

		POINTFLOAT tagfPoint =
		{
			float(tagPoint.x),float(tagPoint.y)
		};

		return tagfPoint;
	}
};