#include "Color.h"

unsigned char getByte(float color)
{
	if (color < 0) {
		return 0;
	} else if (color > 1) {
		return 255;
	} else {
		return color * 255;
	}
}

Color::Color()
{
	red = 0;
	green = 0;
	blue = 0;
	alpha = 1;
}

Color::Color(float r, float g, float b, float a)
{
	red = r;
	green = g;
	blue = b;
	alpha = a;
}

float Color::getRed() const
{
	return red;
}

void Color::setRed(float r)
{
	red = r;
}

float Color::getGreen() const
{
	return green;
}

void Color::setGreen(float g)
{
	green = g;
}

float Color::getBlue() const
{
	return blue;
}

void Color::setBlue(float b)
{
	blue = b;
}

Color Color::operator +(const Color &c) const
{
	return Color(red + c.red, green + c.green, blue + c.blue, alpha);
}

Color Color::operator -(const Color &c) const
{
	return Color(red - c.red, green - c.green, blue - c.blue, alpha);
}

Color& Color::operator +=(const Color &c)
{
	red += c.red;
	green += c.green;
	blue += c.blue;

	return *this;
}

Color Color::operator *(float d) const
{
	return Color(red * d, green * d, blue * d, alpha);
}

Color Color::operator *(Color c) const
{
	return Color(red * c.red, green * c.green, blue * c.blue, alpha);
}

bool Color::operator ==(const Color &c) const
{
	return ((c.red == red) && (c.green == green) && (c.blue == blue) && (c.alpha == alpha));
}

bool Color::operator !=(const Color &c) const
{
	return ! operator==(c);
}
