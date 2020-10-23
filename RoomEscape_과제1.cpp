#include <bangtal>
using namespace bangtal;

int main()
{
	// 장면 생성 // room1
	auto scene1 = Scene::create("ROOM 1 ①", "방탈이미지/방1.png");
	auto scene2 = Scene::create("ROOM 1 ②", "방탈이미지/방2.png");
	auto scene3 = Scene::create("ROOM 1 ③", "방탈이미지/방1.png");
	auto scene4 = Scene::create("ROOM 1 ④", "방탈이미지/방2.png");

	// room2
	auto scene5 = Scene::create("ROOM 2 ①", "방탈이미지/방3.png");
	auto scene6 = Scene::create("ROOM 2 ②", "방탈이미지/방4.png");
	auto scene7 = Scene::create("ROOM 2 ③", "방탈이미지/방3.png");
	auto scene8 = Scene::create("ROOM 2 ④", "방탈이미지/방4.png");
	auto game2enter = false;



	auto tv = Object::create("방탈이미지/TV 치지직.png", scene1, 550, 0);
	tv->setScale(0.65f);

	auto tv_hint = Object::create("방탈이미지/TV 힌트.png", scene1, 592, 286, false);
	tv_hint->setScale(0.65f);

	auto plant = Object::create("방탈이미지/화분.png", scene1, 200, 120);
	plant->setScale(1.5f);

	auto tv_open1 = Object::create("방탈이미지/서랍 열림.png", scene1, 574, 98, false);
	tv_open1->setScale(0.66f);

	auto tv_open2 = Object::create("방탈이미지/서랍 열림.png", scene1, 752, 98, false);
	tv_open2->setScale(0.66f);

	auto tv_open3 = Object::create("방탈이미지/서랍 열림.png", scene1, 930, 98, false);
	tv_open3->setScale(0.66f);


	auto remote = Object::create("방탈이미지/remote.png", scene1, 635, 207, false);
	remote->setScale(0.1f);

	auto puzzle1 = Object::create("방탈이미지/용퍼즐/용1.png", scene1, 1000, 207, false);
	puzzle1->setScale(0.2f);

	bool tv_open1_check = false, tv_open2_check = false, tv_open3_check = false;

	tv->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (x > 0 && x < 180 && y>0 && y < 570) {

			tv_open1->show();
			tv_open1_check = true;
			remote->show();

		}
		else if (x > 200 && x < 390 && y>0 && y < 570) {
			tv_open2->show();
			tv_open2_check = true;

		}
		else if (x > 400 && x < 590 && y>0 && y < 570) {
			showKeypad("USB", tv_open3);
			tv_open3->setOnKeypadCallback([&](ObjectPtr object)->bool {
				tv_open3->show();
				tv_open3_check = true;
				puzzle1->show();
				return true;
				});
		}
		else {
			if (remote->isHanded())
				tv_hint->show();
		}
		return true;
		});


	remote->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		remote->pick();

		return true;
		});

	puzzle1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if(game2enter == false) puzzle1->pick();

		return true;
		});
	auto cloth = Object::create("방탈이미지/옷장잠김.png", scene2, 700, -350);
	cloth->setScale(0.6f);
	auto cloth2 = Object::create("방탈이미지/옷장 열림.png", scene2, 700, -350, false);
	cloth2->setScale(0.6f);
	auto drawer = Object::create("방탈이미지/옷장서랍열림.png", scene2, 729, 112, false);
	drawer->setScale(0.6f);

	auto key1 = Object::create("방탈이미지/key2.png", scene2, 860, 210, false);
	key1->setScale(0.075f);

	auto puzzle2 = Object::create("방탈이미지/용퍼즐/용2.png", scene2, 940, 400, false);
	puzzle2->setScale(0.2f);
	puzzle2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (game2enter == false) puzzle2->pick();

		return true;
		});

	cloth->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (x > 0 && x < 400 && y>1150 && y < 1250) {
			drawer->show();
			key1->show();
		}
		else if (x > 120 && x < 250 && y>1300 && y < 1500) {
			showKeypad("good", cloth);
			cloth->setOnKeypadCallback([&](ObjectPtr object)->bool {
				cloth2->show();
				puzzle2->show();
				return true;
				});
		}


		return true;
		});


	key1->setOnMouseCallback([&](ObjectPtr object, int x, int, MouseAction action)->bool {
		key1->pick();

		return true;
		});



	auto open1 = false;
	auto door1 = Object::create("방탈이미지/닫힌문.png", scene2, 200, 209);
	door1->setScale(0.6f);
	door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (key1->isHanded())
		{
			door1->setImage("방탈이미지/페이크문.png");
			open1 = true;
		}
		else {
			showMessage("열쇠가 필요합니다.");
		}

		return true;
		});

	auto button1 = Object::create("방탈이미지/스위치.png", scene2, 440, 350);
	button1->setScale(0.55f);

	auto password1 = Object::create("방탈이미지/good.png", scene2, 290, 400, false);

	auto dark = false;
	button1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (dark == false) {
			scene2->setLight(0.4f);
			dark = true;
			if (open1 == true) password1->show();
		}
		else {
			scene2->setLight(1.f);
			dark = false;
			if (open1 == true) password1->hide();
		}
		return true;
		});


	auto sofa = Object::create("방탈이미지/소파.png", scene3, 600, 130);
	sofa->setScale(0.75f);

	auto picture = Object::create("방탈이미지/명화.jpg", scene3, 810, 290);
	picture->setScale(0.05f);
	picture->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		picture->pick();

		return true;
		});


	auto moved = false;
	auto cushion = Object::create("방탈이미지/소파쿠션.png", scene3, 800, 260);
	cushion->setScale(0.8f);
	cushion->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
		if (moved == false) {
			if (action == MouseAction::MOUSE_DRAG_LEFT) {
				cushion->locate(scene3, 770, 260);
				moved = true;
			}
			else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
				cushion->locate(scene3, 830, 260);
				moved = true;
			}
		}
		else {
			if (action == MouseAction::MOUSE_DRAG_LEFT) {
				cushion->locate(scene3, 800, 260);
				moved = false;
			}
			else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
				cushion->locate(scene3, 800, 260);
				moved = false;
			}
		}
		return true;
		});




	auto table = Object::create("방탈이미지/테이블.png", scene3, 200, 130);
	table->setScale(0.55f);

	auto box = Object::create("방탈이미지/금고.png", scene3, 275, 300);
	box->setScale(0.55f);


	auto box2 = Object::create("방탈이미지/열린금고.png", scene3, 275, 259, false);
	box2->setScale(0.55f);


	auto puzzle3 = Object::create("방탈이미지/용퍼즐/용3.png", scene3, 335, 355, false);
	puzzle3->setScale(0.2f);
	puzzle3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (game2enter == false) puzzle3->pick();

		return true;
		});


	auto clock = Object::create("방탈이미지/시계.png", scene3, 120, 460);
	clock->setScale(0.55f);


	box->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showKeypad("1215", box);
		box->setOnKeypadCallback([&](ObjectPtr object)->bool {
			box2->show();
			puzzle3->show();

			return true;
			});

		return true;
		});

	auto chair1 = Object::create("방탈이미지/간이의자1.png", scene3, 140, 130);
	chair1->setScale(0.6f);

	auto chair2 = Object::create("방탈이미지/의자2.png", scene3, 450, 110);
	chair2->setScale(0.6f);

	auto pic2 = Object::create("방탈이미지/pic2.png", scene4, 150, 400);
	pic2->setScale(0.6f);

	auto sunban = Object::create("방탈이미지/선반.png", scene4, 450, 330);
	sunban->setScale(0.55f);


	ObjectPtr doll[4];

	int a[] = { 450, 520, 590, 660 };

	auto doll1 = Object::create("방탈이미지/마트로시카2.png", scene4, 450, 350);
	doll1->setScale(0.55f);
	doll[0] = doll1;

	auto doll2 = Object::create("방탈이미지/마트로시카4.png", scene4, 520, 350);
	doll2->setScale(0.55f);
	doll[1] = doll2;


	auto doll3 = Object::create("방탈이미지/마트로시카1.png", scene4, 590, 348);
	doll3->setScale(0.55f);
	doll[2] = doll3;


	auto doll4 = Object::create("방탈이미지/마트로시카3.png", scene4, 660, 348);
	doll4->setScale(0.55f);
	doll[3] = doll4;

	auto key2 = Object::create("방탈이미지/key.png", scene4, 607, 409, false);
	key2->setScale(0.05f);


	key2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		key2->pick();

		return true;
		});

	auto puzzle4 = Object::create("방탈이미지/용퍼즐/용4.png", scene4, 680, 425, false);
	puzzle4->setScale(0.15f);
	puzzle4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (game2enter == false)puzzle4->pick();

		return true;
		});

	doll1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_RIGHT && a[0] != 660) {
			doll1->locate(scene4, a[0] + 70, 350);
			a[0] = a[0] + 70;
		}
		else if (action == MouseAction::MOUSE_DRAG_LEFT && a[0] != 450) {
			doll1->locate(scene4, a[0] - 70, 350);
			a[0] = a[0] - 70;

		}
		if (a[0] == 520 && a[1] == 660 && a[2] == 450 && a[3] == 590) {
			doll4->setImage("방탈이미지/마트로시카3열림.png");
			doll2->setImage("방탈이미지/마트로시카4열림.png");
			key2->show();
			puzzle4->show();
		}
		return true;
		});

	doll2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_RIGHT && a[1] != 660) {
			doll2->locate(scene4, a[1] + 70, 350);
			a[1] = a[1] + 70;
		}
		else if (action == MouseAction::MOUSE_DRAG_LEFT && a[1] != 450) {
			doll2->locate(scene4, a[1] - 70, 350);
			a[1] = a[1] - 70;
		}
		if (a[0] == 520 && a[1] == 660 && a[2] == 450 && a[3] == 590) {
			doll4->setImage("방탈이미지/마트로시카3열림.png");
			doll2->setImage("방탈이미지/마트로시카4열림.png");
			key2->show();
			puzzle4->show();
		}
		return true;
		});

	doll3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_RIGHT && a[2] != 660) {
			doll3->locate(scene4, a[2] + 70, 348);
			a[2] = a[2] + 70;
		}
		else if (action == MouseAction::MOUSE_DRAG_LEFT && a[2] != 450) {
			doll3->locate(scene4, a[2] - 70, 348);
			a[2] = a[2] - 70;
		}
		if (a[0] == 520 && a[1] == 660 && a[2] == 450 && a[3] == 590) {
			doll4->setImage("방탈이미지/마트로시카3열림.png");
			doll2->setImage("방탈이미지/마트로시카4열림.png");
			key2->show();
			puzzle4->show();
		}
		return true;
		});

	doll4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_RIGHT && a[3] != 660) {
			doll4->locate(scene4, a[3] + 70, 348);
			a[3] = a[3] + 70;
		}
		else if (action == MouseAction::MOUSE_DRAG_LEFT && a[3] != 450) {
			doll4->locate(scene4, a[3] - 70, 348);
			a[3] = a[3] - 70;

		}
		if (a[0] == 520 && a[1] == 660 && a[2] == 450 && a[3] == 590) {
			doll4->setImage("방탈이미지/마트로시카3열림.png");
			doll2->setImage("방탈이미지/마트로시카4열림.png");
			key2->show();
			puzzle4->show();
		}
		return true;
		});




	//ROOM1 문 생성 및 클릭시 이동
	auto open2 = false;
	auto door2 = Object::create("방탈이미지/닫힌문.png", scene4, 850, 209);
	door2->setScale(0.6f);
	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open2 == true) scene5->enter();
		else if (key2->isHanded())
		{
			door2->setImage("방탈이미지/열린문.png");
			open2 = true;
		}
		else {
			showMessage("열쇠가 필요합니다.");
		}
		return true;
		});


	//ROOM1 문 생성 및 클릭시 이동
	auto door3 = Object::create("방탈이미지/룸2문.png", scene5, 200, 195);
	door3->setScale(0.6f);
	door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene4->enter();
		return true;
		});



	auto cabinet = Object::create("방탈이미지/찬장잠김.png", scene5, 800, 350);
	cabinet->setScale(0.6f);


	auto puzzle5 = Object::create("방탈이미지/용퍼즐/용5.png", scene5, 1010, 478, false);
	puzzle5->setScale(0.15f);
	puzzle5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (game2enter == false) puzzle5->pick();

		return true;
		});


	int up = 0, down = 0;

	auto reset = Object::create("방탈이미지/리셋.png", scene5, 750, 500);
	reset->setScale(0.5f);
	reset->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		up = 0;
		down = 0;
		printf("up: %d, down: %d\n", up, down);
		return true;
		});
	auto updown = Object::create("방탈이미지/위아래스위치.png", scene5, 750, 420);
	updown->setScale(0.3f);
	updown->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (y > 205) {
			up++;
			printf("up: %d, down: %d\n", up, down);

		}
		else {
			down++;
			printf("up: %d, down: %d\n", up, down);

		}
		if (up == 3 && down == 2) {
			cabinet->setImage("방탈이미지/찬장열림.png");
			puzzle5->show();
		}
		return true;
		});





	auto table2 = Object::create("방탈이미지/테이블.png", scene5, 450, 130);
	table2->setScale(0.55f);


	auto music = Object::create("방탈이미지/카세트.png", scene5, 500, 300);
	music->setScale(0.6f);

	music->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showAudioPlayer("오디오/위아래.mp3");
		return true;
		});


	auto bed = Object::create("방탈이미지/침대.png", scene6, 170, -100);
	bed->setScale(0.75f);

	auto begae1 = Object::create("방탈이미지/베개1.png", scene6, 265, 250);
	begae1->setScale(0.7f);
	int begae1_y = 250;
	begae1->setScale(0.7f);
	begae1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_UP) {
			begae1->locate(scene6, 265, begae1_y + 10);
			begae1_y = begae1_y + 10;
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			begae1->locate(scene6, 265, begae1_y - 10);
			begae1_y = begae1_y - 10;
		}

		return true;
		});


	auto glass = Object::create("방탈이미지/돋보기.png", scene6, 500, 270);
	glass->setScale(0.1f);
	glass->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		glass->pick();
		return true;
		});


	auto begae2 = Object::create("방탈이미지/베개2.png", scene6, 485, 248);
	int begae2_y = 248;
	begae2->setScale(0.7f);
	begae2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_UP) {
			begae2->locate(scene6, 485, begae2_y + 10);
			begae2_y = begae2_y + 10;
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			begae2->locate(scene6, 485, begae2_y - 10);
			begae2_y = begae2_y - 10;
		}

		return true;
		});




	auto game1 = Scene::create("틀린그림찾기", "방탈이미지/방2.png");
	auto blue = Object::create("방탈이미지/파란배경.png", game1, 0, 0);

	auto pic5 = Object::create("방탈이미지/명화.jpg", game1, 10, 130);
	pic5->setScale(0.8f);


	auto pic4 = Object::create("방탈이미지/명화_수정.png", game1, 550, 130);
	pic4->setScale(1.05f);


	auto check1 = Object::create("방탈이미지/check.png", game1, 827, 400, false);
	check1->setScale(0.1f);

	auto check2 = Object::create("방탈이미지/check.png", game1, 985, 618, false);
	check2->setScale(0.1f);

	auto check3 = Object::create("방탈이미지/check.png", game1, 1045, 628, false);
	check3->setScale(0.1f);


	auto check4 = Object::create("방탈이미지/check.png", game1, 640, 720 - 275, false);
	check4->setScale(0.1f);

	auto check5 = Object::create("방탈이미지/check.png", game1, 687, 720 - 236, false);
	check5->setScale(0.1f);

	int checkcount = 0;


	auto pic3 = Object::create("방탈이미지/명화_수정.png", scene6, 720, 300);
	pic3->setScale(0.55f);
	pic3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (picture->isHanded()) {
			game1->enter();
			return true;
		}
		else {
			showMessage("명화 원본 그림이 필요합니다.");
		}
		});


	auto puzzle6 = Object::create("방탈이미지/용퍼즐/용6.png", scene6, 800, 320, false);
	puzzle6->setScale(0.15f);
	puzzle6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (game2enter == false) puzzle6->pick();

		return true;
		});

	auto null = Object::create("방탈이미지/null.png", game1, 0, 0);
	auto c1 = false, c2 = false, c3 = false, c4 = false, c5 = false;

	null->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (x > 824 && x < 869 && y>390 && y < 443) {
			check1->show();
			if (c1 == false)			checkcount++;
			c1 = true;
		}
		else if (x > 987 && x < 1017 && y>610 && y < 669) {
			check2->show();
			if (c2== false)	checkcount++;
			c2 = true;
		}
		else if (x > 1051 && x < 1085 && y>623 && y < 668) {
			check3->show();
			if (c3 == false)	checkcount++;
			c3 = true;
		}
		else if (x > 640 && x < 675 && y>720 - 295 && y < 720 - 105) {
			check4->show();
			if (c4 == false)	checkcount++;
			c4 = true;
		}
		else if (x > 693 && x < 719 && y>720 - 232 && y < 720 - 196) {
			check5->show();
			if (c5 == false)	checkcount++;
			c5 = true;
		}
		if (checkcount == 5) {
			scene6->enter();
			pic3->setImage("방탈이미지/명화오픈.png");
			puzzle6->show();
		}

		return true;
		});

	auto backbutton = Object::create("방탈이미지/back.png", game1, 620, 20);
	backbutton->setScale(0.7f);

	backbutton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene6->enter();
		return true;
		});



	auto numberquiz = Object::create("방탈이미지/숫자퀴즈.png", scene7, 179, 720 - 409);
	numberquiz->setScale(0.7f);
	numberquiz->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (glass->isHanded())
			numberquiz->setImage("방탈이미지/숫자퀴즈확대.png");
		else
			showMessage("돋보기가 필요합니다.");

		return true;
		});

	auto desk = Object::create("방탈이미지/책장.png", scene7, 640, 720 - 552);
	desk->setScale(0.7f);

	auto puzzle8 = Object::create("방탈이미지/용퍼즐/용8.png", scene7, 1062, 720 - 400 + 20);
	puzzle8->setScale(0.1f);
	puzzle8->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (game2enter == false) puzzle8->pick();

		return true;
		});
	auto book1 = Object::create("방탈이미지/책두권.png", scene7, 1060, 720 - 400 + 15);
	book1->setScale(0.7f);

	book1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT) {
			book1->locate(scene7, 1060 - 30, 720 - 400 + 15);
		}
		return true;
		});

	auto deskopendown = Object::create("방탈이미지/책상서랍열림.png", scene7, 640, 720 - 595, false);
	deskopendown->setScale(0.7f);

	auto puzzle7 = Object::create("방탈이미지/용퍼즐/용7.png", scene7, 700, 210, false);
	puzzle7->setScale(0.1f);
	puzzle7->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (game2enter == false) puzzle7->pick();

		return true;
		});
	auto deskopenup = Object::create("방탈이미지/책상서랍열림.png", scene7, 640, 720 - 536, false);
	deskopenup->setScale(0.7f);

	auto openup = false;
	auto opendown = false;

	desk->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (x > 0 && x < 150 && y>0 && y < 230) {
			showKeypad("15", deskopendown);
			deskopendown->setOnKeypadCallback([&](ObjectPtr object)->bool {
				deskopendown->show();
				puzzle7->show();
				opendown = true;
				return true;
				});
		}
		else if (x > 0 && x < 150 && y>230 && y < 460) {
			deskopenup->show();
			openup = true;
		}
		return true;
		});
	deskopenup->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (openup == true) {
			deskopenup->hide();
			opendown = false;
		}
		return true;
		});
	deskopendown->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (opendown == true) {
			deskopendown->hide();
			opendown = false;
		}
		return true;
		});


	auto game2 = Scene::create("퍼즐 맞추기", "방탈이미지/파란배경.png");


	//탈출구 생성 및 클릭시 이동
	auto finish = false;
	auto open4 = false;
	auto door4 = Object::create("방탈이미지/닫힌문.png", scene8, 850, 209);
	door4->setScale(0.6f);
	door4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open4 == false) {

			showMessage("잠겨 있습니다.");
		}
		else if(finish==false) {
			showMessage("탈★출★성★공");
			finish = true;
		}
		else {
			endGame();
		}
		return true;
		});



	auto puzzlegame = Object::create("방탈이미지/퍼즐판.png", scene8, 500, 300);
	puzzlegame->setScale(0.3f);

	puzzlegame->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game2enter = true;
		game2->enter();
		return true;
		});

	auto puzzlegame2 = Object::create("방탈이미지/퍼즐판.png", game2, 330, 100);
	puzzlegame->setScale(0.3f);

	auto hint = Object::create("방탈이미지/힌트문구.png", game2, 500, 100);
	hint->setScale(0.5f);
	puzzlegame2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (puzzle1->isHanded()) {
			puzzle1->drop();
		}
		if (puzzle2->isHanded()) {
			puzzle2->drop();
		}
		if (puzzle3->isHanded()) {
			puzzle3->drop();
		}
		if (puzzle4->isHanded()) {
			puzzle4->drop();
		}
		if (puzzle5->isHanded()) {
			puzzle5->drop();
		}
		if (puzzle6->isHanded()) {
			puzzle6->drop();

		}
		if (puzzle7->isHanded()) {
			puzzle7->drop();
		}

		if (puzzle8->isHanded()) {
			puzzle8->drop();
		}
		return true;
	});

	int puzzleright= 0 ;

		puzzle1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (game2enter == true) {
				puzzle1->locate(game2, 328, 720 - 220);
				puzzle1->setScale(1.0f);
				puzzleright++;
			}
			else puzzle1->pick();
			return true;
			});
		puzzle2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (game2enter == true) {

				puzzle2->locate(game2, 528, 720 - 220);
				puzzle2->setScale(1.0f);
				puzzleright++;

			}
			else puzzle2->pick();
			return true;
			});
		puzzle3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (game2enter == true) {

				puzzle3->locate(game2, 728, 720 - 220);
				puzzle3->setScale(1.0f);
				puzzleright++;

			}
			else puzzle3->pick();

			return true;
			});
		puzzle4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (game2enter == true) {
				puzzle4->locate(game2, 328, 720 - 420);
				puzzle4->setScale(1.0f);
				puzzleright++;

			}
			else puzzle4->pick();
			return true;
			});
		puzzle5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (game2enter == true) {
				puzzle5->locate(game2, 528, 720 - 420);
				puzzle5->setScale(1.0f);
				puzzleright++;

			}
			else puzzle5->pick();
			return true;
			});

		puzzle6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (game2enter == true) {

				puzzle6->locate(game2, 728, 720 - 420);
				puzzle6->setScale(1.0f);
				puzzleright++;

			}
			else puzzle6->pick();

			return true;
			});

		puzzle7->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (game2enter == true) {
				puzzle7->locate(game2, 328, 720 - 620);
				puzzle7->setScale(1.0f);
				puzzleright++;

			}
			else puzzle7->pick();

			return true;
			});
		
		puzzle8->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (game2enter == true) {
				puzzle8->locate(game2, 528, 720 - 620);
				puzzle8->setScale(1.0f);
				puzzleright++;

			}
			else puzzle8->pick();
			return true;
			});
	

		int i;
	auto backbutton2 = Object::create("방탈이미지/back.png", game2, 100, 300);
	backbutton2->setScale(0.7f);

	backbutton2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		
		if (puzzleright==8){
			game2enter = false;
			open4 = true;
			puzzlegame->setImage("방탈이미지/complete.png");
			door4->setImage("방탈이미지/열린문.png");
			scene8->enter();
		}
		else {
			game2enter = false;
			scene8->enter();

		}
		

		return true;
		});






	auto right1_1 = Object::create("방탈이미지/오른쪽이동.png", scene1, 1170, 280);
	right1_1->setScale(0.5f);
	right1_1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
		});

	auto lett1_2 = Object::create("방탈이미지/왼쪽이동.png", scene2, 35, 262);
	lett1_2->setScale(0.5f);
	lett1_2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		return true;
		});

	auto right1_2 = Object::create("방탈이미지/오른쪽이동.png", scene2, 1170, 280);
	right1_2->setScale(0.5f);
	right1_2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene3->enter();
		return true;
		});

	auto lett1_3 = Object::create("방탈이미지/왼쪽이동.png", scene3, 35, 262);
	lett1_3->setScale(0.5f);
	lett1_3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
		});

	auto right1_3 = Object::create("방탈이미지/오른쪽이동.png", scene3, 1170, 280);
	right1_3->setScale(0.5f);
	right1_3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene4->enter();
		return true;
		});

	auto lett1_4 = Object::create("방탈이미지/왼쪽이동.png", scene4, 35, 262);
	lett1_4->setScale(0.5f);
	lett1_4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene3->enter();
		return true;
		});

	auto right2_1 = Object::create("방탈이미지/오른쪽이동.png", scene5, 1170, 280);
	right2_1->setScale(0.5f);
	right2_1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene6->enter();
		return true;
		});

	auto lett2_2 = Object::create("방탈이미지/왼쪽이동.png", scene6, 35, 262);
	lett2_2->setScale(0.5f);
	lett2_2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene5->enter();
		return true;
		});

	auto right2_2 = Object::create("방탈이미지/오른쪽이동.png", scene6, 1170, 280);
	right2_2->setScale(0.5f);
	right2_2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene7->enter();
		return true;
		});

	auto lett2_3 = Object::create("방탈이미지/왼쪽이동.png", scene7, 35, 262);
	lett2_3->setScale(0.5f);
	lett2_3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene6->enter();
		return true;
		});

	auto right2_3 = Object::create("방탈이미지/오른쪽이동.png", scene7, 1170, 280);
	right2_3->setScale(0.5f);
	right2_3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene8->enter();
		return true;
		});

	auto lett2_4 = Object::create("방탈이미지/왼쪽이동.png", scene8, 35, 262);
	lett2_4->setScale(0.5f);
	lett2_4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene7->enter();
		return true;
		});



	// 게임 시작
	startGame(scene1);

	return 0;
}