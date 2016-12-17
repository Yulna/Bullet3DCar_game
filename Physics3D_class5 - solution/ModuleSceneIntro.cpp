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

	//App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	//App->camera->LookAt(vec3(0, 0, 0));

	
	//------Map-----

	Cube cub1;
	PhysBody3D*bodcub1;
	cub1.size.x = 0.5;
	cub1.size.z = 200;
	cub1.size.y = 2;
	cub1.color = Blue;
	MyCubeMap.PushBack(cub1);
	bodcub1 = App->physics->AddBody(cub1, 0);
	bodcub1->SetPos(95.5, 0.5, -122);
	MyPhysbodyCubeMap.PushBack(bodcub1);

	Cube cub2;
	PhysBody3D*bodcub2;
	cub2.size.x = 0.5;
	cub2.size.z = 200;
	cub2.size.y = 2;
	cub2.color = Blue;
	MyCubeMap.PushBack(cub2);
	bodcub2 = App->physics->AddBody(cub2, 0);
	bodcub2->SetPos(83, 0.5, -122);
	MyPhysbodyCubeMap.PushBack(bodcub2);


	Cube cub3;
	PhysBody3D*bodcub3;
	cub3.size.x = 0.5;
	cub3.size.z = 10;
	cub3.size.y = 2;
	cub3.color = Blue;
	cub3.SetRotation(-3.14, vec3(0, 1, 0));
	MyCubeMap.PushBack(cub3);
	bodcub3 = App->physics->AddBody(cub3, 0);
	bodcub3->SetPos(83, 0.5, -22);
	MyPhysbodyCubeMap.PushBack(bodcub3);


	/*Cube cub2;
	PhysBody3D*bodcub2;
	cub2.size.x = 8;
	cub2.size.z = 200;
	MyCubeMap.PushBack(cub2);
	bodcub2 = App->physics->AddBody(cub2, 0);
	bodcub2->SetPos(8, 0, 2);
	MyPhysbodyCubeMap.PushBack(bodcub2);
	
	Cube cub3;
	PhysBody3D*bodcub3;
	cub3.size.x = 110;
	cub3.size.z = 8;
	MyCubeMap.PushBack(cub3);
	bodcub3 = App->physics->AddBody(cub3, 0);
	bodcub3->SetPos(51.5, 0, 105.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube cub4;
	PhysBody3D*bodcub4;
	cub4.size.x = 110;
	cub4.size.z = 8;
	MyCubeMap.PushBack(cub4);
	bodcub4 = App->physics->AddBody(cub4, 0);
	bodcub4->SetPos(51.5, 0, 113.5);
	MyPhysbodyCubeMap.PushBack(bodcub4);*/

	/*Cube cub5;
	PhysBody3D*bodcub5;
	cub5.size.x = 8;
	cub5.size.z = 200;
	MyCubeMap.PushBack(cub5);
	bodcub5 = App->physics->AddBody(cub5, 0);
	bodcub5->SetPos(94.5, -0.5, -30);
	MyPhysbodyCubeMap.PushBack(bodcub5);
	*/
	Cube PlainGame;
	PhysBody3D*PlainGame_Body;
	PlainGame.size.x = 500;
	PlainGame.size.z = 500;
	MyCubeMap.PushBack(PlainGame);
	PlainGame_Body = App->physics->AddBody(PlainGame, 0);
	PlainGame_Body->SetPos(102.5, -0.5, -30);
	MyPhysbodyCubeMap.PushBack(PlainGame_Body);

	/*Cube cub7;
	PhysBody3D*bodcub7;
	cub7.size.x = 110;
	cub7.size.z = 8;
	MyCubeMap.PushBack(cub7);
	bodcub7 = App->physics->AddBody(cub7, 0);
	bodcub7->SetPos(51.5, 0, -102);
	MyPhysbodyCubeMap.PushBack(bodcub7);

	Cube cub8;
	PhysBody3D*bodcub8;
	cub8.size.x = 110;
	cub8.size.z = 8;
	MyCubeMap.PushBack(cub8);
	bodcub8 = App->physics->AddBody(cub8, 0);
	bodcub8->SetPos(51.5, 0, -110);
	MyPhysbodyCubeMap.PushBack(bodcub8);*/


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

	Cube cub6;
	PhysBody3D*bodcub6;
	cub6.size.x = 4;
	cub6.size.z = 0.5;
	cub6.size.y = 0;
	cub6.color = Black;
	MyCubeMap.PushBack(cub6);
	bodcub6 = App->physics->AddBody(cub6, 0);
	bodcub6->SetPos(89, 1, -200);

	MyPhysbodyCubeMap.PushBack(bodcub6);

	Cube cub7;
	
	cub7.size.x = 4;
	cub7.size.z = 0;
	cub7.size.y = 5;
	cub7.color = Red;
	MyCubeMap.PushBack(cub7);
	bodcub7 = App->physics->AddBody(cub7, 1);
	bodcub7->collision_listeners.add(this);
	bodcub7->SetPos(89, 10, -200);
	MyPhysbodyCubeMap.PushBack(bodcub7);
	
	
	btVector3 anchor_bodcub6(0,0,0);
	btVector3 anchor_bodcub7(0, -cub7.size.y/2, 0.01);
	btVector3 axis_bod_6_7(1, 0, 0);
	
	enemyhinge = App->physics->Add_Hinge_Constraint(*bodcub6->GetRigidBody(), *bodcub7->GetRigidBody(), anchor_bodcub6, anchor_bodcub7, axis_bod_6_7, axis_bod_6_7, true);
	enemyhinge->setLimit(-3.14 * 0.5, 0);
	
	
	//SENSOR
	Cube cub_7_6_Sensor;
	PhysBody3D*bodcub_7_6_Sensor;
	cub_7_6_Sensor.size.x = 10;
	cub_7_6_Sensor.size.z = 2;
	cub_7_6_Sensor.size.y = 3;
	MySensorCube.PushBack(cub_7_6_Sensor);
	bodcub_7_6_Sensor = App->physics->AddBody(cub_7_6_Sensor, 0);
	bodcub_7_6_Sensor->SetPos(89, 2, -213);

	bodcub_7_6_Sensor->SetAsSensor(true);
	bodcub_7_6_Sensor->collision_listeners.add(this);
	MySensorCubeBody.PushBack(bodcub_7_6_Sensor);


	//----
	
	
	
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
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
		if ((ballkickerObject == body1 || ballkickerObject == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2) && (timepassed>=1000)) {
			App->player->puntuation += 10;
			LOG("Puntuation: %i", App->player->puntuation);
			timer.Start();
		}
	
		if ((bodcub7 == body1 || bodcub7 == body2) && (App->player->CanonBallsBody[i] == body1 || App->player->CanonBallsBody[i] == body2)) {
			enemyhinge->enableMotor(false);
		}

	}

	if (MySensorCubeBody[0] == body1 && App->player->turret == body2) {
		bodcub7->body->activate(true);
		enemyhinge->enableMotor(true);
		enemyhinge->setMaxMotorImpulse(10);
		enemyhinge->setMotorTargetVelocity(10);
	}
}

