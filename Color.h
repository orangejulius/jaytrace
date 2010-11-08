#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

class Color
{
public:
	Color();
	Color(float r, float g, float b, float a = 1);

	float getRed() const;
	void setRed(float r);

	float getGreen() const;
	void setGreen(float g);

	float getBlue() const;
	void setBlue(float b);

	unsigned int getARGB() const;

	Color operator +(const Color &c) const;
	Color operator -(const Color &c) const;
	Color& operator +=(const Color &c);
	Color operator *(float d) const;
	Color operator *(Color c) const;

	bool operator ==(const Color &c) const;
	bool operator !=(const Color &c) const;

private:
	float red;
	float green;
	float blue;
	float alpha;
};

#endif // COLOR_H_INCLUDED
