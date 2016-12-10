#include "Globals.h"
#include "Application.h"
#include "PhysBody3D.h"
#include "ModuleCamera3D.h"
#include "ModulePlayer.h"
#include "PhysVehicle3D.h"

ModuleCamera3D::ModuleCamera3D(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	CalculateViewMatrix();

	X = vec3(1.0f, 0.0f, 0.0f);
	Y = vec3(0.0f, 1.0f, 0.0f);
	Z = vec3(0.0f, 0.0f, 1.0f);

	Position = vec3(0.0f, 0.0f, 5.0f);
	Reference = vec3(0.0f, 0.0f, 0.0f);
}

ModuleCamera3D::~ModuleCamera3D()
{}

// -----------------------------------------------------------------
bool ModuleCamera3D::Start()
{
	LOG("Setting up the camera");
	bool ret = true;

	return ret;
}

// -----------------------------------------------------------------
bool ModuleCamera3D::CleanUp()
{
	LOG("Cleaning camera");

	return true;
}

// -----------------------------------------------------------------
update_status ModuleCamera3D::Update(float dt)
{
	// Implement a debug camera with keys and mouse
	// Now we can make this movememnt frame rate independant!

	/*vec3 newPos(0,0,0);
	float speed = 3.0f * dt;
	if(App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT)
		speed = 8.0f * dt;

	if(App->input->GetKey(SDL_SCANCODE_R) == KEY_REPEAT) newPos.y += speed;
	if(App->input->GetKey(SDL_SCANCODE_F) == KEY_REPEAT) newPos.y -= speed;

	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) newPos -= Z * speed;
	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) newPos += Z * speed;


	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) newPos -= X * speed;
	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) newPos += X * speed;

	Position += newPos;
	Reference += newPos;
	*/


	btVector3 temp = App->player->vehicle->vehicle->getChassisWorldTransform().getOrigin();

	float* tempC = new float[16];
	App->player->vehicle->vehicle->getChassisWorldTransform().getOpenGLMatrix(tempC);

	mat3x3 C(tempC[0], tempC[1], tempC[2], tempC[4], tempC[5], tempC[6], tempC[8], tempC[9], tempC[10]);

	Position.x = temp.getX();
	Position.y = temp.getY();
	Position.z = temp.getZ();

	Position += C*vec3(0, 3, -10);

	LookAt(vec3(temp.getX(), temp.getY(), temp.getZ()));


	/*
	btQuaternion qtemp = App->player->vehicle->vehicle->getChassisWorldTransform().getRotation();
	
	//Just getting the rotation quaternion to floats for easiest calcu
	float q0 = qtemp.getW();
	float q1 = qtemp.getX();
	float q2 = qtemp.getY();
	float q3 = qtemp.getZ();;

	//Get Rotation Matrix
//	R[0] = (q0*q0 + q1*q1 - q2*q2 - q3*q3);
//	R[1] = (2 * q1*q2 + 2 * q0*q3);
//	R[2] = (2 * q1*q3 - 2 * q0*q2);
//	R[3] = (2 * q1*q2 - 2 * q0*q3);
//	R[4] = (q0*q0 - q1*q1 + q2*q2 - q3*q3);
//	R[5] = (2 * q2*q3 + 2 * q0*q1);
//	R[6] = (2 * q1*q3 + 2 * q0*q2);
//	R[7] = (2 * q2*q3 - 2 * q0*q1);
//	R[8] = (q0*q0 - q1*q1 - q2*q2 + q3*q3);

	R = transpose(R);
	//180º rotation 
	mat3x3 fix(-1,0,0,0,1,0,0,0,-1);

	R = fix*R;
	//Saving in case we need them later
	X = vec3(R[0], R[3], R[6]);
	Y = vec3(R[1], R[4], R[7]);
	Z = vec3(R[2], R[5], R[8]);
	*/



	// Mouse motion ----------------
	/*
	if(App->input->GetMouseButton(SDL_BUTTON_RIGHT) == KEY_REPEAT)
	{
		int dx = -App->input->GetMouseXMotion();
		int dy = -App->input->GetMouseYMotion();

		float Sensitivity = 0.25f;

		Position -= Reference;

		if(dx != 0)
		{
			float DeltaX = (float)dx * Sensitivity;

			X = rotate(X, DeltaX, vec3(0.0f, 1.0f, 0.0f));
			Y = rotate(Y, DeltaX, vec3(0.0f, 1.0f, 0.0f));
			Z = rotate(Z, DeltaX, vec3(0.0f, 1.0f, 0.0f));
		}

		if(dy != 0)
		{
			float DeltaY = (float)dy * Sensitivity;

			Y = rotate(Y, DeltaY, X);
			Z = rotate(Z, DeltaY, X);

			if(Y.y < 0.0f)
			{
				Z = vec3(0.0f, Z.y > 0.0f ? 1.0f : -1.0f, 0.0f);
				Y = cross(Z, X);
			}
		}

		Position = Reference + Z * length(Position);
	}
	*/
	// Recalculate matrix -------------
	CalculateViewMatrix();

	return UPDATE_CONTINUE;
}

// -----------------------------------------------------------------
void ModuleCamera3D::Look(const vec3 &Position, const vec3 &Reference, bool RotateAroundReference)
{
	this->Position = Position;
	this->Reference = Reference;

	Z = normalize(Position - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	if(!RotateAroundReference)
	{
		this->Reference = this->Position;
		this->Position += Z * 0.05f;
	}

	CalculateViewMatrix();
}

// -----------------------------------------------------------------
void ModuleCamera3D::LookAt( const vec3 &Spot)
{
	Reference = Spot;

	Z = normalize(Position - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	CalculateViewMatrix();
}


// -----------------------------------------------------------------
void ModuleCamera3D::Move(const vec3 &Movement)
{
	Position += Movement;
	Reference += Movement;

	CalculateViewMatrix();
}

// -----------------------------------------------------------------
float* ModuleCamera3D::GetViewMatrix()
{
	return &ViewMatrix;
}

// -----------------------------------------------------------------
void ModuleCamera3D::CalculateViewMatrix()
{
	ViewMatrix = mat4x4(X.x, Y.x, Z.x, 0.0f, X.y, Y.y, Z.y, 0.0f, X.z, Y.z, Z.z, 0.0f, -dot(X, Position), -dot(Y, Position), -dot(Z, Position), 1.0f);
	//ViewMatrix = mat4x4(R[0], R[1] , R[2], 0.0f, R[3], R[4], R[5], 0.0f, R[6], R[7], R[8], 0.0f, -dot(vec3(R[0],R[3],R[6]), Position), -dot(vec3(R[1], R[4], R[7]), Position), -dot(vec3(R[2], R[5], R[8]), Position), 1.0f);
	ViewMatrixInverse = inverse(ViewMatrix);
}