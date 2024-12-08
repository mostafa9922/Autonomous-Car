#ifndef _L293D_Interface_H_
#define _L293D_Interface_H_

void MoveToFroward();
void MoveToBack();
void Turn_Right();
void Turn_Left();
void Stop();
void Motors_Init();
void Car_Speed(f32 LeftMotors_speed,f32 RightMotors_speed);

#endif
