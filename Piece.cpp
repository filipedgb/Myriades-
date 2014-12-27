#include "Piece.h"

GLfloat ambB[4] = {0.0,0.0,0.0,1};
GLfloat ambW[4] = {0.5,0.5,0.5,1};
GLfloat ambG[4] = {0.1,0.1,0.1,1};

GLfloat specB[4] = {0.5,0.5,0.5,1};
GLfloat specW[4] = {1,1,1,1};
GLfloat specG[4] = {0.8,0.8,0.8,1};

GLfloat black[4] = {0,0,0,1};
GLfloat white[4] = {1,1,1,0};
GLfloat grey[4] = {0.8,0.8,0.8,1};


Piece::Piece(int number, char color) {
	this->color = color; 
	this->number = number;
	this->piece = new Cylinder(1,1,0.2,30,30);

	switch (color) {
	case 'w':
		this->app = new Appearance("w",120,NULL,ambW,white,specW);
		break;
	case 'b':
		this->app = new Appearance("b",120,NULL,ambB,black,specB);
		break;
	case 'g':
		this->app = new Appearance("g",120,NULL,ambG,grey,specG);
		break;
	default:
		break;
	}
}

char Piece::getColor() const {
	return color;
}

int Piece::getNumber() const {
	return number;
}

void Piece::setColor(char c) {
	this->color = c;

	switch (color) {
	case 'w':
		this->app = new Appearance("w",120,NULL,ambW,white,specW);
		break;
	case 'b':
		this->app = new Appearance("b",120,NULL,ambB,black,specB);
		break;
	case 'g':
		this->app = new Appearance("g",120,NULL,ambG,grey,specG);
		break;
	default:
		break;
	}
}

void Piece::setNumber(int n) {
	this->number = n;
}

void Piece::draw(float text_s, float text_t) {
	glPushMatrix();
	this->app->apply();
	this->piece->draw(text_s,text_t);
	glPopMatrix();
}