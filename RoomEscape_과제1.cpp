#include <bangtal.h>
using namespace bangtal;

int main()
{
	// 장면 생성
	auto scene1 = Scene::create("ROOM 1", "Images/배경-1.png");
	auto scene2 = Scene::create("ROOM 2", "Images/배경-2.png");
	auto scene3 = Scene::create("ROOM 3", "Images/배경-1.png");
	auto scene4 = Scene::create("ROOM 4", "Images/배경-2.png");

	// ROOM1 문 생성 및 클릭시 이동
	auto open1 = false;
	auto r1_door1 = Object::create("Images/문-오른쪽-닫힘.png", scene1, 800, 270);
	r1_door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open1 == true)
		{
			scene2->enter();
		}
		else {
			r1_door1->setImage("Images/문-오른쪽-열림.png");
			open1 = true;
		}

		return true;
		});

	// ROOM2 문 생성 및 클릭시 이동
	auto open2 = false;
	auto r2_door1 = Object::create("Images/문-왼쪽-열림.png", scene2, 320, 270);
	r2_door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open2 == true)
		{
			scene1->enter();
		}
		else {
			open2 = true;
		}		
		
		return true;
		});

	auto open3 = false;
	auto r2_door2 = Object::create("Images/문-오른쪽-닫힘.png", scene2, 810, 289);
	r2_door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open3 == true)
		{
			scene3->enter();
		}
		else {
			r2_door2->setImage("Images/문-오른쪽-열림.png");
			open3 = true;
		}
		return true;
		});
		
	auto open4 = false;
	auto r2_door3 = Object::create("Images/문-오른쪽-닫힘.png", scene2, 1010, 258);
	r2_door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open4 == true)
		{
			scene4->enter();
		}
		else {
			r2_door3->setImage("Images/문-오른쪽-열림.png");
			open4 = true;
		}
		return true;
		});

	// ROOM3 문 생성 및 클릭시 이동
	auto open5 = false;
	auto r3_door1 = Object::create("Images/문-왼쪽-열림.png", scene3, 240, 288);
	r3_door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open5 == true)
		{
			scene2->enter();
		}
		else {
			open5 = true;

		}
		return true;
		});

	auto open6 = false;
	auto r3_door2 = Object::create("Images/문-오른쪽-닫힘.png", scene3, 800, 270);
	r3_door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open6 == true)
		{
			scene4->enter();
		}
		else {
			r3_door2->setImage("Images/문-오른쪽-열림.png");
			open6 = true;
		}
		return true;
		});


	// ROOM4 문 생성 및 클릭시 이동
	auto open7 = false;
	auto r4_door1 = Object::create("Images/문-왼쪽-닫힘.png", scene4, 150, 238);

	r4_door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open7 == true)
		{

			scene3->enter();
		}
		else {
			r4_door1->setImage("Images/문-왼쪽-열림.png");

			open7 = true;

		}
		return true;
		});

	auto open8 = false;
	auto r4_door2 = Object::create("Images/문-왼쪽-닫힘.png", scene4, 400, 285);
	r4_door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open8 == true)
		{
			scene2->enter();
		}
		else {
			r4_door2->setImage("Images/문-왼쪽-열림.png");
			open8 = true;

		}
		return true;
		});

	auto open9 = false;
	auto r4_door3 = Object::create("Images/문-오른쪽-닫힘.png", scene4, 910, 270);
	r4_door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open9 == true) {
			endGame();
		}
		else {
			r4_door3->setImage("Images/문-오른쪽-열림.png");
			showMessage("★탈출문을 찾았습니다!★ \n (문을 더블클릭하면 게임이 종료됩니다.)");
			open9 = true;
		}
		return true;
		});


	// 게임 시작
	startGame(scene1);

	return 0;
}