#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Piece.h"
#include "Cube.h"
#include <GL/glut.h>
#include "CGFappearance.h"

class Board {	
	vector<vector<Piece*>> board;
	int size;

	Piece* whitePiece;
	Piece* blackPiece;

	CGFappearance* boardApp;

	CGFappearance* whiteApp;
	CGFappearance* blackApp;

	CGFtexture* woodTex;



public:
	Board();
	Board(int s);
	Board(vector<vector<Piece*>> boardIn);

	void boardParser(string answer);
	void draw();
	void drawSolidBase();
	void drawBase();
	void drawBox();
	void drawBoxPiece();
	void setAppearance(CGFappearance* a);

	void Board::setTexture(char c) ;

	int getPieceNumber(int row, int col);

	char getPieceColor(int row, int col);

	int getSize() { 
		return size;
	}

	string toString();
};

#endif
