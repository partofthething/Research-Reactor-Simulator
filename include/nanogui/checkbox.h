/*
    nanogui/checkbox.h -- Two-state check box widget

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#pragma once

#include <nanogui/widget.h>

#define ANIM_TIME	0.4

NAMESPACE_BEGIN(nanogui)

class NANOGUI_EXPORT CheckBox : public Widget {
public:
    CheckBox(Widget *parent, const std::string &caption = "Untitled",
             const std::function<void(bool)> &callback = std::function<void(bool)>());

    const std::string &caption() const { return mCaption; }
    void setCaption(const std::string &caption) { mCaption = caption; }

    const bool &checked() const { return mChecked; }
    void setChecked(const bool &checked) { mChecked = checked; }

    const bool &pushed() const { return mPushed; }
    void setPushed(const bool &pushed) { mPushed = pushed; }

    std::function<void(bool)> callback() const { return mCallback; }
    void setCallback(const std::function<void(bool)> &callback) { mCallback = callback; }

    virtual bool mouseButtonEvent(const Vector2i &p, int button, bool down, int modifiers) override;
    virtual Vector2i preferredSize(NVGcontext *ctx) const override;
    virtual void draw(NVGcontext *ctx) override;

    virtual void save(Serializer &s) const override;
    virtual bool load(Serializer &s) override;
protected:
    std::string mCaption;
    bool mPushed, mChecked;
    std::function<void(bool)> mCallback;
};

class NANOGUI_EXPORT SliderCheckBox : public Widget {
public:
	SliderCheckBox(Widget *parent, const std::function<void(bool)> &callback = std::function<void(bool)>());

	const bool &checked() const { return mChecked; }
	void setChecked(const bool &checked) { mChecked = checked; }

	const bool &pushed() const { return mPushed; }
	void setPushed(const bool &pushed) { mPushed = pushed; }

	std::function<void(bool)> callback() const { return mCallback; }
	void setCallback(const std::function<void(bool)> &callback) { mCallback = callback; }

	virtual bool mouseButtonEvent(const Vector2i &p, int button, bool down, int modifiers) override;
	virtual bool mouseEnterEvent(const Vector2i &p, bool enter) override;
	virtual Vector2i preferredSize(NVGcontext *ctx) const override;
	virtual void draw(NVGcontext *ctx) override;

	virtual void save(Serializer &s) const override;
	virtual bool load(Serializer &s) override;
protected:
	std::string mCaption;
	bool mPushed, mChecked;
	std::function<void(bool)> mCallback;
	double timeAtChange;
	int state;
	bool mouseE;
};

NAMESPACE_END(nanogui)
