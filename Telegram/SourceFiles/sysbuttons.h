/*
This file is part of Telegram Desktop,
an unofficial desktop messaging app, see https://telegram.org

Telegram Desktop is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

It is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

Full license: https://github.com/telegramdesktop/tdesktop/blob/master/LICENSE
Copyright (c) 2014 John Preston, https://tdesktop.com
*/
#pragma once

#include <QtWidgets/QWidget>
#include "gui/animation.h"
#include "gui/button.h"

class Window;

class SysBtn : public Button, public Animated {
	Q_OBJECT

public:

	SysBtn(QWidget *parent, const style::sysButton &st);

	void paintEvent(QPaintEvent *e);

	HitTestType hitTest(const QPoint &p) const;

	bool animStep(float64 ms);

public slots:

	void onStateChange(int oldState, ButtonStateChangeSource source);

protected:

	style::sysButton _st;
	anim::cvalue a_color;

};

class MinimizeBtn : public SysBtn {
	Q_OBJECT

public:

	MinimizeBtn(QWidget *parent, Window *window);

public slots:

	void onClick();

private:

	Window *wnd;
};

class MaximizeBtn : public SysBtn {
	Q_OBJECT

public:

	MaximizeBtn(QWidget *parent, Window *window);

public slots:

	void onClick();

private:

	Window *wnd;
};

class RestoreBtn : public SysBtn {
	Q_OBJECT

public:

	RestoreBtn(QWidget *parent, Window *window);

public slots:

	void onClick();

private:

	Window *wnd;
};

class CloseBtn : public SysBtn {
	Q_OBJECT

public:

	CloseBtn(QWidget *parent, Window *window);

public slots:

	void onClick();

private:

	Window *wnd;
};

class UpdateBtn : public SysBtn {
	Q_OBJECT

public:

	UpdateBtn(QWidget *parent, Window *window);

public slots:

	void onClick();

private:

	Window *wnd;
};
