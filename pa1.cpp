/**
 * @file pa1.cpp
 * @author your name(s)
 *
 * Contains basic tests for CPSC 221 PA1
 *
 * THIS FILE WILL NOT BE SUBMITTED TO PRAIRIELEARN
 * 
 * IT IS HIGHLY RECOMMENDED TO ADD YOUR OWN TESTS TO THIS FILE!
 * 
 * Think about the mechanical processes in the other functions you have written.
 * Where are the likely places for the logic to go wrong?
 * Write tests that specifically target these potential weak points!
 * START WITH SMALL TEST CASES!
 */

#include "block.h"
#include "twodlinkedlist.h"

#include <iostream>

using namespace std;
using namespace cs221util;

// Declaration of testing functions.
// Recommended to have a testing function for each major function in Block and/or TwoDLinkedList
void TestRender();
void TestFlipHorizontal();

void TestBlock();
void TestRenderScaleLargerThanOne();
void TestFlippy();

// Entry point to your program
int main(void) {

	// Add or remove calls to the declared testing functions as necessary
	TestRender();
	TestFlipHorizontal();

	TestBlock();
	TestRenderScaleLargerThanOne();
	TestFlippy();

	return 0;
}

// Implementation of testing functions

// 
void TestBlock() {
	cout << "Entered TestBlock..." << endl;
	PNG inputimg;
	PNG outputimg;
	inputimg.readFromFile("input-img/cat-face_1f431.png");
	outputimg.readFromFile("input-img/white-background.png");
	cout << "Read cat image file..." << endl;
	Block b;
	b.Build(50, 50, 10, 10, inputimg);
	cout << "Built a block..." << endl;
	b.Render(0, 0, 0, outputimg);
	cout << "rendered" << endl;
	outputimg.writeToFile("output-img/cat-face-render-half-test.png");

}

void TestRenderScaleLargerThanOne() {
	cout << "Entered TestBlock..." << endl;
	PNG inputimg;
	PNG outputimg;
	inputimg.readFromFile("input-img/cat-face_1f431.png");
	outputimg.readFromFile("input-img/white-background.png");
	cout << "Read cat image file..." << endl;
	Block b;
	b.Build(50, 50, 0, 0, inputimg);
	cout << "Built a block..." << endl;
	b.Render(2, 20, 20, outputimg);
	cout << "rendered" << endl;
	outputimg.writeToFile("output-img/cat-face-render-larger-test.png");
}

void TestFlippy() {
	cout << "Entered TestBlock..." << endl;
	PNG inputimg;
	PNG outputimg;
	inputimg.readFromFile("input-img/cat-face_1f431.png");
	outputimg.readFromFile("input-img/white-background.png");
	cout << "Read cat image file..." << endl;
	Block b;
	b.Build(50, 50, 10, 10, inputimg);
	b.FlipHorizontal();
	cout << "Built a block..." << endl;
	b.Render(0, 0, 0, outputimg);
	cout << "rendered" << endl;
	outputimg.writeToFile("output-img/cat-face-render-half-test2.png");
}
/**
 *  Builds a list from an input image, calls Blockify, and renders to a PNG
 */
void TestRender() {
	cout << "Entered TestRender..." << endl;

	cout << "Reading input image...";
	PNG inputimg;
	inputimg.readFromFile("input-img/cat-face_1f431.png");
	cout << " done." << endl;

	cout << "Creating TwoDLinkedList...";
	TwoDLinkedList catfacelist(inputimg, 40, 40);
	cout << " done." << endl;

	cout << "Rendering image to output PNG at 1x scale...";
	PNG outputimg1 = catfacelist.Render(1);
	cout << " done." << endl;

	cout << "Writing rendered PNG to file...";
	outputimg1.writeToFile("output-img/cat-face-render1.png");
	cout << " done." << endl;

	cout << "Rendering image to output PNG at 0.5x scale...";
	PNG outputimg0 = catfacelist.Render(0);
	cout << " done." << endl;

	cout << "Writing rendered PNG to file...";
	outputimg0.writeToFile("output-img/cat-face-render0.png");
	cout << " done." << endl;

	cout << "Rendering image to output PNG at 2x scale...";
	PNG outputimg2 = catfacelist.Render(2);
	cout << " done." << endl;

	cout << "Writing rendered PNG to file...";
	outputimg2.writeToFile("output-img/cat-face-render2.png");
	cout << " done." << endl;

	cout << "Rendering image to output PNG at 3x scale...";
	PNG outputimg3 = catfacelist.Render(3);
	cout << " done." << endl;

	cout << "Writing rendered PNG to file...";
	outputimg3.writeToFile("output-img/cat-face-render3.png");
	cout << " done." << endl;

	cout << "Exiting TestRender...\n" << endl;
}

/**
 *  Builds a list from an input image, calls FlipHorizontal, and renders to a PNG
 */
void TestFlipHorizontal() {
	cout << "Entered TestFlipHorizontal..." << endl;

	cout << "Reading input image...";
	PNG inputimg;
	inputimg.readFromFile("input-img/cs-256x224.png");
	cout << " done." << endl;

	cout << "Creating TwoDLinkedList...";
	TwoDLinkedList cslist(inputimg, 8, 4);
	cout << " done." << endl;

	cout << "Calling FlipHorizontal on list...";
	cslist.FlipHorizontal();
	cout << " done." << endl;

	cout << "Rendering flipped image to output PNG at 1x scale...";
	PNG outputimg = cslist.Render(1);
	cout << " done." << endl;

	cout << "Writing flipped PNG to file...";
	outputimg.writeToFile("output-img/cs-fliphorizontal-8x4.png");
	cout << " done." << endl;

	cout << "Exiting TestFlipHorizontal...\n" << endl;
}
