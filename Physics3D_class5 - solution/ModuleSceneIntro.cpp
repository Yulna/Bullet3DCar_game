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
	//Surface
	Cube PlainGame;

	PlainGame.size.x = 500;
	PlainGame.size.z = 500;
	MyCubeMap.PushBack(PlainGame);
	PlainGame_Body = App->physics->AddBody(PlainGame, 0);
	PlainGame_Body->SetPos(102.5, -0.5, -30);
	PlainGame_Body->collision_listeners.add(this);
	MyPhysbodyCubeMap.PushBack(PlainGame_Body);



	Cube roadboarder1L;
	PhysBody3D*bodcub1;
	roadboarder1L.size.x = 0.5;
	roadboarder1L.size.z = 200;
	roadboarder1L.size.y = 2;
	roadboarder1L.color = Blue;
	MyCubeMap.PushBack(roadboarder1L);
	bodcub1 = App->physics->AddBody(roadboarder1L, 0);
	bodcub1->SetPos(95.5, 0.5, -122);
	MyPhysbodyCubeMap.PushBack(bodcub1);

	Cube roadboarder1R;
	PhysBody3D*bodcub2;
	roadboarder1R.size.x = 0.5;
	roadboarder1R.size.z = 200;
	roadboarder1R.size.y = 2;
	roadboarder1R.color = Blue;
	MyCubeMap.PushBack(roadboarder1R);
	bodcub2 = App->physics->AddBody(roadboarder1R, 0);
	bodcub2->SetPos(83, 0.5, -122);
	MyPhysbodyCubeMap.PushBack(bodcub2);
	

	Cube roadcurve1R;
	PhysBody3D*bodcub3;
	roadcurve1R.size.x = 0.5;
	roadcurve1R.size.z = 20;
	roadcurve1R.size.y = 2;
	roadcurve1R.color = Blue;
	roadcurve1R.SetRotation(-30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve1R);
	bodcub3 = App->physics->AddBody(roadcurve1R, 0);
	bodcub3->SetPos(78, 0.5, -13.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);
	

	Cube roadcurve1L;
	roadcurve1L.size.x = 0.5;
	roadcurve1L.size.z = 20;
	roadcurve1L.size.y = 2;
	roadcurve1L.color = Blue;
	roadcurve1L.SetRotation(-30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve1L);
	bodcub3 = App->physics->AddBody(roadcurve1L, 0);
	bodcub3->SetPos(90.5, 0.5, -13.5);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve2L;
	roadcurve2L.size.x = 0.5;
	roadcurve2L.size.z = 40;
	roadcurve2L.size.y = 2;
	roadcurve2L.color = Blue;
	roadcurve2L.SetRotation(30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve2L);
	bodcub3 = App->physics->AddBody(roadcurve2L, 0);
	bodcub3->SetPos(95.5, 0.5, 12.25);
	MyPhysbodyCubeMap.PushBack(bodcub3);

	Cube roadcurve2R;
	roadcurve2R.size.x = 0.5;
	roadcurve2R.size.z = 40;
	roadcurve2R.size.y = 2;
	roadcurve2R.color = Blue;
	roadcurve2R.SetRotation(30, vec3(0, 1, 0));
	MyCubeMap.PushBack(roadcurve2R);
	bodcub3 = App->physics->AddBody(roadcurve2R, 0);
	bodcub3->SetPos(83, 0.5, 12.25);
	MyPhysbodyCubeMap.PushBack(bodcub3);
	

	


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

	//-----enemy 1-------
	PhysBody3D* bodcub7;
	btHingeConstraint *enemyhinge;
	Create_Guy(&bodcub7, &enemyhinge, vec3(89, 0.1, -200), bad_guy);
	Stage1_guys_bodys.PushBack(bodcub7);
	Stage1_guys_hinges.PushBack(enemyhinge);
	//-----enemy 2-------
	PhysBody3D *bodcub9_enemy2;
	btHingeConstraint *enemyhinge3;
	Create_Guy(&bodcub9_enemy2, &enemyhinge3, vec3(100, 0.1, -200), bad_guy);
	Stage1_guys_bodys.PushBack(bodcub9_enemy2);
	Stage1_guys_hinges.PushBack(enemyhinge3);
	//-----good guy 1-----
	PhysBody3D* bodcub8_good_guy1;
	btHingeConstraint *enemyhinge2;
	Create_Guy(&bodcub8_good_guy1, &enemyhinge2, vec3(75, 0.1, -180), good_guy);
	Stage1_guys_bodys.PushBack(bodcub8_good_guy1);
	Stage1_guys_hinges.PushBack(enemyhinge2);

	//-----good guy 2-----
	PhysBody3D* bodcub8_good_guy2;
	btHingeConstraint *goodguy_hinge2;
	Create_Guy(&bodcub8_good_guy2, &goodguy_hinge2, vec3(86, 0.1, -180), good_guy);
	Stage1_guys_bodys.PushBack(bodcub8_good_guy2);
	Stage1_guys_hinges.PushBack(goodguy_hinge2);


	//---------Stage 2-------

	//-----enemy 3-------
	PhysBody3D* bodcub9_enemy3;
	btHingeConstraint *hinge_enemy3;
	Create_Guy(&bodcub9_enemy3, &hinge_enemy3, vec3(89, 0.1, -160), bad_guy);
	Stage2_guys_bodys.PushBack(bodcub9_enemy3);
	Stage2_guys_hinges.PushBack(hinge_enemy3);
	/*//-----enemy 4-------
	PhysBody3D *bodcub9_enemy2;
	btHingeConstraint *enemyhinge3;
	Create_Guy(&bodcub9_enemy2, &enemyhinge3, vec3(100, 0.1, -200), bad_guy);
	Stage1_guys_bodys.PushBack(bodcub9_enemy2);
	Stage1_guys_hinges.PushBack(enemyhinge3);
	//-----good guy 3-----
	PhysBody3D* bodcub8_good_guy1;
	btHingeConstraint *enemyhinge2;
	Create_Guy(&bodcub8_good_guy1, &enemyhinge2, vec3(75, 0.1, -180), good_guy);
	Stage1_guys_bodys.PushBack(bodcub8_good_guy1);
	Stage1_guys_hinges.PushBack(enemyhinge2);*/


	//SENSOR

	
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
	



	
	
	return ret;
}




// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

void ModuleSceneIntro::Create_Guy(PhysBody3D **body, btHingeConstraint **hinge, vec3 position, guy guy_type)
{
	Cube cub_base;
	PhysBody3D*bodcub_base;
	cub_base.size.x = 4;
	cub_base.size.z = 0.5;
	cub_base.size.y = 0;
	cub_base.color = Black;
	MyCubeMap.PushBack(cub_base);
	bodcub_base = App->physics->AddBody(cub_base, 0);
	bodcub_base->SetPos(position.x, position.y, position.z);
	MyPhysbodyCubeMap.PushBack(bodcub_base);


	Cube cub_enemy_good;
	cub_enemy_good.size.x = 4;
	cub_enemy_good.size.z = 0;
	cub_enemy_good.size.y = 5;
	
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

		if ((PlainGame_Body == body1) && (App->player->CanonBallsBody[i] == body2) && (timepassed >= 3000)) {
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
				Stage1_guys_bodys[x]->active = false;
			}
		}		
	}

	if (MySensorCubeBody[0] == body1 && App->player->turret == body2) {
		FirstStage_Activation();
	}
}


void ModuleSceneIntro::FirstStage_Activation()
{
	//----enemy_1
	for (int x = 0; x < Stage1_guys_bodys.Count(); x++) {
		Stage1_guys_bodys[x]->body->activate(true);
		Stage1_guys_hinges[x]->enableMotor(true);
		Stage1_guys_hinges[x]->setMaxMotorImpulse(10);
		Stage1_guys_hinges[x]->setMotorTargetVelocity(10);
	}

}


