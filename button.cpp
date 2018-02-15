#include "stdafx.h"
#include "button.h"
#include "function.h"
#include "glyph.h"
#include "view.h"
#include <GL/glut.h>
#include "globalvar.h"
#include "passengerGenerator.h"


#include <iostream>
using namespace std;

extern texName a;
extern int texId[];

extern CheckPoint* CheckP[20];
extern PassengerGenerator PassengerG;


//���캯�������찴ť����
Button::Button(texName name, float x, float y, float width, float height) {
    pos.x = x; pos.y = y;
    this->width = width; this->height = height;
    texId = ::texId[name];
    initId = texId;
}
//�ƶ�����¼�
void Button::mouseMove(int x, int y) {
    if(mouseIn(x, y)) {
        texId = initId + 1;
    } else {
        texId = initId;
    }
}
//�������¼�
void Button::mouseClick(int btn, int state, int x, int y) {
    if(mouseIn(x, y) && state == GLUT_DOWN) {
        texId = initId + 2;
        //dosomething
		if (texId == ::texId[button_normal] + 2) {
			//���붯��
			aniWindow = true;
		} else if(texId == ::texId[arrow_left_normal] + 2) {
            //�޸Ĳ���
			if(*corspVar > 1) *corspVar -= 1;
            writeSettingFile();
        } else if(texId == ::texId[arrow_right_normal] + 2) {
            //�޸Ĳ���
			*corspVar += 1;
            writeSettingFile();
        } else if(texId == ::texId[playAndPause_normal] + 2) {
			//�ı䰲���״̬
			switchCheckPointState(CheckP, corspCP);
        } else if(texId == ::texId[gooff_normal] + 2) {
            programEnd(CheckP, &SerpQ);
        } else if(texId == ::texId[plus_normal] + 2) {
            PassengerG.addSingle();
        }
    }
}
