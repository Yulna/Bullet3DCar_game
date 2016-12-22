#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include"ModulePlayer.h"
#include"PhysVehicle3D.h"
ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	//music_scene1 = App->audio->LoadFx("DMX_-_X_Gon_39_Give_It_To_Ya_Official_Instrumental.ogg");
	App->audio->PlayMusic("DMX - X Gon' Give It To Ya (Official Instrumental).ogg", 1);
	finish_sound = App->audio->LoadFx("FinishSound.ogg");
	//App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	//App->camera->LookAt(vec3(0, 0, 0));

	
	//------Map-----
	//Surface
	Cube PlainGame;

	PlainGame.size.x = 700;
	PlainGame.size.z = 700;
	MyCubeMap.PushBack(PlainGame);
	PlainGame_Body = App->physics->AddBody(PlainGame, 0);
	PlainGame_Body->SetPos(102.5, -0.5, -30);
	PlainGame_Body->collision_listeners.add(this);
	MyPhysbodyCubeMap.PushBack(PlainGame_Body);


	//Road
	Cube roadboarderStartR;
	PhysBody3D*bodcub2;
	roadboarderStartR.size.x = 0.5;
	roadboarderStartR.size.z = 20;
	roadboarderStartR.size.y = 4;
	roadboarderStartR.color = Blue;
	MyCubeMap.PushBack(roadboarderStartR);
	bodcub2 = App->physics->AddBody(roadboarderStartR, 0);
	bodcub2->SetPos(83, 0.5, -232);
	MyPhysbodyCubeMap.PushBack(bodcub2);
	Cube roadboarderStartL;
	roadboarderStartL.size.x = 0.5;
	roadboarderStartL.size.z = 20;
	roadboarderStartL.size.y = 4;
	roadboarderStartL.color = Blue;
	MyCubeMap.PushBack(roadboarderStartL);
	bodcub2 = App->physics->AddBody(roadboarderStartL, 0);
	bodcub2->SetPos(95.5, 0.5, -232);
	MyPhysbodyCubeMap.PushBack(bodcub2);
	Cube roadboarderStartB;
	roadboarderStartB.size.x = 13;
	roadboarderStartB.size.z = 0.5;
	roadboarderStartB.size.y = 4;
	roadboarderStartB.color = Blue;
	MyCubeMap.PushBack(roadboarderStartB);
	bodcub2 = App->physics->AddBody(roadboarderStartB, 0);
	bodcub2->SetPos(89.25, 0.5, -242);
	MyPhysbodyCubeMap.PushBack(bodcub2);

	Cube roadboarder1L;
	PhysBody3D*bodcub1;
	roadboarder1L.size.x = 0.5;
	roadboarder1L.size.z = 200;
	roadboarder1L.size.y = 3.5;
	roadboarder1L.color = Blue;
	MyCubeMap.PushBack(roadboarder1L);
	bodcub1 = App->physics->AddBody(roadboarder1L, 0);
	bodcub1->SetPos(95.5, 0.5, -122);
	MyPhysbodyCubeMap.PushBack(bodcub1);

	Cube roadboarder1R;
	roadboarder1R.size.x = 0.5;
	roadboarder1R.size.z = 200;
	roadboarder1R.size.y = 3.5;
	roadboarder1R.color = Blue;
	MyCubeMap.PushBack(roadboarder1R);
	bodcub2 = App->physics->AddBody(roadboarder1R, 0);
	bodcub2->SetPos(83, 0.5, -122);
	MyPhysbodyCubeMap.PushBack(bodcub2);
	
	Cube roadcurve1R;
	PhysBody3D*bodcub3;
	roadcurve1R.size.x = 0.5;
	roadcurve1R.size.z = 20;
	roadcurve1R.size.y = 3.5;
	roadcurve1R.color = Blue;
	roadcurve1R.SetRotation(-30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve1R);
	bodcub3 = App->physics->AddBody(roadcurve1R, 0);
	bodcub3->SetPos(78, 0.5, -13.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve1L;
	roadcurve1L.size.x = 0.5;
	roadcurve1L.size.z = 20;
	roadcurve1L.size.y = 3.5;
	roadcurve1L.color = Blue;
	roadcurve1L.SetRotation(-30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve1L);
	bodcub3 = App->physics->AddBody(roadcurve1L, 0);
	bodcub3->SetPos(90.5, 0.5, -13.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve2L;
	roadcurve2L.size.x = 0.5;
	roadcurve2L.size.z = 40;
	roadcurve2L.size.y = 3.5;
	roadcurve2L.color = Blue;
	roadcurve2L.SetRotation(30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve2L);
	bodcub3 = App->physics->AddBody(roadcurve2L, 0);
	bodcub3->SetPos(95.5, 0.5, 12.25);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve2R;
	roadcurve2R.size.x = 0.5;
	roadcurve2R.size.z = 40;
	roadcurve2R.size.y = 3.5;
	roadcurve2R.color = Blue;
	roadcurve2R.SetRotation(30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve2R);
	bodcub3 = App->physics->AddBody(roadcurve2R, 0);
	bodcub3->SetPos(83, 0.5, 12.25);
	MyPhysbodyCubeMap.PushBack(bodcub3);
	
	Cube roadboarder2R;
	roadboarder2R.size.x = 0.5;
	roadboarder2R.size.z = 50;
	roadboarder2R.size.y = 3.5;
	roadboarder2R.color = Blue;
	MyCubeMap.PushBack(roadboarder2R);
	bodcub3 = App->physics->AddBody(roadboarder2R, 0);
	bodcub3->SetPos(92.9, 0.5, 54.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);
	
	Cube roadboarder2L;
	roadboarder2L.size.x = 0.5;
	roadboarder2L.size.z = 50;
	roadboarder2L.size.y = 3.5;
	roadboarder2L.color = Blue;
	MyCubeMap.PushBack(roadboarder2L);
	bodcub3 = App->physics->AddBody(roadboarder2L, 0);
	bodcub3->SetPos(105.4, 0.5, 54.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve3L;
	roadcurve3L.size.x = 0.5;
	roadcurve3L.size.z = 40;
	roadcurve3L.size.y = 3.5;
	roadcurve3L.color = Blue;
	roadcurve3L.SetRotation(-45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve3L);
	bodcub3 = App->physics->AddBody(roadcurve3L, 0);
	bodcub3->SetPos(92, 0.5, 93);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve3R;
	roadcurve3R.size.x = 0.5;
	roadcurve3R.size.z = 20;
	roadcurve3R.size.y = 3.5;
	roadcurve3R.color = Blue;
	roadcurve3R.SetRotation(-45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve3R);
	bodcub3 = App->physics->AddBody(roadcurve3R, 0);
	bodcub3->SetPos(85.8, 0.5, 86.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadboarder3L;
	roadboarder3L.size.x = 100;
	roadboarder3L.size.z = 0.5;
	roadboarder3L.size.y = 3.5;
	roadboarder3L.color = Blue;
	MyCubeMap.PushBack(roadboarder3L);
	bodcub3 = App->physics->AddBody(roadboarder3L, 0);
	bodcub3->SetPos(28.8, 0.5, 93.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadboarder3R;
	roadboarder3R.size.x = 100;
	roadboarder3R.size.z = 0.5;
	roadboarder3R.size.y = 3.5;
	roadboarder3R.color = Blue;
	MyCubeMap.PushBack(roadboarder3R);
	bodcub3 = App->physics->AddBody(roadboarder3R, 0);
	bodcub3->SetPos(28.8, 0.5, 106);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve4R;
	roadcurve4R.size.x = 0.5;
	roadcurve4R.size.z = 20;
	roadcurve4R.size.y = 3.5;
	roadcurve4R.color = Blue;
	roadcurve4R.SetRotation(45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve4R);
	bodcub3 = App->physics->AddBody(roadcurve4R, 0);
	bodcub3->SetPos(-28.2, 0.5, 86.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve4L;
	roadcurve4L.size.x = 0.5;
	roadcurve4L.size.z = 40;
	roadcurve4L.size.y = 4;
	roadcurve4L.color = Blue;
	roadcurve4L.SetRotation(45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve4L);
	bodcub3 = App->physics->AddBody(roadcurve4L, 0);
	bodcub3->SetPos(-34, 0.5, 93);
	MyPhysbodyCubeMap.PushBack(bodcub3);


	Cube roadboarder4R;
	roadboarder4R.size.x = 0.5;
	roadboarder4R.size.z = 100;
	roadboarder4R.size.y = 4;
	roadboarder4R.color = Blue;
	MyCubeMap.PushBack(roadboarder4R);
	bodcub3 = App->physics->AddBody(roadboarder4R, 0);
	bodcub3->SetPos(-35.2, 0.5, 29.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadboarder4L;
	roadboarder4L.size.x = 0.5;
	roadboarder4L.size.z = 100;
	roadboarder4L.size.y = 3.5;
	roadboarder4L.color = Blue;
	MyCubeMap.PushBack(roadboarder4L);
	bodcub3 = App->physics->AddBody(roadboarder4L, 0);
	bodcub3->SetPos(-47.7, 0.5, 29.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve5R;
	roadcurve5R.size.x = 0.5;
	roadcurve5R.size.z = 40;
	roadcurve5R.size.y = 3.5;
	roadcurve5R.color = Blue;
	roadcurve5R.SetRotation(-45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve5R);
	bodcub3 = App->physics->AddBody(roadcurve5R, 0);
	bodcub3->SetPos(-33.5, 0.5, -34.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve5L;
	roadcurve5L.size.x = 0.5;
	roadcurve5L.size.z = 40;
	roadcurve5L.size.y = 3.5;
	roadcurve5L.color = Blue;
	roadcurve5L.SetRotation(-45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve5L);
	bodcub3 = App->physics->AddBody(roadcurve5L, 0);
	bodcub3->SetPos(-21, 0.5, -34.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve6L;
	roadcurve6L.size.x = 0.5;
	roadcurve6L.size.z = 40;
	roadcurve6L.size.y = 3.5;
	roadcurve6L.color = Blue;
	roadcurve6L.SetRotation(45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve6L);
	bodcub3 = App->physics->AddBody(roadcurve6L, 0);
	bodcub3->SetPos(-33.5, 0.5, -62.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve6R;
	roadcurve6R.size.x = 0.5;
	roadcurve6R.size.z = 60;
	roadcurve6R.size.y = 3.5;
	roadcurve6R.color = Blue;
	roadcurve6R.SetRotation(45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve6R);
	bodcub3 = App->physics->AddBody(roadcurve6R, 0);
	bodcub3->SetPos(-28, 0.5, -69.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve7L;
	roadcurve7L.size.x = 0.5;
	roadcurve7L.size.z = 40;
	roadcurve7L.size.y = 3.5;
	roadcurve7L.color = Blue;
	roadcurve7L.SetRotation(-45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve7L);
	bodcub3 = App->physics->AddBody(roadcurve7L, 0);
	bodcub3->SetPos(-61.5, 0.5, -62.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve7R;
	roadcurve7R.size.x = 0.5;
	roadcurve7R.size.z = 40;
	roadcurve7R.size.y = 3.5;
	roadcurve7R.color = Blue;
	roadcurve7R.SetRotation(-45, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve7R);
	bodcub3 = App->physics->AddBody(roadcurve7R, 0);
	bodcub3->SetPos(-61.5, 0.5, -75);
	MyPhysbodyCubeMap.PushBack(bodcub3);


	Cube roadboarder5L;
	roadboarder5L.size.x = 100;
	roadboarder5L.size.z = 0.5;
	roadboarder5L.size.y = 3.5;
	roadboarder5L.color = Blue;
	MyCubeMap.PushBack(roadboarder5L);
	bodcub3 = App->physics->AddBody(roadboarder5L, 0);
	bodcub3->SetPos(-125.5, 0.5, -48.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadboarder5R;
	roadboarder5R.size.x = 100;
	roadboarder5R.size.z = 0.5;
	roadboarder5R.size.y = 3.5;
	roadboarder5R.color = Blue;
	MyCubeMap.PushBack(roadboarder5R);
	bodcub3 = App->physics->AddBody(roadboarder5R, 0);
	bodcub3->SetPos(-125.5, 0.5, -61);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadboarderEnd;
	roadboarderEnd.size.x = 0.5;
	roadboarderEnd.size.z = 14;
	roadboarderEnd.size.y = 3.5;
	roadboarderEnd.color = Blue;
	MyCubeMap.PushBack(roadboarderEnd);
	bodcub3 = App->physics->AddBody(roadboarderEnd, 0);
	bodcub3->SetPos(-175.5, 0.5, -54.75);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube house_top;
	house_top.size.x = 10;
	house_top.size.z = 5;
	house_top.size.y = 2;
	house_top.color = Blue;
	MyCubeMap.PushBack(house_top);
	house_top_body = App->physics->AddBody(house_top, 0);
	house_top_body->SetPos(90, 8, -60);
	MyPhysbodyCubeMap.PushBack(house_top_body);

	Cube house_top2;
	house_top.size.x = 10;
	house_top.size.z = 5;
	house_top.size.y = 2;
	house_top.color = Blue;
	MyCubeMap.PushBack(house_top);
	house_top_body = App->physics->AddBody(house_top, 0);
	house_top_body->SetPos(90, 8, -20);
	MyPhysbodyCubeMap.PushBack(house_top_body);

	Cube house_top3;
	house_top3.size.x = 10;
	house_top3.size.z = 5;
	house_top3.size.y = 2;
	house_top3.color = Blue;
	MyCubeMap.PushBack(house_top3);
	house_top_body = App->physics->AddBody(house_top3, 0);
	house_top_body->SetPos(-40, 8, 60);
	MyPhysbodyCubeMap.PushBack(house_top_body);

	Cube house_top4;
	house_top4.size.x = 10;
	house_top4.size.z = 5;
	house_top4.size.y = 2;
	house_top4.color = Blue;
	MyCubeMap.PushBack(house_top4);
	house_top_body = App->physics->AddBody(house_top4, 0);
	house_top_body->SetPos(-40, 8, 30);
	MyPhysbodyCubeMap.PushBack(house_top_body);

	Cube house_top5;
	house_top5.size.x = 10;
	house_top5.size.z = 5;
	house_top5.size.y = 2;
	house_top5.color = Blue;
	MyCubeMap.PushBack(house_top5);
	house_top_body = App->physics->AddBody(house_top5, 0);
	house_top_body->SetPos(-40, 8, -10);
	MyPhysbodyCubeMap.PushBack(house_top_body);

	//-----Objects-----

	Sphere ballkicker;
	ballkicker.SetPos(1, 1, 1);
	ballkicker.radius = 1;
	MySphereObj.PushBack(ballkicker);
	

	ballkickerObject = App->physics->AddBody(ballkicker, 1);
	MyPhysbodySphereobj.PushBack(ballkickerObject);
	ballkickerObject->collision_listeners.add(this);

	Cube rect;
	rect.size.y = 3;
	MyCubeObj.PushBack(rect);

	PhysBody3D* RectObject;
	RectObject = App->physics->AddBody(rect, 0);
	MyPhysbodyCubeobj.PushBack(RectObject);

	//P2P Constraint to make ball kicker with rect 
	App->physics->Add_P2P_Constraint(*ballkickerObject->GetRigidBody(), *RectObject->GetRigidBody(), btVector3(0, 1, 0), btVector3(0, 1, 0), true);
	timer.Start();
	



	//-----Targets-----
	//---------Stage 2-------
	//-----enemy 2-------
	PhysBody3D* bodcub7;
	btHingeConstraint *enemyhinge;
	Create_Guy(&bodcub7, &enemyhinge, vec3(89, 0.1, -120), bad_guy,0);
	bodcub7->active = false;
	Stage2_guys_bodys.PushBack(bodcub7);
	Stage2_guys_hinges.PushBack(enemyhinge);
	//-----enemy 2-------
	PhysBody3D *bodcub9_enemy2;
	btHingeConstraint *enemyhinge3;
	Create_Guy(&bodcub9_enemy2, &enemyhinge3, vec3(100, 0.1, -120), bad_guy,0);
	bodcub9_enemy2->active = false;
	Stage2_guys_bodys.PushBack(bodcub9_enemy2);
	Stage2_guys_hinges.PushBack(enemyhinge3);
	//-----good guy 1-----
	PhysBody3D* bodcub8_good_guy1;
	btHingeConstraint *enemyhinge2;
	Create_Guy(&bodcub8_good_guy1, &enemyhinge2, vec3(75, 0.1, -125), good_guy,0);
	bodcub8_good_guy1->active = false;
	Stage2_guys_bodys.PushBack(bodcub8_good_guy1);
	Stage2_guys_hinges.PushBack(enemyhinge2);

	//-----good guy 2-----
	PhysBody3D* bodcub8_good_guy2;
	btHingeConstraint *goodguy_hinge2;
	Create_Guy(&bodcub8_good_guy2, &goodguy_hinge2, vec3(86, 0.1, -125), good_guy,0);
	bodcub8_good_guy2->active = false;
	Stage2_guys_bodys.PushBack(bodcub8_good_guy2);
	Stage2_guys_hinges.PushBack(goodguy_hinge2);


	//---------Stage 1-------

	//-----enemy 3-------
	PhysBody3D* bodcub9_enemy3;
	btHingeConstraint *hinge_enemy3;
	Create_Guy(&bodcub9_enemy3, &hinge_enemy3, vec3(89, 0.1, -180), bad_guy,0);
	bodcub9_enemy3->active = false;
	Stage1_guys_bodys.PushBack(bodcub9_enemy3);
	Stage1_guys_hinges.PushBack(hinge_enemy3);
	//-----goodguy 3-------
	PhysBody3D *bodcub9_goodguy3;
	btHingeConstraint *goodguyhinge3;
	Create_Guy(&bodcub9_goodguy3, &goodguyhinge3, vec3(100, 0.1, -180), good_guy,0);
	bodcub9_goodguy3->active = false;
	Stage1_guys_bodys.PushBack(bodcub9_goodguy3);
	Stage1_guys_hinges.PushBack(goodguyhinge3);
	//-----goodguy 4-----
	PhysBody3D* bodcub9_enemy4;
	btHingeConstraint *hinge_enemy4;
	Create_Guy(&bodcub9_enemy4, &hinge_enemy4, vec3(75, 0.1, -185), good_guy,0);
	bodcub9_enemy4->active = false;
	Stage1_guys_bodys.PushBack(bodcub9_enemy4);
	Stage1_guys_hinges.PushBack(hinge_enemy4);


	//-------stage 3------
	//-----enemy 5-----
	PhysBody3D* bodcub9_enemy5;
	btHingeConstraint *hinge_enemy5;
	Create_Guy(&bodcub9_enemy5, &hinge_enemy5, vec3(90, 9, -60), good_guy,0);
	bodcub9_enemy5->active = false;
	Stage3_guys_bodys.PushBack(bodcub9_enemy5);
	Stage3_guys_hinges.PushBack(hinge_enemy5);

	PhysBody3D* bodcub10_enemy6;
	btHingeConstraint *hinge_enemy6;
	Create_Guy(&bodcub10_enemy6, &hinge_enemy6, vec3(90, 9, -20), bad_guy,0);
	bodcub9_enemy5->active = false;
	Stage3_guys_bodys.PushBack(bodcub10_enemy6);
	Stage3_guys_hinges.PushBack(hinge_enemy6);

	PhysBody3D* bodcub11_enemy7;
	btHingeConstraint *hinge_enemy7;
	Create_Guy(&bodcub11_enemy7, &hinge_enemy7, vec3(100, 0.1, -25), bad_guy,0);
	bodcub9_enemy5->active = false;
	Stage3_guys_bodys.PushBack(bodcub11_enemy7);
	Stage3_guys_hinges.PushBack(hinge_enemy7);

	//------Stage 4------
	PhysBody3D* bodcub12_enemy8;
	btHingeConstraint *hinge_enemy8;
	Create_Guy(&bodcub12_enemy8, &hinge_enemy8, vec3(80, 0.1, 40), bad_guy,-45);
	bodcub12_enemy8->active = false;
	Stage4_guys_bodys.PushBack(bodcub12_enemy8);
	Stage4_guys_hinges.PushBack(hinge_enemy8);

	PhysBody3D* bodcub13_enemy9;
	btHingeConstraint *hinge_enemy9;
	Create_Guy(&bodcub13_enemy9, &hinge_enemy9, vec3(80, 0.1, 50), good_guy,-45);
	bodcub13_enemy9->active = false;
	Stage4_guys_bodys.PushBack(bodcub13_enemy9);
	Stage4_guys_hinges.PushBack(hinge_enemy9);

	PhysBody3D* bodcub14_enemy10;
	btHingeConstraint *hinge_enemy10;
	Create_Guy(&bodcub14_enemy10, &hinge_enemy10, vec3(80, 0.1, 60), bad_guy, -45);
	bodcub14_enemy10->active = false;
	Stage4_guys_bodys.PushBack(bodcub14_enemy10);
	Stage4_guys_hinges.PushBack(hinge_enemy10);

	PhysBody3D* bodcub15_enemy11;
	btHingeConstraint *hinge_enemy11;
	Create_Guy(&bodcub15_enemy11, &hinge_enemy11, vec3(115, 0.1, 100), bad_guy, 45);
	bodcub15_enemy11->active = false;
	Stage4_guys_bodys.PushBack(bodcub15_enemy11);
	Stage4_guys_hinges.PushBack(hinge_enemy11);

	PhysBody3D* bodcub16_enemy12;
	btHingeConstraint *hinge_enemy12;
	Create_Guy(&bodcub16_enemy12, &hinge_enemy12, vec3(105, 0.1, 110), good_guy, 45);
	bodcub16_enemy12->active = false;
	Stage4_guys_bodys.PushBack(bodcub16_enemy12);
	Stage4_guys_hinges.PushBack(hinge_enemy12);

	PhysBody3D* bodcub17_enemy13;
	btHingeConstraint *hinge_enemy13;
	Create_Guy(&bodcub17_enemy13, &hinge_enemy13, vec3(60, 0.1, 120), good_guy, -45);
	bodcub17_enemy13->active = false;
	Stage4_guys_bodys.PushBack(bodcub17_enemy13);
	Stage4_guys_hinges.PushBack(hinge_enemy13);

	PhysBody3D* bodcub18_enemy14;
	btHingeConstraint *hinge_enemy14;
	Create_Guy(&bodcub18_enemy14, &hinge_enemy14, vec3(60, 0.1, 83), bad_guy, 180);
	bodcub18_enemy14->active = false;
	Stage4_guys_bodys.PushBack(bodcub18_enemy14);
	Stage4_guys_hinges.PushBack(hinge_enemy14);

	PhysBody3D* bodcub19_enemy15;
	btHingeConstraint *hinge_enemy15;
	Create_Guy(&bodcub19_enemy15, &hinge_enemy15, vec3(30, 0.1, 110), good_guy, 0);
	bodcub19_enemy15->active = false;
	Stage4_guys_bodys.PushBack(bodcub19_enemy15);
	Stage4_guys_hinges.PushBack(hinge_enemy15);

	PhysBody3D* bodcub20_enemy16;
	btHingeConstraint *hinge_enemy16;
	Create_Guy(&bodcub20_enemy16, &hinge_enemy16, vec3(10, 0.1, 83), bad_guy, 180);
	bodcub20_enemy16->active = false;
	Stage4_guys_bodys.PushBack(bodcub20_enemy16);
	Stage4_guys_hinges.PushBack(hinge_enemy16);

	PhysBody3D* bodcub21_enemy17;
	btHingeConstraint *hinge_enemy17;
	Create_Guy(&bodcub21_enemy17, &hinge_enemy17, vec3(-40, 0.1, 99), bad_guy, -90);
	bodcub21_enemy17->active = false;
	Stage5_guys_bodys.PushBack(bodcub21_enemy17);
	Stage5_guys_hinges.PushBack(hinge_enemy17);

	PhysBody3D* bodcub22_enemy18;
	btHingeConstraint *hinge_enemy18;
	Create_Guy(&bodcub22_enemy18, &hinge_enemy18, vec3(-60, 0.1, 80), good_guy, -90);
	bodcub22_enemy18->active = false;
	Stage5_guys_bodys.PushBack(bodcub22_enemy18);
	Stage5_guys_hinges.PushBack(hinge_enemy18);

	PhysBody3D* bodcub23_enemy19;
	btHingeConstraint *hinge_enemy19;
	Create_Guy(&bodcub23_enemy19, &hinge_enemy19, vec3(-40, 9, 60), bad_guy, 180);
	bodcub23_enemy19->active = false;
	Stage5_guys_bodys.PushBack(bodcub23_enemy19);
	Stage5_guys_hinges.PushBack(hinge_enemy19);

	PhysBody3D* bodcub24_enemy20;
	btHingeConstraint *hinge_enemy20;
	Create_Guy(&bodcub24_enemy20, &hinge_enemy20, vec3(-40, 9, 30), good_guy, 180);
	bodcub24_enemy20->active = false;
	Stage5_guys_bodys.PushBack(bodcub24_enemy20);
	Stage5_guys_hinges.PushBack(hinge_enemy20);

	PhysBody3D* bodcub25_enemy21;
	btHingeConstraint *hinge_enemy21;
	Create_Guy(&bodcub25_enemy21, &hinge_enemy21, vec3(-40, 9, -10), bad_guy, 180);
	bodcub25_enemy21->active = false;
	Stage5_guys_bodys.PushBack(bodcub25_enemy21);
	Stage5_guys_hinges.PushBack(hinge_enemy21);

	PhysBody3D* bodcub26_enemy22;
	btHingeConstraint *hinge_enemy22;
	Create_Guy(&bodcub26_enemy22, &hinge_enemy22, vec3(-70, 0.1, -40), bad_guy, 0);
	bodcub26_enemy22->active = false;
	Stage6_guys_bodys.PushBack(bodcub26_enemy22);
	Stage6_guys_hinges.PushBack(hinge_enemy22);

	PhysBody3D* bodcub27_enemy23;
	btHingeConstraint *hinge_enemy23;
	Create_Guy(&bodcub27_enemy23, &hinge_enemy23, vec3(-50, 0.1, -40), bad_guy, -45);
	bodcub27_enemy23->active = false;
	Stage6_guys_bodys.PushBack(bodcub27_enemy23);
	Stage6_guys_hinges.PushBack(hinge_enemy23);

	PhysBody3D* bodcub28_enemy24;
	btHingeConstraint *hinge_enemy24;
	Create_Guy(&bodcub28_enemy24, &hinge_enemy24, vec3(-30, 0.1, -80), bad_guy, 180);
	bodcub28_enemy24->active = false;
	Stage6_guys_bodys.PushBack(bodcub28_enemy24);
	Stage6_guys_hinges.PushBack(hinge_enemy24);

	//SENSOR
	Cube cub_7_6_Sensor;
	PhysBody3D*bodcub_7_6_Sensor;
	cub_7_6_Sensor.size.x = 10;
	cub_7_6_Sensor.size.z = 2;
	cub_7_6_Sensor.size.y = 3;
	MySensorCube.PushBack(cub_7_6_Sensor);
	bodcub_7_6_Sensor = App->physics->AddBody(cub_7_6_Sensor, 0);
	bodcub_7_6_Sensor->SetPos(89, 2, -220);

	bodcub_7_6_Sensor->SetAsSensor(true);
	bodcub_7_6_Sensor->collision_listeners.add(this);
	MySensorCubeBody.PushBack(bodcub_7_6_Sensor);


	//----
	Cube cub_Sensor2;
	PhysBody3D* bodcub_Sensor2;
	cub_Sensor2.size.x = 10;
	cub_Sensor2.size.z = 2;
	cub_Sensor2.size.y = 3;
	MySensorCube.PushBack(cub_Sensor2);
	bodcub_Sensor2 = App->physics->AddBody(cub_Sensor2, 0);
	bodcub_Sensor2->SetPos(89, 2, -155);

	bodcub_Sensor2->SetAsSensor(true);
	bodcub_Sensor2->collision_listeners.add(this);
	MySensorCubeBody.PushBack(bodcub_Sensor2);



	//---- sensor 3----
	Cube cub_Sensor3;
	PhysBody3D* bodcub_Sensor3;
	cub_Sensor3.size.x = 10;
	cub_Sensor3.size.z = 2;
	cub_Sensor3.size.y = 3;
	MySensorCube.PushBack(cub_Sensor3);
	bodcub_Sensor3 = App->physics->AddBody(cub_Sensor3, 0);
	bodcub_Sensor3->SetPos(89, 2, -100);

	bodcub_Sensor3->SetAsSensor(true);
	bodcub_Sensor3->collision_listeners.add(this);
	MySensorCubeBody.PushBack(bodcub_Sensor3);


	//---- sensor 4----
	Cube cub_Sensor4;
	PhysBody3D* bodcub_Sensor4;
	cub_Sensor4.size.x = 10;
	cub_Sensor4.size.z = 2;
	cub_Sensor4.size.y = 5;
	MySensorCube.PushBack(cub_Sensor4);
	bodcub_Sensor4 = App->physics->AddBody(cub_Sensor4, 0);
	bodcub_Sensor4->SetPos(88, 2, 10);

	bodcub_Sensor4->SetAsSensor(true);
	bodcub_Sensor4->collision_listeners.add(this);
	MySensorCubeBody.PushBack(bodcub_Sensor4);

	//---- sensor 5----
	Cube cub_Sensor5;
	PhysBody3D* bodcub_Sensor5;
	cub_Sensor5.size.x = 13;
	cub_Sensor5.size.z = 3;
	cub_Sensor5.size.y = 10;
	cub_Sensor5.SetRotation(90,vec3(0,1,0));
	MySensorCube.PushBack(cub_Sensor5);
	bodcub_Sensor5 = App->physics->AddBody(cub_Sensor5, 0);
	bodcub_Sensor5->SetPos(10, 0.1, 99);

	bodcub_Sensor5->SetAsSensor(true);
	bodcub_Sensor5->collision_listeners.add(this);
	MySensorCubeBody.PushBack(bodcub_Sensor5);

	//---- sensor 6----
	Cube cub_Sensor6;
	PhysBody3D* bodcub_Sensor6;
	cub_Sensor6.size.x = 13;
	cub_Sensor6.size.z = 3;
	cub_Sensor6.size.y = 10;
	
	MySensorCube.PushBack(cub_Sensor6);
	bodcub_Sensor6 = App->physics->AddBody(cub_Sensor6, 0);
	bodcub_Sensor6->SetPos(-40, 0.1, -20);

	bodcub_Sensor6->SetAsSensor(true);
	bodcub_Sensor6->collision_listeners.add(this);
	MySensorCubeBody.PushBack(bodcub_Sensor6);

	//---- sensor 7----
	Cube cub_Sensor7;
	PhysBody3D* bodcub_Sensor7;
	cub_Sensor7.size.x = 3;
	cub_Sensor7.size.z = 13;
	cub_Sensor7.size.y = 10;
	MySensorCube.PushBack(cub_Sensor7);
	bodcub_Sensor7 = App->physics->AddBody(cub_Sensor7,0);
	bodcub_Sensor7->SetPos(-140.5, 0.5, -54.75);

	bodcub_Sensor7->SetAsSensor(true);
	bodcub_Sensor7->collision_listeners.add(this);
	MySensorCubeBody.PushBack(bodcub_Sensor7);
	
	return ret;
}




// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

void ModuleSceneIntro::Create_Guy(PhysBody3D **body, btHingeConstraint **hinge, vec3 position, guy guy_type, float angle)
{
	Cube cub_base;
	PhysBody3D*bodcub_base;
	cub_base.size.x = 4;
	cub_base.size.z = 0.5;
	cub_base.size.y = 0;
	cub_base.color = Black;
	if (angle != 0) {
		cub_base.SetRotation(angle, vec3(0, 1, 0));
	}
	MyCubeMap.PushBack(cub_base);
	bodcub_base = App->physics->AddBody(cub_base, 0);
	bodcub_base->SetPos(position.x, position.y, position.z);
	MyPhysbodyCubeMap.PushBack(bodcub_base);


	Cube cub_enemy_good;
	cub_enemy_good.size.x = 4;
	cub_enemy_good.size.z = 0;
	cub_enemy_good.size.y = 5;
	if (angle != 0) {
		cub_enemy_good.SetRotation(angle, vec3(0, 1, 0));
	}
	if (guy_type == good_guy) {
		cub_enemy_good.color = Green;
	}
	else {
		cub_enemy_good.color = Red;
	}
	MyCubeMap.PushBack(cub_enemy_good);
	PhysBody3D* bodcub_enemy_good;
	bodcub_enemy_good = App->physics->AddBody(cub_enemy_good, 1);
	bodcub_enemy_good->collision_listeners.add(this);
	bodcub_enemy_good->SetPos(position.x, 5, position.z);
	if (guy_type == good_guy) {
		bodcub_enemy_good->type_guy = good_guy;
	}
	else {
		bodcub_enemy_good->type_guy = bad_guy;
	}
	MyPhysbodyCubeMap.PushBack(bodcub_enemy_good);
	btVector3 anchor_bodcub6(0, 0, 0);
	btVector3 anchor_bodcub7(0, -cub_enemy_good.size.y / 2, 0.01);
	btVector3 axis_bod_6_7(1, 0, 0);
	*body = bodcub_enemy_good;

	btHingeConstraint *guy_hinge;
	guy_hinge = App->physics->Add_Hinge_Constraint(*bodcub_base->GetRigidBody(), *bodcub_enemy_good->GetRigidBody(), anchor_bodcub6, anchor_bodcub7, axis_bod_6_7, axis_bod_6_7, true);
	guy_hinge->setLimit(-3.14 * 0.5, 0);
	*hinge = guy_hinge;
}


update_status ModuleSceneIntro::PreUpdate(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
		Reset();

	for (int i = 0; i < App->player->CanonBallsBody.Count(); i++) 
	{
		if (App->player->CanonBallsBody[i]->tokill == true)
		{

			App->physics->DestroyBody(*App->player->CanonBallsBody[i]);
			App->player->CanonBallsSpheres.Remove(i);
			App->player->CanonBallsBody.Remove(i);
			
		}
	}

	return UPDATE_CONTINUE;
}


// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	for (int i=0; i < MyCubeMap.Count(); i++) {
		MyPhysbodyCubeMap[i]->GetTransform(&MyCubeMap[i].transform);
		MyCubeMap[i].Render();
	
	}
	for (int i = 0; i < MySphereObj.Count(); i++) {
		MyPhysbodySphereobj[i]->GetTransform(&MySphereObj[i].transform);
		MySphereObj[i].Render();

	}
	for (int i = 0; i < MyCubeObj.Count(); i++) {
		MyPhysbodyCubeobj[i]->GetTransform(&MyCubeObj[i].transform);
		MyCubeObj[i].Render();
	}
	

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	int timepassed;
	for (int i = 0; i < App->player->CanonBallsBody.Count(); i++) {
		timepassed = timer.ReadMs();
		if ((ballkickerObject == body1 ) && ( App->player->CanonBallsBody[i] == body2) && (timepassed>=1000)) {
			App->player->puntuation += 10;
			LOG("Puntuation: %i", App->player->puntuation);
	
			timer.Start();
		}

		if ((PlainGame_Body == body1) && (App->player->CanonBallsBody[i] == body2)) {
			body2->tokill = true;
			timer.Start();
		}

		for (int x = 0; x < Stage1_guys_bodys.Count(); x++) {
			if ((Stage1_guys_bodys[x] == body1 || Stage1_guys_bodys[x] == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && Stage1_guys_bodys[x]->active == true) {
				Stage1_guys_hinges[x]->enableMotor(false);
				if (Stage1_guys_bodys[x]->type_guy == bad_guy) {
					App->player->puntuation += 20;
				}
				else {
					App->player->puntuation -= 10;
				}
				body2->tokill = true;
				Stage1_guys_bodys[x]->active = false;
			}
		}


		for (int x = 0; x < Stage2_guys_bodys.Count(); x++) {
			if ((Stage2_guys_bodys[x] == body1 || Stage2_guys_bodys[x] == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && Stage2_guys_bodys[x]->active == true) {
				Stage2_guys_hinges[x]->enableMotor(false);
				if (Stage2_guys_bodys[x]->type_guy == bad_guy) {
					App->player->puntuation += 20;
				}
				else {
					App->player->puntuation -= 10;
				}
				body2->tokill = true;
				Stage2_guys_bodys[x]->active = false;
			}
		}

		for (int x = 0; x < Stage3_guys_bodys.Count(); x++) {
			if ((Stage3_guys_bodys[x] == body1 || Stage3_guys_bodys[x] == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && Stage3_guys_bodys[x]->active == true) {
				Stage3_guys_hinges[x]->enableMotor(false);
				if (Stage3_guys_bodys[x]->type_guy == bad_guy) {
					App->player->puntuation += 20;
				}
				else {
					App->player->puntuation -= 10;
				}
				body2->tokill = true;
				Stage3_guys_bodys[x]->active = false;
			}
		}

		for (int x = 0; x < Stage4_guys_bodys.Count(); x++) {
			if ((Stage4_guys_bodys[x] == body1 || Stage4_guys_bodys[x] == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && Stage4_guys_bodys[x]->active == true) {
				Stage4_guys_hinges[x]->enableMotor(false);
				if (Stage4_guys_bodys[x]->type_guy == bad_guy) {
					App->player->puntuation += 20;
				}
				else {
					App->player->puntuation -= 10;
				}
				body2->tokill = true;
				Stage4_guys_bodys[x]->active = false;
			}
		}

		for (int x = 0; x < Stage5_guys_bodys.Count(); x++) {
			if ((Stage5_guys_bodys[x] == body1 || Stage5_guys_bodys[x] == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && Stage5_guys_bodys[x]->active == true) {
				Stage5_guys_hinges[x]->enableMotor(false);
				if (Stage5_guys_bodys[x]->type_guy == bad_guy) {
					App->player->puntuation += 20;
				}
				else {
					App->player->puntuation -= 10;
				}
				body2->tokill = true;
				Stage5_guys_bodys[x]->active = false;
			}
		}

		for (int x = 0; x < Stage6_guys_bodys.Count(); x++) {
			if ((Stage6_guys_bodys[x] == body1 || Stage6_guys_bodys[x] == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && Stage6_guys_bodys[x]->active == true) {
				Stage6_guys_hinges[x]->enableMotor(false);
				if (Stage6_guys_bodys[x]->type_guy == bad_guy) {
					App->player->puntuation += 20;
				}
				else {
					App->player->puntuation -= 10;
				}
				body2->tokill = true;
				Stage6_guys_bodys[x]->active = false;
			}
		}
	}

	if (MySensorCubeBody[0] == body1 && App->player->turret == body2 && MySensorCubeBody[0]->active==true) {
		Stage_Activation(1);
		MySensorCubeBody[0]->active = false;
	}

	if (MySensorCubeBody[1] == body1 && App->player->turret == body2 && MySensorCubeBody[1]->active == true) {
		Stage_Activation(2);
 		MySensorCubeBody[1]->active = false;
	}

	if (MySensorCubeBody[2] == body1 && App->player->turret == body2 && MySensorCubeBody[2]->active == true) {
		Stage_Activation(3);
		MySensorCubeBody[2]->active = false;
	}

	if (MySensorCubeBody[3] == body1 && App->player->turret == body2 && MySensorCubeBody[3]->active == true) {
		Stage_Activation(4);
		MySensorCubeBody[3]->active = false;
	}

	if (MySensorCubeBody[4] == body1 && App->player->turret == body2 && MySensorCubeBody[4]->active == true) {
		Stage_Activation(5);
		MySensorCubeBody[4]->active = false;
	}

	if (MySensorCubeBody[5] == body1 && App->player->turret == body2 && MySensorCubeBody[5]->active == true) {
		Stage_Activation(6);
		MySensorCubeBody[5]->active = false;
	}

	if (MySensorCubeBody[6] == body1 && App->player->turret == body2 && MySensorCubeBody[6]->active == true) {
		App->audio->StopMusic();
		App->audio->PlayFx(finish_sound);
		
		win = true;
		MySensorCubeBody[6]->active = false;
		
		App->player->EndGameScore();

	}
}


void ModuleSceneIntro::Stage_Activation(int stage)
{
	//----enemy_1
	if (stage == 1) {
		for (int x = 0; x < Stage1_guys_bodys.Count(); x++) {
			Stage1_guys_bodys[x]->body->activate(true);
			Stage1_guys_bodys[x]->active = true;
			Stage1_guys_hinges[x]->enableMotor(true);
			Stage1_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage1_guys_hinges[x]->setMotorTargetVelocity(10);
		}
	}
	else if (stage == 2) {
		for (int x = 0; x < Stage2_guys_bodys.Count(); x++) {
			Stage2_guys_bodys[x]->body->activate(true);
			Stage2_guys_bodys[x]->active = true;
			Stage2_guys_hinges[x]->enableMotor(true);
			Stage2_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage2_guys_hinges[x]->setMotorTargetVelocity(10);
		}
	}
	else if (stage == 3) {
		for (int x = 0; x < Stage3_guys_bodys.Count(); x++) {
			Stage3_guys_bodys[x]->body->activate(true);
			Stage3_guys_bodys[x]->active = true;
			Stage3_guys_hinges[x]->enableMotor(true);
			Stage3_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage3_guys_hinges[x]->setMotorTargetVelocity(10);
		}
	}

	else if (stage == 4) {
		for (int x = 0; x < Stage4_guys_bodys.Count(); x++) {
			Stage4_guys_bodys[x]->body->activate(true);
			Stage4_guys_bodys[x]->active = true;
			Stage4_guys_hinges[x]->enableMotor(true);
			Stage4_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage4_guys_hinges[x]->setMotorTargetVelocity(10);
		}
	}
	else if (stage == 5) {
		for (int x = 0; x < Stage5_guys_bodys.Count(); x++) {
			Stage5_guys_bodys[x]->body->activate(true);
			Stage5_guys_bodys[x]->active = true;
			Stage5_guys_hinges[x]->enableMotor(true);
			Stage5_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage5_guys_hinges[x]->setMotorTargetVelocity(10);
		}
	}
	else if (stage == 6) {
		for (int x = 0; x < Stage6_guys_bodys.Count(); x++) {
			Stage6_guys_bodys[x]->body->activate(true);
			Stage6_guys_bodys[x]->active = true;
			Stage6_guys_hinges[x]->enableMotor(true);
			Stage6_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage6_guys_hinges[x]->setMotorTargetVelocity(10);
		}
	}
}

void ModuleSceneIntro::Reset()
{
	App->audio->ResumeMusic();
	App->player->timelimit.Start();
	App->player->puntuation = 0;
	mat4x4 A(1,0,0,0,0,1,0,0,0,0,1,0,88,2,-232,1);
	App->player->vehicle->SetTransform(A.M);
	A[0] = 0;
	A[2] = 1;
	A[8] = -1;
	A[10] = 0;
	A[13] = 5;
	App->player->canonbody->SetTransform(A.M);
	App->player->turret->SetTransform(A.M);

	win = false;
	for (int i = 0; i < MySensorCubeBody.Count(); i++) {
		MySensorCubeBody[i]->active = true;
	}
	for (int x = 0; x < Stage1_guys_bodys.Count(); x++) {
		if (Stage1_guys_bodys[x]->active == true) {
			Stage1_guys_bodys[x]->body->activate(true);
			Stage1_guys_hinges[x]->enableMotor(true);
			Stage1_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage1_guys_hinges[x]->setMotorTargetVelocity(-100000);
			Stage1_guys_bodys[x]->active = false;
		}
	}

	for (int x = 0; x < Stage2_guys_bodys.Count(); x++) {
		if (Stage2_guys_bodys[x]->active == true) {
			Stage2_guys_bodys[x]->body->activate(true);
			Stage2_guys_hinges[x]->enableMotor(true);
			Stage2_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage2_guys_hinges[x]->setMotorTargetVelocity(-100000);
			Stage2_guys_bodys[x]->active = false;
		}
	}

	for (int x = 0; x < Stage3_guys_bodys.Count(); x++) {
		if (Stage3_guys_bodys[x]->active == true) {
			Stage3_guys_bodys[x]->body->activate(true);
			Stage3_guys_hinges[x]->enableMotor(true);
			Stage3_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage3_guys_hinges[x]->setMotorTargetVelocity(-100000);
			Stage3_guys_bodys[x]->active = false;
		}
	}

	for (int x = 0; x < Stage4_guys_bodys.Count(); x++) {
		if (Stage4_guys_bodys[x]->active == true) {
			Stage4_guys_bodys[x]->body->activate(true);
			Stage4_guys_hinges[x]->enableMotor(true);
			Stage4_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage4_guys_hinges[x]->setMotorTargetVelocity(-100000);
			Stage4_guys_bodys[x]->active = false;
		}
	}

	for (int x = 0; x < Stage5_guys_bodys.Count(); x++) {
		if (Stage5_guys_bodys[x]->active == true) {
			Stage5_guys_bodys[x]->body->activate(true);
			Stage5_guys_hinges[x]->enableMotor(true);
			Stage5_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage5_guys_hinges[x]->setMotorTargetVelocity(-100000);
			Stage5_guys_bodys[x]->active = false;
		}
	}

	for (int x = 0; x < Stage6_guys_bodys.Count(); x++) {
		if (Stage6_guys_bodys[x]->active == true) {
			Stage6_guys_bodys[x]->body->activate(true);
			Stage6_guys_hinges[x]->enableMotor(true);
			Stage6_guys_hinges[x]->setMaxMotorImpulse(10);
			Stage6_guys_hinges[x]->setMotorTargetVelocity(-100000);
			Stage6_guys_bodys[x]->active = false;
		}
	}

}


