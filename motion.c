#include <raylib.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_OF_OBJ 15
#define GRAVITY 1.5
const int  MIN_RADIUS =20;
const int MAX_RADIUS=40;

typedef struct object{
	Vector2 Position;
	Vector2 Velocity;
	Vector2 Acceleration;
	float mass;
	Color color;
	float radius;
}obj;

void updateObject(obj *object){

	object->Velocity.y += object->Acceleration.y;
	object->Position.y += object->Velocity.y;
	if(object->Position.y +object->radius >= HEIGHT){
		object->Position.y = HEIGHT-object->radius;
		object->Velocity.y *= -0.75f;
	}

	DrawCircleV(object->Position,object->radius,object->color);
}

void initObjects(obj objects[],int size, float gravity){
	srand(time(NULL));
	for(int i =0; i <NUM_OF_OBJ; i++){
		objects[i].Position = (Vector2){GetRandomValue(MAX_RADIUS,WIDTH-MAX_RADIUS),50};
		objects[i].Velocity = (Vector2) {0.0f,0.0f};
		objects[i].mass = 0.5+i*gravity;
		objects[i].Acceleration.y=gravity/objects[i].mass;
		objects[i].radius =(float) GetRandomValue(MIN_RADIUS,MAX_RADIUS);
		objects[i].color = (Color){
			rand() % 256,
			rand() % 256,
			rand() % 256,
			255	
		};
	}
}

int main()
{
	srand(time(NULL));
	obj objects[NUM_OF_OBJ];
	initObjects(objects,NUM_OF_OBJ,GRAVITY);

	InitWindow(WIDTH,HEIGHT,"Motion");
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for(int i = 0; i < NUM_OF_OBJ; i++)
		{
			updateObject(&objects[i]);
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
