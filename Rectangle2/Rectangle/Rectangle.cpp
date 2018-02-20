#include "Rectangle.h"

Rectangle::Rectangle()
{
	mLength = 0.0;
	mWidth = 0.0;
	std::cout << "inside constructor for Rectangle" << std::endl;

}

Rectangle::Rectangle(Rectangle &copy)
{
	// defining the way to copy Rectangle objects!
	mLength = copy.getLength();
	mWidth = copy.getWidth();
}

Rectangle::~Rectangle()
{
	std::cout << "inside destructor for Rectangle" << std::endl;
}

double Rectangle::getLength()
{
	return mLength;
}

double Rectangle::getWidth()
{
	return mWidth;
}

void Rectangle::setLength(double newLength)
{
	mLength = newLength;
}

void Rectangle::setWidth(double newWidth)
{
	if (newWidth > 0.0) // we can validate that width is > 0
	{
		mWidth = newWidth;
	}
	else
	{
		mWidth = 0.0;
	}
}

double Rectangle::computeArea()
{
	return mLength * mWidth;
}